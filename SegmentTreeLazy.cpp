#include <bits/stdc++.h>
using namespace std;
map<int,int > lazy,val,seg;

void build(int i,int st,int sp)
{
	int mid=(st+sp)/2;
if(st==sp)
{
seg[i]=val[sp];
return;
}
build(2*i,st,mid);
build(2*i+1,mid+1,sp);
seg[i]=seg[2*i]+seg[2*i+1];
}


void update(int i,int st,int sp,int qst,int qsp,int val)
{
 int mid=(st+sp)/2;

seg[i]=seg[i]^lazy[i];
lazy[2*i]=lazy[i]^lazy[2*i];
lazy[2*i+1]=lazy[i]^lazy[2*i+1];
lazy[i]=0;
if(st>qsp || qst>sp)
	return;


if(qst<=st && qsp>=sp)
{
seg[i]=seg[i]^val;
lazy[2*i]=val^lazy[2*i];
lazy[2*i+1]=val^lazy[2*i+1];
return;
}
update(2*i,st,mid,qst,qsp,val);
update(2*i+1,mid+1,sp,qst,qsp,val);
seg[i]=seg[2*i]+seg[2*i+1];


}

int query(int i,int st,int sp,int qst,int qsp)
{
	int mid=(st+sp)/2;
seg[i]=seg[i]^lazy[i];
lazy[2*i]=lazy[i]^lazy[2*i];
lazy[2*i+1]=lazy[i]^lazy[2*i+1];
lazy[i]=0;
if(st>qsp || qst>sp)
	return 0;

if(qst<=st && qsp>=sp)
return(seg[i]);
int a=query(2*i,st,mid,qst,qsp);
int b=query(2*i+1,mid+1,sp,qst,qsp);
return(a+b);
}

int main()
{

int n;
cin>>n;
for(int e=1;e<=n;e++)
	cin>>val[e];
build(1,1,n);
int q;
cin>>q;
for(int e=1;e<=q;e++)
{
int ch,l,r,v;
cin>>ch;
if(ch==1)
{
cin>>l>>r;
cout<<query(1,1,n,l,r)<<endl;
}
else
{
cin>>l>>r>>v;
update(1,1,n,l,r,v);

}




}



}

