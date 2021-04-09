#include<conio.h>
#include<stdio.h>

struct process{
	int burst_time;
}p[10];

int g[11];

void main(){
	int	a,n;
	float aw,at;
	g[0]=0;
	clrscr();
	printf("Enter the total number of process:- ");
	scanf("%d",&n);
	for(a=0;a<n;a++){
		printf("Enter burst time for process %d:-  ",a+1);
		scanf("%d",&p[a].burst_time);
	}
	for(a=0;a<n;a++)
	{
		g[a+1] += g[a]+p[a].burst_time;
	}
	printf("\nThe Gantt's chart:- \n");
	printf("%d",g[0]);
	for(a=0;a<n;a++)
	{
		printf("\tProcess '%d'\t%d",a+1,g[a+1]);
	}
	getch();
	printf("\nWaiting time for process:- \n");
	for(a=0;a<n;a++)
	{
		printf("Process '%d'\tWaiting time:- %d\n",a+1,g[a]);
		aw = aw+g[a];
	}
	getch();
	printf("\nTurnaround time for process:- \n");

	for(a=0;a<n;a++)
	{
		printf("Process '%d'\tTurnaround time:- %d\n",a+1,g[a+1]);
		at = at +g[a+1];
	}
	getch();

	printf("Average waiting time:- %f\n", aw/(float)n);
	printf("Average turnaround time:- %f\n", at/(float)n);



	getch();
}



