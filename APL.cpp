#include <iostream>

using namespace std;

class Integer
{
    public:
        string num;
        Integer()
        {
            num="";
        }
        Integer(string s)
        {
            num=s;
        }
        Integer operator+(Integer& a)
        {
            int i,c=0,s,l1,l2,min,d1,d2;
            char ch1,ch2;
            l1=num.length();
            l2=a.num.length();
            if((num.at(l1-1)!='-')&&(a.num.at(l2-1)!='-'))
            {
                Integer tem;
                if(l1>l2)
                {
                    min=l2;
                }
                else
                {
                    min=l1;
                }
                for(i=0;i<min;i++)
                {
                    ch1=num.at(i);
                    ch2=a.num.at(i);
                    d1=((int)ch1)-48;
                    d2=((int)ch2)-48;
                    c=c+d1+d2;
                    s=c%10;
                    c=c/10;
                    tem.num=char(s+48)+tem.num;
                }
                if(l1>l2)
                {
                    for(i=min;i<l1;i++)
                    {
                        ch1=num.at(i);
                        d1=((int)ch1)-48;
                        c=c+d1;
                        s=c%10;
                        c=c/10;
                        tem.num=char(s+48)+tem.num;
                    }
                    if(c!=0)
                    {
                        tem.num=char(s+48)+tem.num;
                    }
                }
                else if(l1<l2)
                {
                    for(i=min;i<l2;i++)
                    {
                        ch1=a.num.at(i);
                        d1=ch1-48;
                        c=c+d1;
                        s=c%10;
                        c=c/10;
                        tem.num=char(s+48)+tem.num;
                    }
                    if(c!=0)
                    {
                        tem.num=char(s+48)+tem.num;
                    }
                }
                else
                {
                    if(c!=0)
                    {
                        tem.num=char(c+48)+tem.num;
                    }
                }
                int j,l,f=0;
                string s="";
                l=tem.num.length();
                for(j=0;j<=l-1;j++)
                {
                    if(tem.num.at(j)=='0')
                    {
                       if(f!=0)
                       {
                           s=s+tem.num.at(j);
                       }
                    }
                    else
                    {
                        s=s+tem.num.at(j);
                        f=1;
                    }

                }
                if(s=="")
                {
                    s="0";
                }
                tem.num=s;
                return tem;
            }
            else if((num.at(l1-1)=='-')&&(a.num.at(l2-1)=='-'))
            {
                Integer t1,t2,t3;
                string s1="";
                int i;
                for(i=0;i<l1-1;i++)
                {
                    s1=s1+num.at(i);
                }
                t1.num=s1;
                s1="";
                for(i=0;i<l2-1;i++)
                {
                    s1=s1+a.num.at(i);
                }
                t2.num=s1;
                t3=t1+t2;
                t3.num="-"+t3.num;
                return t3;
            }
            else if((num.at(l1-1)!='-')&&(a.num.at(l2-1)=='-'))
            {
                int j;
                string s="";
                Integer te1,te2,tem;
                te1.num=num;
                for(j=0;j<=l2-2;j++)
                {
                    s=s+a.num.at(j);
                }
                te2.num=s;
                if(te1>te2)
                {
                    tem=te1-te2;
                    return tem;
                }
                else
                {
                    tem=te2-te1;
                    tem.num="-"+tem.num;
                    return tem;
                }
            }
            else
            {
                int j;
                string s="";
                Integer te1,te2,tem;
                te2.num=a.num;
                for(j=0;j<=l1-2;j++)
                {
                    s=s+num.at(j);
                }
                te1.num=s;
                if(te1>te2)
                {
                    tem=te1-te2;
                    tem.num="-"+tem.num;
                    return tem;
                }
                else
                {
                    tem=te2-te1;
                    return tem;
                }
            }
        }
        Integer operator-(Integer& a)
        {
            int l1,l2,i,d1,c=0,s,d2;
            char ch1,ch2;
            Integer tem;
            l1=num.length();
            l2=a.num.length();
            if((num.at(l1-1)!='-')&&(a.num.at(l2-1)!='-'))
            {
                if(*this>a)
                {
                    for(i=0;i<l2;i++)
                    {
                        ch1=num.at(i);
                        ch2=a.num.at(i);
                        d1=((int)ch1)-48;
                        d2=((int)ch2)-48;
                        if((c+d1)>=d2)
                        {
                            s=c+d1-d2;
                            c=0;
                        }
                        else
                        {
                            s=c+10+d1-d2;
                            c=-1;
                        }
                        tem.num=char(s+48)+tem.num;
                    }
                    if(l1>l2)
                    {
                        for(i=l2;i<l1;i++)
                        {
                            ch1=num.at(i);
                            d1=((int)ch1)-48;
                            if((c+d1)>=0)
                            {
                                s=c+d1;
                                c=0;
                            }
                            else
                            {
                                c=-1;
                                s=c+10+d1;
                            }
                            tem.num=char(s+48)+tem.num;
                        }
                    }
                    int j,l,f=0;
                    string s="";
                    l=tem.num.length();
                    for(j=0;j<l;j++)
                    {
                        if(tem.num.at(j)=='0')
                        {
                           if(f!=0)
                           {
                               s=s+tem.num.at(j);
                           }
                        }
                        else
                        {
                            s=s+tem.num.at(j);
                            f=1;
                        }
                        
                    }
                    if(s=="")
                    {
                        s="0";
                    }
                    tem.num=s;
                    return tem;
                }
                else if(*this<a)
                {
                    for(i=0;i<l1;i++)
                    {
                        ch1=num.at(i);
                        ch2=a.num.at(i);
                        d1=((int)ch1)-48;
                        d2=((int)ch2)-48;
                        if((c+d2)>=d1)
                        {
                            s=c+d2-d1;
                            c=0;
                        }
                        else
                        {
                            s=c+10+d2-d1;
                            c=-1;
                        }
                        tem.num=char(s+48)+tem.num;
                    }
                    if(l2>l1)
                    {
                        for(i=l1;i<l2;i++)
                        {
                            ch1=a.num.at(i);
                            d1=((int)ch1)-48;
                            if((c+d1)>=0)
                            {
                                s=c+d1;
                                c=0;
                            }
                            else
                            {
                                c=-1;
                                s=c+10+d1;
                            }
                            tem.num=char(s+48)+tem.num;
                        }
                    }
                    int j,l,f=0;
                    string s="";
                    l=tem.num.length();
                    for(j=0;j<=l-1;j++)
                    {
                        if(tem.num.at(j)=='0')
                        {
                           if(f!=0)
                           {
                               s=s+tem.num.at(j);
                           }
                        }
                        else
                        {
                            s=s+tem.num.at(j);
                            f=1;
                        }
                        
                    }
                    if(s=="")
                    {
                        s="0";
                    }
                    tem.num=s;
                    tem.num="-"+tem.num;
                    return tem;
                }
                else
                {
                    Integer temp;
                    temp.num="0";
                    return temp;
                }
            }
            else if((num.at(l1-1)=='-')&&(a.num.at(l2-1)=='-'))
            {
                int i;
                string s="";
                Integer te1,te2,tem;
                for(i=0;i<l2-1;i++)
                {
                    s=s+a.num.at(i);
                }
                te1.num=s;
                s="";
                for(i=0;i<l1;i++)
                {
                    s=s+num.at(i);
                }
                te2.num=s;
                tem=te1+te2;
                int j,l,f=0;
                s="";
                l=tem.num.length();
                for(j=0;j<=l-1;j++)
                {
                    if(tem.num.at(j)=='0')
                    {
                       if(f!=0)
                       {
                           s=s+tem.num.at(j);
                       }
                    }
                    else
                    {
                        s=s+tem.num.at(j);
                        f=1;
                    }

                }
                if(s=="")
                {
                    s="0";
                }
                tem.num=s;
                return tem;
            }
            else if((num.at(l1-1)!='-')&&(a.num.at(l2-1)=='-'))
            {
                int i;
                string s="";
                Integer te1,te2,tem;
                for(i=0;i<l1;i++)
                {
                    s=s+num.at(i);
                }
                te1.num=s;
                s="";
                for(i=0;i<l2-1;i++)
                {
                    s=s+a.num.at(i);
                }
                te2.num=s;
                tem=te1+te2;
                int j,l,f=0;
                    s="";
                    l=tem.num.length();
                    for(j=0;j<l-1;j++)
                    {
                        if(tem.num.at(j)=='0')
                        {
                           if(f!=0)
                           {
                               s=s+tem.num.at(j);
                           }
                        }
                        else
                        {
                            s=s+tem.num.at(j);
                            f=1;
                        }
                        
                    }
                return tem;
            }
            else
            {
                int i;
                string s="";
                Integer te1,te2,tem;
                for(i=0;i<l1-1;i++)
                {
                    s=s+num.at(i);
                }
                te1.num=s;
                s="";
                for(i=0;i<l2;i++)
                {
                    s=s+a.num.at(i);
                }
                te2.num=s;
                tem=te1+te2;
                int j,l,f=0;
                s="";
                l=tem.num.length();
                for(j=0;j<=l-1;j++)
                {
                    if(tem.num.at(j)=='0')
                    {
                       if(f!=0)
                       {
                           s=s+tem.num.at(j);
                       }
                    }
                    else
                    {
                        s=s+tem.num.at(j);
                        f=1;
                    }

                }
                if(s=="")
                {
                    s="0";
                }
                tem.num=s;
                tem.num="-"+tem.num;
                return tem;
            }
        }
        Integer operator*(Integer& a)
        {
            int l1,l2,j,c,si1,i,si2,s,d1,d2,sg1=-1,sg2=-1;
            Integer res,re;
            l1=num.length();
            l2=a.num.length();
            char ch1,ch2;
            if(num.at(l1-1)=='-')
            {
                si1=l1-2;
                sg1=-1;
            }
            else
            {
                si1=l1-1;
                sg1=1;
            }
            if(a.num.at(l2-1)=='-')
            {
                si2=l2-2;
                sg2=-1;
            }
            else
            {
                si2=l2-1;
                sg2=1;
            }
            for(i=0;i<=si1;i++)
            {
                ch1=num.at(i);
                d1=((int)ch1)-48;
                c=0;
                re.num="";
                for(j=0;j<=si2;j++)
                {
                    ch2=a.num.at(j);
                    d2=((int)ch2)-48;;
                    c=c+(d1*d2);
                    s=c%10;
                    c=c/10;
                    re.num=re.num+char(s+48);
                }
                if(c!=0)
                {
                    re.num=re.num+char(c+48);
                }
                for(j=0;j<i;j++)
                {
                    re.num="0"+re.num;
                }
                if(i==0)
                {
                    res=re;
                }
                else
                {
                    res+=re;
                    int i,l;
                    string rev="";
                    l=res.num.length();
                    for(i=0;i<l;i++)
                    {
                        rev=res.num.at(i)+rev;
                    }
                    res.num=rev;
                }
            }
            int l;
            string rev="";
            l=res.num.length();
            for(i=0;i<l;i++)
            {
                rev=res.num.at(i)+rev;
            }
                res.num=rev;
            if(sg1==1&&sg2==-1)
            {
                res.num="-"+res.num;
            }
            if(sg1==-1&&sg2==1)
            {
                res.num="-"+res.num;
            }
            return res;
        }
        Integer operator/(Integer& a)
        {
            int l1,l2,j,c,si1,i,l,flag=0,si2,sg1=-1,sg2=-1;
            Integer res,re;
            l1=num.length();
            l2=a.num.length();
            if(num.at(l1-1)=='-')
            {
                si1=l1-2;
                sg1=-1;
            }
            else
            {
                si1=l1-1;
                sg1=1;
            }
            if(a.num.at(l2-1)=='-')
            {
                si2=l2-2;
                sg2=-1;
            }
            else
            {
                si2=l2-1;
                sg2=1;
            }
            Integer te,tem,A;
            for(i=0;i<=si2;i++)
            {
                A.num=A.num+a.num.at(i);
            }
            string rev;
            l1=num.length(); 
            for(i=si1;i>=0;i--)
            {
                c=0;
                te.num=num.at(i)+te.num;
                if(te>=A)
                {
                    while(te>=A)
                    {
                        te=te-A;
                        l=te.num.length();
                        rev="";
                        for(j=0;j<l;j++)
                        {
                            rev=te.num.at(j)+rev;
                        }
                        c++;
                        te.num=rev;
                    }
                    if(te.num=="0")
                    {
                        te.num="";
                    }
                    flag=1;
                    tem.num=tem.num+char(c+48);
                }
                else
                {
                    if(flag==1)
                    {
                        tem.num=tem.num+"0";
                    }
                }
            }
            if(sg1==1&&sg2==-1)
            {
                tem.num="-"+tem.num;
            }
            if(sg1==-1&&sg2==1)
            {
                tem.num="-"+tem.num;
            }
            if(flag==0)
            {
                tem.num="0";
            }
            return tem;
        }
        Integer operator%(Integer& a)
        {
            Integer t1,t2,t3;
            int i,l;
            t1=*this/a;
            string s="";
            l=t1.num.length();
            for(i=0;i<l;i++)
            {
                s=t1.num.at(i)+s;
            }
            t1.num=s;
            
            t2=t1*a;
            s="";
            l=t2.num.length();
            for(i=0;i<l;i++)
            {
                s=t2.num.at(i)+s;
            }
            t2.num=s;
            t3=*this-t2;
            return t3;
        }
        Integer operator+=(Integer& a)
        {
            int l1,i;
            Integer te,t1;
            string s="";
            l1=num.length();
            for(i=0;i<l1;i++)
            {
                s=s+num.at(i);
            }
            te.num=s;
            t1=te+a;
            num=t1.num;
            return *this;
        }
        Integer operator-=(Integer& a)
        {
            int l1,i;
            Integer te,t1;
            string s="";
            l1=num.length();
            for(i=0;i<l1;i++)
            {
                s=s+num.at(i);
            }
            te.num=s;
            t1=te-a;
            num=t1.num;
            return *this;
        }
        Integer operator*=(Integer& a)
        {
            int l1,i;
            Integer te,t1;
            string s="";
            l1=num.length();
            for(i=0;i<l1;i++)
            {
                s=s+num.at(i);
            }
            te.num=s;
            t1=te*a;
            num=t1.num;
            return *this;
        }
        Integer operator/=(Integer a)
        {
            *this=*this/a;
            return *this;
        }
        Integer operator%=(Integer a)
        {
            *this=*this%a;
            return *this;
        }
        bool operator==(Integer& a)
        {
            int l1,l2,i;
            char ch1,ch2;
            l1=num.length();
            l2=a.num.length();
            if(l1==l2)
            {
                for(i=0;i<l1;i++)
                {
                    ch1=num.at(i);
                    ch2=a.num.at(i);
                    if(ch1!=ch2)
                    {
                        break;
                    }
                }
                if(i==l1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        bool operator!=(Integer& a)
        {
            int l1,i;
            Integer te;
            string s="";
            l1=num.length();
            for(i=0;i<l1;i++)
            {
                s=s+num.at(i);
            }
            te.num=s;
            if(te==a)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool operator<(Integer& a)
        {
            int l1,i;
            Integer te;
            string s="";
            l1=num.length();
            for(i=0;i<l1;i++)
            {
                s=s+num.at(i);
            }
            te.num=s;
            if(te>=a)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool operator<=(Integer& a)
        {
            int l1,i;
            Integer te;
            string s="";
            l1=num.length();
            for(i=0;i<l1;i++)
            {
                s=s+num.at(i);
            }
            te.num=s;
            if(te>a)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool operator>(Integer& a)
        {
            int l1,l2,si1,i,si2,d1,d2,sg1=-1,sg2=-1,mag=-1;
            int j,l,f=0,c;
            string s="";
            l=num.length();
            if(num.at(l-1)=='-')
            {
                c=2;
            }
            else
            {
                c=1;
            }
            //cout<<num<<"  "<<a.num<<"\n";
            for(j=l-c;j>=0;j--)
            {
                if(num.at(j)=='0')
                {
                   if(f!=0)
                   {
                       s=num.at(j)+s;
                   }
                }
                else
                {
                    s=num.at(j)+s;
                    f=1;
                }

            }
            if(s=="")
            {
                s="0";
            }
            num=s;
            if(c==2)
            {
                num=num+"-";
            }
            s="";
            f=0;
            l=a.num.length();
            if(a.num.at(l-1)=='-')
            {
                c=2;
            }
            else
            {
                c=1;
            }
            for(j=l-c;j>=0;j--)
            {
                if(a.num.at(j)=='0')
                {
                   if(f!=0)
                   {
                       s=a.num.at(j)+s;
                   }
                }
                else
                {
                    s=a.num.at(j)+s;
                    f=1;
                }

            }
            if(s=="")
            {
                s="0";
            }
            a.num=s;
            if(c==2)
            {
                a.num=a.num+"-";
            }
            l1=num.length();
            l2=a.num.length();
            char ch1,ch2;
            if(num.at(l1-1)=='-')
            {
                si1=l1-2;
                sg1=-1;
            }
            else
            {
                si1=l1-1;
                sg1=1;
            }
            if(a.num.at(l2-1)=='-')
            {
                si2=l2-2;
                sg2=-1;
            }
            else
            {
                si2=l2-1;
                sg2=1;
            }
            //cout<<num<<"  "<<a.num<<"\n";
            //cout<<si1<<"  "<<si2<<"\n";
            if(si1>si2)
            {
                mag=1;
            }
            else if(si2>si1)
            {
                mag=2;
            }
            else
            {
                for(i=si1;i>=0;i--)
                {
                    ch1=num.at(i);
                    ch2=a.num.at(i);
                    d1=((int)ch1)-48;
                    d2=((int)ch2)-48;
                    if(d1>d2)
                    {
                        mag=1;
                        break;
                    }
                    else if(d2>d1)
                    {
                        mag=2;
                        break;
                    }
                }
            }
            if(mag==1)
            {
                if(sg1==-1&&sg2==-1)
                {
                    return false;
                }
                else if(sg1==-1&&sg2==1)
                {
                    return false;
                }
                else if(sg1==1&&sg2==-1)
                {
                    return true;
                }
                else 
                {
                    return true;
                }
            }
            else
            {
                if(sg1==-1&&sg2==-1)
                {
                    return true;
                }
                else if(sg1==-1&&sg2==1)
                {
                    return false;
                }
                else if(sg1==1&&sg2==-1)
                {
                    return true;
                }
                else 
                {
                    return false;
                }
            }
        }
        bool operator>=(Integer& a)
        {
            int l1,i;
            Integer te;
            string s="";
            l1=num.length();
            for(i=0;i<l1;i++)
            {
                s=s+num.at(i);
            }
            te.num=s;
            if(te>a)
            {
                return true;
            }
            else if(te==a)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        friend ostream& operator<<(ostream& out, Integer& i)
        {
            return(out<<i.num);
        }
        friend istream& operator>>(istream& in, Integer& i)
        {
            return(in>>i.num);
        }
    
        
};
int main() 
{
    int flag=0;
    while(flag==0)
    {
        string ch;
        cin>>ch;
        if(ch!="end")
        {
            string s1,rev="",s="";
            int l,i,f,c;
            Integer t1,t2,t3;
            cin>>s1;
            l=s1.length();
            f=0;
            c=0;
            if(s1.at(0)=='-')
            {
                c=1;
            }
            for(i=c;i<l;i++)
            {
                if(s1.at(i)=='0')
                {
                    if(f!=0)
                    {
                        s=s+s1.at(i);
                    }
                }
                else
                {
                    s=s+s1.at(i);
                    f=1;
                }
            }
            if(s=="")
            {
                s="0";
            }
            if(c==1)
            {
                s="-"+s;
            }
            s1=s;
            s="";
            l=s1.length();
            for(i=0;i<l;i++)
            {
                rev=s1.at(i)+rev;
            }
            t1.num=rev;
            cin>>s1;
            rev="";
            l=s1.length();
            f=0;
            c=0;
            if(s1.at(0)=='-')
            {
                c=1;
            }
            for(i=c;i<l;i++)
            {
                if(s1.at(i)=='0')
                {
                    if(f!=0)
                    {
                        s=s+s1.at(i);
                    }
                }
                else
                {
                    s=s+s1.at(i);
                    f=1;
                }
            }
            if(s=="")
            {
                s="0";
            }
            if(c==1)
            {
                s="-"+s;
            }
            s1=s;
            l=s1.length();
            for(i=0;i<l;i++)
            {
                rev=s1.at(i)+rev;
            }
            t2.num=rev;
            //cout<<t2.num<<"  "<<t1.num;
            if(ch=="+")
            {
                    t3=t1+t2;
                    cout<<t3<<"\n";
            }
            else if(ch=="-")
            {
                    t3=t1-t2;
                    cout<<t3<<"\n";
            }
            else if(ch=="*")
            {
                    t3=t1*t2;
                    cout<<t3<<"\n";
            }
            else if(ch=="/")
            {
                    t3=t1/t2;
                    cout<<t3<<"\n";
            }
            else if(ch=="%")
            {
                    t3=t1%t2;
                    cout<<t3<<"\n";
            }
            else if(ch=="+=")
            {
                    t1+=t2;
                    cout<<t1<<"\n";
            }
            else if(ch=="-=")
            {
                    t1-=t2;
                    cout<<t1<<"\n";
            }
            else if(ch=="*=")
            {
                    t1*=t2;
                    cout<<t1<<"\n";
            }
            else if(ch=="/=")
            {
                    t1/=t2;
                    cout<<t1<<"\n";
            }
            else if(ch=="%=")
            {
                    t1%=t2;
                    cout<<t1<<"\n";
            }
            else if(ch=="<")
            {
                if(t1<t2)
                {
                    cout<<"true"<<"\n";
                }
                else
                {
                    cout<<"false"<<"\n";
                }
            }
            else if(ch=="<=")
            {
                if(t1<=t2)
                {
                    cout<<"true"<<"\n";
                }
                else
                {
                    cout<<"false"<<"\n";
                }
            }
            else if(ch==">")
            {
                if(t1>t2)
                {
                    cout<<"true"<<"\n";
                }
                else
                {
                    cout<<"false"<<"\n";
                }
            }
            else if(ch==">=")
            {
                if(t1>=t2)
                {
                    cout<<"true"<<"\n";
                }
                else
                {
                    cout<<"false"<<"\n";
                }
            }
            else if(ch=="==")
            {
                if(t1==t2)
                {
                    cout<<"true"<<"\n";
                }
                else
                {
                    cout<<"false"<<"\n";
                }
            }
            else 
            {
                if(t1!=t2)
                {
                    cout<<"true"<<"\n";
                }
                else
                {
                    cout<<"false"<<"\n";
                }
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}