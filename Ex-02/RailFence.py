s=input("Enter string: ")
k=int(input("Enter key: "))
enc=[[" " for i in range(len(s))] for j in range(k)]
flag=0
row=0
for i in range(len(s)):
  enc[row][i]=s[i]
  if row==0:
    flag=0
  elif row==k-1:
    flag=1
  if flag==0:
    row+=1
  else:
    row-=1
ct=[]
for i in range(k):
    for j in range(len(s)):
        if enc[i][j]!=' ':
            ct.append(enc[i][j])
cipher="".join(ct)
print("Cipher Text: ",cipher)


def decryptMsg(char msg[], int key){
    int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0, m = 0; 
    char railMatrix[key][msgLen];
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n'; 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = '*'; 
        if(row == 0 || row == key-1)
            k= k * (-1); row = row + k;
    }
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j) 
            if(railMatrix[i][j] == '*')
                railMatrix[i][j] = msg[m++];
    row = col = 0;
    k = -1;
    printf("\nDecrypted Message: "); 
    for(i = 0; i < msgLen; ++i){
        printf("%c", railMatrix[row][col++]);
        if(row == 0 || row == key-1) 
            k= k * (-1);
        row = row + k;} 
}

