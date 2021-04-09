//01/03/2021

#include<conio.h>
#include<stdio.h>
int n,bt[10],t1[10];
struct process{
	int burst_time;
	int completion_time;
	int arrival_time;
	int start_time;
	int wait_time;
	char completed;
	char arrived;
}p[10],temp;

int getMin()
{
	int min,i,index;
    min=t1[0];
    for(i=1; i<n; i++)
    {
		   if(min>t1[i])
		    {
			min=t1[i];
		    }
    }
    for(i=0;i<n;i++)
	if(min==bt[i])
		index=i;
    return index;
}

void main(){
	int a,time_taken=0,k,flag=0,j,clock=-1,tempbt,minInd,gantT=0;
	float aw=0,at=0;
	clrscr();
	printf("Enter the total number of process:- ");
	scanf("%d",&n);
	k=n;
	for(a=0;a<n;a++){
		printf("Enter burst time for process %d and also its arrival time:-  ",a+1);
		scanf("%d %d",&p[a].burst_time,&p[a].arrival_time);
		p[a].completed = 'F';
		p[a].arrived = 'n';
		p[a].start_time=0;
		bt[a]=p[a].burst_time;
	}
 /*	for(a=0;a<n-1;a++){
		for(j=0;j<n-1-a;j++)
		{
			if(p[j].arrival_time>p[j+1].arrival_time)
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}


	} */

	printf("\nThe Gantt's chart:- \n");
	time_taken=0;
	minInd = -6;
	while(clock++)
	{
		flag=0;
		for(a=0;a<k;a++)
		{
			if(p[a].arrival_time==clock)
			{
				p[a].arrived='y';
			}
		}
		for(a=0;a<k;a++)
		{
			if(p[a].arrived=='y' && p[a].completed=='F')
			{
				t1[a] = bt[a];
			}
			else
				t1[a] = 9999;
		}
		if(minInd == -6 || minInd != getMin()  )
		{
			minInd = getMin();
			bt[minInd]--;
			printf("%d  Process '%d'  %d",gantT,minInd+1,clock);
			gantT=clock;
		}
		else{
			bt[minInd]--;
		}
		for(a=0;a<k;a++)
		{
			if(p[a].arrived=='y' && p[a].completed=='F' && minInd!=a)
				p[a].wait_time++;
			if(bt[a]==0)
				{
						p[a].completed='T';
						p[a].completion_time = clock-p[a].arrival_time;
				}
			if(p[a].completed=='F')
				flag++;

		}
		if(flag==0)
			break;
	}	

		
	getch();
	printf("\nWaiting time for process:- \n");
	for(a=0;a<n;a++)
	{
		printf("Process '%d'\tWaiting time:- %d\n",a+1,p[a].wait_time);
		aw = aw+p[a].wait_time;
	}
	getch();
	printf("\nTurnaround time for process:- \n");

	for(a=0;a<n;a++)
	{
		printf("Process '%d'\tTurnaround time:- %d\n",a+1,p[a].completion_time);
		at = at + p[a].completion_time;
	}
	getch();

	printf("Average waiting time:- %f\n", aw/(float)n);
	printf("Average turnaround time:- %f\n", at/(float)n);



	getch();
}



