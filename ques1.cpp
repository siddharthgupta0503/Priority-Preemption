#include<stdio.h>
int main()
{
	int size=5,i,pos,j,temp,limit=0;
	int BT[]={10,1,2,1,5},pr[]={3,1,4,5,2},p[]={1,2,3,4,5},CT[size],WT[size];
	for(i=0;i<size;i++)
	{
		printf("\nBurst time of P[%d] : %d",p[i],BT[i]);
		printf("\nPriority of P[%d] : %d\n",p[i],pr[i]);
	}
	printf("\n\n");
	for(i=0;i<size;i++)
	{
		pos=i;
		for(j=i+1;j<size;j++)
		{
			if(pr[pos]>pr[j])
				pos=j;
		}
		//priority
		temp=pr[pos];
		pr[pos]=pr[i];
		pr[i]=temp;
		//process
		temp=p[pos];
		p[pos]=p[i];
		p[i]=temp;
		//Burst time
		temp=BT[pos];
		BT[pos]=BT[i];
		BT[i]=temp;
	}
	for(i=0;i<size;i++)
	{
		limit+=BT[i];
		CT[i]=limit;
		WT[i]=CT[i]-BT[i];
	}
	float awt=0;
	printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<size;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],0,BT[i],CT[i],CT[i],WT[i]);
		awt+=WT[i];
	}
	printf("\n\nAverage Waiting Time : %.2f",(awt/size));
}
