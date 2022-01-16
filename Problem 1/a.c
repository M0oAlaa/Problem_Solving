#include<stdio.h>
#define MaxArrSize	100
/*Declaration of the function that get the maximun values of subarrays and return their anding result*/
int ANDING(int *arr,int N,int K); 

void main(void)
{
	/*Some local signed integers*/
	signed int i,K,N,arr[MaxArrSize],TestCases,Res,j;
	printf("Please enter # of TestCases:");
	scanf("%d",&TestCases);//Get number of test cases
	/*if test cases less than 3 ask the user again*/
	while(TestCases<3)
	{
		printf("Minimum test cases are 3\n");
		printf("Please enter # of TestCases:");
		scanf("%d",&TestCases);
	}
	/*Do the test cases*/
	for(j=0;j<TestCases;j++)
	{
		printf("Please enter N & K:");
		scanf("%d%d",&N,&K);//Ask the user to enter the number of array's e'ements and number or splits
		/*If number of splits more than size of array ask user again*/
		while(K>N || K<1)
		{
			printf("K should be < or = N and more than 1\n");
			printf("Please enter N & K:");
			scanf("%d%d",&N,&K);
		}
		/*Get array's elements*/
		printf("Please enter array elements:");
		for(i=0;i<N;i++)
		{
			scanf("%d",&arr[i]);
		}
		/*Calling ANDING function and save the return into Res*/
		Res=ANDING(arr,N,K);
		printf("AndingResult=%d\n",Res);//Print final result
	}
}

/*Implementation of the function that get the maximun values of subarrays and return their anding result*/
int ANDING(int *arr,int N,int K)
{
	/*define some local variables to check about subarrays*/
	int i,copy_spliteSize,splitSize,j=0,Max=0,newarr[N],newArrayElementNum=0,CurrentSplitNum=0,ReminderSplitSize;
	/*if number of splits < or = the half of array's size*/
	if(K<=(N/2))
	{
		if((N%K)!=0)
		{
			splitSize=(N-1)/K;
		}
		else
		{
			splitSize=N/K;
		}
		copy_spliteSize=splitSize;
		/*Do iterations until number of splits finish*/
		while(CurrentSplitNum<K)
		{
			for(i=j;i<copy_spliteSize;i++)
			{
				if((*(arr+i))>Max)
				{
					Max=*(arr+i);
					newarr[newArrayElementNum]=Max;
				}
			}
			Max=0;
			j=i;
			ReminderSplitSize=N-splitSize;
			N=N-splitSize;
			if(ReminderSplitSize<(splitSize*2))
			{
				copy_spliteSize=copy_spliteSize+ReminderSplitSize;
			}
			else
			{
				copy_spliteSize=copy_spliteSize+splitSize;
			}
			newArrayElementNum++;
			CurrentSplitNum++;
		}
	}
	/*else if number of splits > the half of array's size*/
	else if(K>(N/2))
	{
		copy_spliteSize=N-K;
		splitSize=(N-1)/(N/2);
		CurrentSplitNum=splitSize;
		for(i=0;i<copy_spliteSize;i++)
		{
			for(j=ReminderSplitSize;j<splitSize;j++)
			{
				if(*(arr+j)>Max)
				{
					Max=*(arr+j);
					newarr[newArrayElementNum]=Max;
				}
			}
			Max=0;
			ReminderSplitSize=j;
			splitSize=CurrentSplitNum+ReminderSplitSize;
			newArrayElementNum++;
		}
		for(j=ReminderSplitSize;j<N;j++)
		{
			newarr[newArrayElementNum]=*(arr+j);
			newArrayElementNum++;
		}
	}
	/*Anding all maximin values of subarrays*/
	Max=0xff;
	for(i=0;i<newArrayElementNum;i++)
	{
		printf("%d\n",newarr[i]);
		Max=Max&newarr[i];
	}
	return Max;
}