import java.util.*;
class DSA {
    public static void main(String[] args) {
        int p=11,q=5,h=2;
        int HM,g,x,y,k,r,s,w,u1,u2,v;
	Random rand= new Random();
	h=rand.nextInt(p-1-1+1);
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Hash Message : ");
        HM=sc.nextInt();
        int t=(p-1)/q;
        g=((int)Math.pow(h,t))%p;
        //step2
        x=rand.nextInt(q-0+1);
        //step3
        y=((int)Math.pow(g,x))%p;
        //step4
        k=rand.nextInt(q-0+1);
        //step5
        r=(((int)Math.pow(g,k))%p)%q;
        if(k==0) s=0;
	else
	s=((1/k)*(HM+x*r))%q;
        //step6
	if(s==0) w=0;
	else 
        w=(1/s)%q;
        u1=(HM*w)%q;
        u2=(r*w)%q;
        v=((((int)Math.pow(g,u1))*((int)Math.pow(g,u2)))%p)%q;
        if(v==r) System.out.println("The Signature is verified");
        else System.out.println("The signature is not verified");
    }
}

