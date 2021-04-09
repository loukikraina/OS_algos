#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

int allocation_matrix[20][20],claim_matrix[20][20],CA[20][20],np,nr,ResourceV[20],availR[20],processed[20];




int check_R(int i){
	int j,tag=0;
	for(j=0;j<nr;j++){
		if((CA[i][j]-availR[j])<=0)
			tag++;
	}
	if(tag==nr)
		return 1;
	else
		return 0;
}
void allot_R(int i){
	int j;
	for(j=0;j<nr;j++){
		availR[j]+=allocation_matrix[i][j];
	}
}
int main(){
	int sumR=0,i,j,z;
 //	clrscr();
	printf("Enter the number of processes and resources:- \n");
	scanf("%d %d",&np,&nr);
	printf("Enter the claim matrix :- like p1r1,p1r2....\n");
	for(i=0;i<np;i++)
		for(j=0;j<nr;j++)
			scanf("%d",&claim_matrix[i][j]);
	printf("Enter the allocation matrix :- like p1r1,p1r2....\n");
	for(i=0;i<np;i++)
		for(j=0;j<nr;j++)
			scanf("%d",&allocation_matrix[i][j]);
	printf("Enter the resource vector :- like r1,r2....\n");
	for(i=0;i<nr;i++)
		scanf("%d",&ResourceV[i]);
	for(i=0;i<nr;i++){
		sumR=0;
		for(j=0;j<np;j++)
			sumR+=allocation_matrix[j][i];
		availR[i]=ResourceV[i]-sumR;
	}
	for(i=0;i<np;i++)
		for(j=0;j<nr;j++)
			CA[i][j]=claim_matrix[i][j]-allocation_matrix[i][j];

	//for showing C-A and availale vector
	printf("C-A matrix:- \n");
	for(i=0;i<np;i++){
		for(j=0;j<nr;j++)
			printf("%d ",CA[i][j]);
		printf("\n");
	}
	printf("Available resource vector:- \n");
				for(j=0;j<nr;j++)
					printf("%d\t",availR[j]);
	z=1;
	for(j=0;j<np;j++)
	    processed[j]=0;
	while(1){

		for(i=0;i<np;i++){
		    if(z==np+1)
			    break;
			printf("\n\nChecking process %d for safe execution....",i+1);
			if(check_R(i) && processed[i]==0){
				printf("\nProcess %d can be processed safely. Therefore processing it and then claiming back its resources:- \n",i+1);
				processed[i]=z;
				z++;
				allot_R(i);
				printf("Available resource vector now:- \n");
				for(j=0;j<nr;j++)
					printf("%d\t",availR[j]);
			}
			else if(processed[i]!=0)
			    continue;
			else{
				printf("Process %d can't be processed now, not enough resource available!\n",i+1);
			}
// 			getch();
		}
		if(z==np+1)
			break;
		else if(z==0){
			printf("These processes will lead to dead-lock, no safe state found!!!\n");
			exit(0);
		}

	}
	printf("\nProcesses in order of execution:- ");
	for(j=0;j<np;j++){
	    for(i=0;i<np;i++){
	        if(processed[i]==j+1)
		    printf("%d\t",i+1);
	    }
	}
	return 0;
}

/*input	
4 3
3 2 2
6 1 3
3 1 4
4 2 2
1 0 0
6 1 2
2 1 1
0 0 2
9 3 6 */
/*output

Enter the number of processes and resources:- 
Enter the claim matrix :- like p1r1,p1r2....
Enter the allocation matrix :- like p1r1,p1r2....
Enter the resource vector :- like r1,r2....
C-A matrix:- 
2 2 2 
0 0 1 
1 0 3 
4 2 0 
Available resource vector:- 
0	1	1	

Checking process 1 for safe execution....Process 1 can't be processed now, not enough resource available!


Checking process 2 for safe execution....
Process 2 can be processed safely. Therefore processing it and then claiming back its resources:- 
Available resource vector now:- 
6	2	3	

Checking process 3 for safe execution....
Process 3 can be processed safely. Therefore processing it and then claiming back its resources:- 
Available resource vector now:- 
8	3	4	

Checking process 4 for safe execution....
Process 4 can be processed safely. Therefore processing it and then claiming back its resources:- 
Available resource vector now:- 
8	3	6	

Checking process 1 for safe execution....
Process 1 can be processed safely. Therefore processing it and then claiming back its resources:- 
Available resource vector now:- 
9	3	6	
Processes in order of execution:- 2	3	4	1*/