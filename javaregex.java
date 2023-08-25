import java.util.regex.*; 
public class Main
{
	public static void main(String[] args) {
		String blacklisted_ips[]=new String[10];
		String requests[]=new String[10];
		blacklisted_ips[0]="*111.*";
		blacklisted_ips[1]="123.*";
		blacklisted_ips[2]="34.*";
		int n=3;
		    System.out.println(n);
		for(int i=0;i<n;i++){
		   blacklisted_ips[i]= blacklisted_ips[i].replace(".","\\\\.");
		    blacklisted_ips[i]= blacklisted_ips[i].replace("*",".*");
		   
		}
		String s1="34.*";
		s1=s1.replace(".","\\\\.");
		if(s1=="34\\.*")
		System.out.println(s1);
		for(int i=0;i<n;i++){
		    if(blacklisted_ips[i]=="34\\..*")
		    System.out.println(blacklisted_ips[i]);
		}
		int n1=7;
		int x;
		String s="34\\..*";
		requests[0]="123.1";
		requests[1]="121.1.23.34";
		requests[2]="121.1.23.34";
		requests[3]="34.1.23.34";
		requests[4]="121.1.23.34";
		requests[5]="12.1.23.34";
		requests[6]="121.1.23.34";
// 		for(int i=0;i<2;i++){
// 		    x=0;
// 		    for(int j=0;j<n;j++){
// 		      //  s=blacklisted_ips[j];
// 		      //  if(blacklisted_ips[j]==s){
// 		      //      System.out.println(s);
// 		      //  }
// 		      System.out.println(blacklisted_ips[j]);
// 		    if(Pattern.matches(s,requests[i])==true){
// 		        x=1;
// 		      //  System.out.println("yes");
// 		        break;
// 		    }
// 		    }
// 		    System.out.println(x);
// 		}
	}
}