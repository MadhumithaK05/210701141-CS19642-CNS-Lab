import java.util.*;
class Caesar{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        int k=sc.nextInt();
        StringBuilder res=new StringBuilder();
        for(char i:s.toCharArray())
        {
            char c='a';
            if(Character.isLowerCase(i))
            c=(char)(((i-'a'+k)%26)+'a');
            if(Character.isUpperCase(i))
            c=(char)(((i-'A'+k)%26)+'A');
            if(Character.isDigit(i))
            c=(char)(((i-'0'+k)%10)+'0');
            res.append(c);
        }
        s=res.toString();
        StringBuilder d=new StringBuilder();
        for(char i:s.toCharArray())
        {
            char c='a';
            if(Character.isLowerCase(i))
            c=(char)(((i-'a'-k)%26)+'a');
            if(Character.isUpperCase(i))
            c=(char)(((i-'A'-k)%26)+'A');
            if(Character.isDigit(i))
            c=(char)(((i-'0'-k)%10)+'0');
            d.append(c);
        }
        System.out.println(res);
        System.out.println(d);
    }
}
