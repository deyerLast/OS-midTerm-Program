//Program for thread as array
//Ranjidha CS3600
//02/13/2020


#include<stdio.h>
#include<pthread.h>

static int num[10];;


//Begin Thread method 
        void *Add(int n){
	int i,j;
        for(i=0,j=n;i<5;i++)
 	   num[n+i]=num[n+i]+2;
  	 return NULL;
  	}
//End of Thread method 

//Begin main
int main(int argc,char *argv[]){

  pthread_t p1[5]; // Thread as array

  printf("Main starts here\n\n");
  printf("Enter array values numbers");
for(int i=0;i<10;i++)
{
  scanf("%d",&num[i]);
 }

  pthread_create(&p1[0],NULL,Add,0); // Call thread1 passing array position
  pthread_create(&p1[1],NULL,Add,5); // Call thread2 passing array position
 
  pthread_join(p1[0],NULL);
  pthread_join(p1[1],NULL);


for(int i=0;i<10;i++)
{
  printf("  %d",num[i]);
 }
    printf("\n");
 
  return(0);
}
//End of main


