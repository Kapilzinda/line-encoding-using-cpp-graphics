#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

string randominput(int n)
{   vector<int> vec(n,0);
    string input;
    for(int i=1;i<=n;i++)
    {
        vec[i]=rand()%2;
        input.push_back(vec[i]+'0');
    }
    return input;
}
string randomseq8(int n)
{   vector<int> vec(n,0);
    string input;
    for(int i=1;i<=n;i++)
    {
        vec[i]=rand()%2;
        input.push_back(vec[i]+'0');
        
        if(i == 10){
        	for(;i <= 18;i++){
        		input.push_back('0');
			}
		}
    }
    return input;
}
string randomseq4(int n)
{   vector<int> vec(n,0);
    string input;
    for(int i=1;i<=n;i++)
    {
        vec[i]=rand()%2;
        input.push_back(vec[i]+'0');
        
        if(i == 8 || i == 18){
        	for(int j = 0;j < 4;j++){
        		input.push_back('0');
        		i++;
			}
		}
    }
    return input;
}
string lcs(string &x,string &y)
{
    int m=x.size();
    int n=y.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int index=dp[m][n];
    string temp(index+1,'\0');
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            temp[index-1]=x[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    return temp;
}
string lps(string &str)
{
    string rev=str;
    reverse(rev.begin(),rev.end());
    return lcs(str,rev);
}
void NRZL(string s)
{
    int n=s.size();
	int c1 = 0, c2 = 5;
    int x=50;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            line(x,100,x+50,100);
            outtextxy(x+23,115,"0");
            if(i > 0 && s[i-1]=='1')
                line(x,50,x,100);
        }
        else if(s[i]=='1')
        {
            line(x,50,x+50,50);
            outtextxy(x+23,115,"1");
            if(i > 0 && s[i-1]=='0')
                line(x,50,x,100);
        }
        x=x+50;
    }
    outtextxy(0,75,"NRZL");
    outtextxy(0,115,"input");

}
void NRZI(string s)
{
    int n=s.size();
    int x=50,flag=0;
    if(s[0]=='0')
    {
        line(x,100,x+50,100);
        outtextxy(x+23,115,"0");
        flag=0;
    }
    else
    {
        line(x,50,x+50,50);
        outtextxy(x+23,115,"1");
        flag=1;
    }
    x=x+50;
    for(int i=1;i<n;i++)
    {  if(s[i]=='0')
        {outtextxy(x+23,115,"0");
        if(flag==0)
        {
            line(x,100,x+50,100);
            flag=0;
        }
        else if(flag==1)
        {
            line(x,50,x+50,50);
            flag=1;
        }
        x=x+50;
       }
       else if(s[i]=='1')
       {outtextxy(x+23,115,"1");
       if(flag==1)
        {
            line(x,100,x+50,100);
            flag=0;
        }
        else if(flag==0)
        {
            line(x,50,x+50,50);
            flag=1;
        }
        line(x,50,x,100);
        x=x+50;
        

       }}
    outtextxy(0,75,"NRZL");
    outtextxy(0,115,"input");
}
void MANCHESTER(string s)
{
    int n=s.size();
    int x=50;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {   line(x,200,x+25,200);
        	line(x+25,100,x+25,200);
        	line(x+25,100,x+50,100);
        	if(i > 0 && s[i-1] == '0'){
        		setlinestyle(1,0,1);
        		line(x,100,x,200);
        		setlinestyle(0,0,1);
			}
        		

            outtextxy(x+23,215,"0");
            
        }
        else if(s[i]=='1')
        {
        	line(x,100,x+25,100);
        	line(x+25,100,x+25,200);
        	line(x+25,200,x+50,200);
        	if(i > 0 && s[i-1] == '1'){
        		setlinestyle(1,0,1);
        		line(x,100,x,200);
        		setlinestyle(0,0,1);
			}

            outtextxy(x+23,215,"1");

        }
        x=x+50;
    }
    outtextxy(0,125,"MANCHESTER");
    outtextxy(0,215,"input");

}
void DIFMANCHESTER(string s)
{
    int n=s.size();

    int x=50,flag=0;
    if(s[0]=='0')
        {   line(x,200,x+25,200);
        	line(x+25,100,x+25,200);
        	line(x+25,100,x+50,100);
            outtextxy(x+23,215,"0");
            flag=0;
        }
        else if(s[0]=='1')
        {
            line(x,100,x+25,100);
        	line(x+25,100,x+25,200);
        	line(x+25,200,x+50,200);
            outtextxy(x+23,215,"1");
            flag=1;
        }
        x=x+50;
    for(int i=1;i<n;i++)
    {  if(s[i]=='0'){
			if(flag==0)
	        {   line(x,200,x+25,200);
	        	line(x+25,100,x+25,200);
	        	line(x+25,100,x+50,100);
	            outtextxy(x+23,215,"0");
	        }
	        else if(flag==1)
	        {
	            line(x,100,x+25,100);
	        	line(x+25,100,x+25,200);
	        	line(x+25,200,x+50,200);
	            outtextxy(x+23,215,"0");
	        }
        		setlinestyle(1,0,1);
        		line(x,100,x,200);
        		setlinestyle(0,0,1);
			
	        x=x+50;
	    }
	    else if(s[i]=='1')
	    {
	        if(flag==1)
	        {   
				flag=0;
				line(x,200,x+25,200);
        		line(x+25,100,x+25,200);
        		line(x+25,100,x+50,100);
	            outtextxy(x+23,215,"1");
	        }
	        else if(flag==0)
	        {
	        	flag=1;
	            line(x,100,x+25,100);
        		line(x+25,100,x+25,200);
        		line(x+25,200,x+50,200);
	            outtextxy(x+23,215,"1");
	        }
	        x=x+50;
    	}
	}
    outtextxy(0,125,"DIFMANCHESTER");
    outtextxy(0,215,"input");
}
void AMI(string s)
{
    int n=s.size();
    int x=50,flag=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {	
			line(x,100,x+50,100);
        	outtextxy(x+23,165,"0");
        }
        else if(s[i]=='1')
        {
            if(flag==0)
            {
             line(x,50,x+50,50);
             line(x+50,50,x+50,100);
             line(x,50,x,100);
             outtextxy(x+23,165,"1");
             flag=1;
            }
            else
            {
			line(x,150,x+50,150);
            line(x+50,150,x+50,100);
            line(x,150,x,100);
            outtextxy(x+23,165,"1");
            flag=0;
            }
        }
        x=x+50;
    }
}
void B8ZS(string s,int &flag1,int &x)
{
    int flag;
    int n=s.size();
    for(int i=0;i<n;i++)
    {   if(i==3||i==7)
         {
             if(flag1==0)
                flag=1;
             else
                flag=0;
         }
         if(i==4||i==6)
         {  flag=flag1;
         }
        if(s[i]=='0'&& i!=4 && i!=3 && i!=6 && i!=7)
        {line(x,100,x+50,100);
        outtextxy(x+23,165,"0");
        }
        else
        {
            if(flag==0)
            {
             line(x,50,x+50,50);
             line(x+50,50,x+50,100);
             line(x,50,x,100);
             outtextxy(x+23,165,"0");
             flag=1;
            }
            else
            {line(x,150,x+50,150);
            line(x+50,150,x+50,100);
            line(x,150,x,100);
            outtextxy(x+23,165,"0");
            flag=0;
            }
        }
        x=x+50;
    }
    flag1=flag;
        }
void AMIB8ZS(string s)
{
    int n=s.size();
    if(n==8)
    {  int x=50,flag=0;
        if(s=="00000000")
        {
          B8ZS(s,flag,x);
        }
        else
            AMI(s);
    }
    else if(n<8)
        AMI(s);
    else
    {
        int x=50,flag=0;
    for(int i=0;i<n;i++)
    { if(s[i]=='0' && i < n-8)
        {
            string substring=s.substr(i,8);
            if(substring=="00000000")
            {B8ZS(substring,flag,x);
             i=i+7;
             continue;}


        }
        if(s[i]=='0')
        {line(x,100,x+50,100);
        outtextxy(x+23,165,"0");
        }
        else if(s[i]=='1')
        {
            if(flag==0)
            {
             line(x,50,x+50,50);
             line(x+50,50,x+50,100);
             line(x,50,x,100);
             outtextxy(x+23,165,"1");
             flag=1;
            }
            else
            {line(x,150,x+50,150);
            line(x+50,150,x+50,100);
            line(x,150,x,100);
            outtextxy(x+23,165,"1");
            flag=0;
            }
        }
        x=x+50;
    }
    }
}
void HDB3(string s,int &flag1,int &x,int sum)
{
    int flag,n;
    n=s.size();
    for(int i=0;i<n;i++)
    {   if(sum%2==0)
        {if(i==0||i==3)
             flag=flag1;
			 }
         else
         {if(i==3)
           {if(flag1==0)
             flag=1;
             else
                flag=0;
         }}
        if(s[i]=='0'&& i!=3 && i!=0 ||(i==0 && (sum%2!=0 )))
        {line(x,100,x+50,100);
        outtextxy(x+23,165,"0");
        }
        else
        {
            if(flag==0)
            {
             line(x,50,x+50,50);
             line(x+50,50,x+50,100);
             line(x,50,x,100);
             outtextxy(x+23,165,"0");
             flag=1;
            }
            else
            {line(x,150,x+50,150);
            line(x+50,150,x+50,100);
            line(x,150,x,100);
            outtextxy(x+23,165,"0");
            flag=0;
            }
        }
        x=x+50;
    }
    flag1=flag;

}
void AMIHDB3(string s)
{
    int n=s.size();
        int x=50,flag=0,sum=0;
    for(int i=0;i<n;i++)
    {    if(s[i]=='0' && i < n - 4)
        {
            string sub=s.substr(i,4);
            if(sub=="0000")
                {HDB3(sub,flag,x,sum);
                 i=i+3;
                 continue;
                }
        }
        if(s[i]=='0')
        {line(x,100,x+50,100);
        outtextxy(x+23,165,"0");
        }
        else if(s[i]=='1')
        {   sum++;
            if(flag==0)
            {
             line(x,50,x+50,50);
             line(x+50,50,x+50,100);
             line(x,50,x,100);
             outtextxy(x+23,165,"1");
             flag=1;
            }
            else
            {line(x,150,x+50,150);
            line(x+50,150,x+50,100);
            line(x,150,x,100);
            outtextxy(x+23,165,"1"); 
            flag=0;
            }
        }
        x=x+50;
    }
}
int main()
{
    int gd=DETECT,gm,y,scramb;
    char ch;
    initgraph(&gd,&gm,"");
    setcolor(5);
    string s,s1;
    int t;
    
    cout << "enter your choice for data generation --- \n1) total random data\n2) data with sequences" << endl;
    cin >> t;
    
    if(t == 1)
    	s=randominput(20);
    else{
    	cout << "1) sequence of 8 zero \n2)sequence of 4 zero" << endl;
    	int tt;
    	cin >> tt;
    	if(tt == 1)
    	    s=randomseq8(25);
    	else
    	    s=randomseq4(25);
	}

    	
    cout << "generated string is -- " << s << endl;
    s1=lps(s);
    
    cout << "longest palindrom in string is -- " << s1 <<endl;
    
    

    cout<<"Enter Line encoding scheme-\n1)NRZ-L\n2)NRZ-I\n3)MANCHESTER\n4)DIFFERENTIAL MANCHESTER\n5)AMI" << endl;
    cin>>y;
    if(y==1)
    {
        NRZL(s);
    }
    else if(y==2)
    {
        NRZI(s);
    }
    else if(y==3)
    {
        MANCHESTER(s);
    }
    else if(y==4)
    {
        DIFMANCHESTER(s);
    }
    else if(y==5)
    {
        cout<<"Require Scrambling (Y/N)?" << endl;
        cin>>ch;
        if(ch=='Y' || ch == 'y')
        {
            cout<<"Type of scrambling:\n1)B8ZS\n2)HDB3" << endl;
            cin>>scramb;
            if(scramb==1){
            	    outtextxy(0,100,"AMI B8ZS");
    				outtextxy(0,165,"input");
    				AMIB8ZS(s);
			}
            else
            {
            	outtextxy(0,100,"AMI HDB3");
    			outtextxy(0,165,"input");
                AMIHDB3(s);
            }
               
        }
        else
        {
        	outtextxy(0,100,"AMI");
    		outtextxy(0,165,"input");
            AMI(s);
        }
    }

    getch();
    closegraph();
}
