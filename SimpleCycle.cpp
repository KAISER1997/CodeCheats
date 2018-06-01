//COUNTS THE NUMBER OF SIMPLE CYCLES IN AN UNDIRECTED GRAPH//
(EX-cf11D)

//TIME COMPLEXITY O(2^N  * N *N)
typedef long long int intz;
intz tf;
intz mp[32][32]={0};// 0 If edge doesnt exist between vertices else 1
intz ctBits(intz n) //number of nonzero bits
{
intz s=0;
while(n!=0)
{
s+=n%2;
++tf;
n=n/2;
}
return(s);
}

intz first(intz n) //first non zero bit
{
	ctBits(n);
for(intz q=0;q<=tf;q++)
{
if(n&(1<<q))
	return(q+1);
}
}




intz dp[724288][40]={0};
intz countingSimpleCycles(intz n) // COUNTS THE CYCLES
{
intz e=0;
 
intz t=1;
for(intz e=1;e<pow(2,n);e++)
{
	intz mask=e;
if(ctBits(e)==1)
	{
      dp[mask][first(e)]=1;
      continue;
	}

else
{
 
 
for(intz ef=0;ef<n;ef++)
{

if((mask&(1<<ef)))
{
if(first(mask)==ef+1)
{
continue;
}
for(intz q=0;q<n;q++)
{
	if(mp[ef+1][q+1]==1)
dp[mask][ef+1]+=dp[mask^(1<<ef)][q+1];
}
}
}
}
}
 intz sum=0;
intz u=0;
for(intz e=1;e<pow(2,n);e++)
{
	 
if(ctBits(e)>=3)
{
	intz mask2=e;
for(intz w=0;w<n;w++)
{

if(e&(1<<w))
{
sum+=dp[e][w+1]*mp[w+1][first(e)];

}

}


}

}
return sum;

}


