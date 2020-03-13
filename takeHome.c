
/*900927168
  David Meyer
  Midterm: Take Home Programming
  CS3600
  March 3, 2020*/

#include <stdio.h>
#include <pthread.h>
#include <time.h> //for clock-t
#include <unistd.h> // for sleep()
#include <stdlib.h>
#include <semaphore.h>

sem_t mutex;

static int num[9] = {1,2,3,4,5,6,7,8,9};

//================================================

void delay(unsigned int ms){
    /*clock_t goal = ms + clock();
    while(goal > clock());*/
    clock_t start = clock();
    while((clock() - start) * 1000 / CLOCKS_PER_SEC < ms);
    //20*9 = 180,  need at least 180ms on this program
}

//================================================

void *Reverse(void *t) {
    long my_id = (long)t;
    
    printf("Rev 1 \n");
    //Wait
    //sem_wait(&mutex);
    
    //critical stuff
    printf("Rev 2 \n");
    
    int newArray[9];
	for (int i = 0; i < 9; i++) {
        //printf("\nbefore %d\n",num[i]);
        int j = 8-i;//0 to 8 for index
        if(i != 10){
            newArray[j] = num[i];
        }else{
            //newArray[
        }
        //printf("j = %d \n",j);
        delay(20);
        //printf("delay %d\n",i);
    }
    
    for(int i=0; i<9;i++){
        num[i] = newArray[i];
        //printf("i = %d\n",i);
    }
    
    //signal
    sem_post(&mutex);
    
    
    return NULL;
}//reverse thread

//================================================

void *Sum(void *t){
    long my_id = (long)t;
    
    printf("SUM 1 \n");
    
    //wait
    sem_wait(&mutex);
    //sem_post(&mutex);
    
    //critical
    printf("SUM 2 \n");
    int n = 8;
    int m = 1;
    int num1 = 0;
    int num2 = 0;
    num1 = num[n];
    //printf("n = %d",num1);
    num2 = num[m];
    //printf("m = %d", num2);
    int sum = num1 + num2;
    printf("SUM = %d\n",sum);
    
    //signal
    
    return NULL;
}//sum thread

//================================================


int main(int argc, char *argv[]){
    /*Race conditions
    While thread 1 is reversing the array, thread
    2 could obtain an incorrect num from the
    array because the reverse could happen before
    or after we want to get the nums for thread 2.
        
        Deadlock, both call at the same time.
        
        For loop in thread 1 (reverse) could cause
        unexpected results depending on number of
        threads.
        */
    
        //900 927168
        //TIME TAKEN =180.231000 ms
    
    //After race conditions
        //Time Taken = 180.362000
        

        
        
    double timeSpent = 0.0;//store execution time
    clock_t begin = clock();
        
    printf("\nArray before threads:  ");
    for(int i=0; i < 9; i++){
        printf("  %d",num[i]);
    }
    printf("\n");
    
    /*long t1=1, t2=2, t3=3;//for mutex
    //pthread_t p1,p2;
    pthread_t threads[2];//mutex version
    pthread_attr_t attr;
    
    
    
    
    //mutex Version
    pthread_mutex_init(&count_mutex,NULL);
    pthread_cond_init(&count_threshold_cv, NULL);
    //Protability, explicitly create threads in a joinable state
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
    pthread_create(&threads[0], &attr, Reverse,(void *)t1);
    pthread_create(&threads[1],&attr,Sum,(void*)t2);*/
    //wait for all threads to complete
    /*for(int i=0; i< NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }*/
    
    
    //FIRST VERSION
    /*pthread_create(&p1,NULL,Reverse,NULL);
    pthread_create(&p2,NULL,Sum,NULL);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);*/
    
    
    
    
    
    
    
    
    //FINAL VERSION
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,Sum,NULL);
    //sleep(2);
    pthread_create(&t2,NULL,Reverse,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    
    
    
    
    
    
    
    
    //Done with threads
    printf("New Array:  ");
    for(int i=0; i < 9; i++){
        printf(" %d",num[i]);
    }
    printf("\n");
    
    sleep(3);
    clock_t end = clock();
    
    //calculate the elapsed time now
    timeSpent  += (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("Time elapsed is %f seconds \n", timeSpent);
    double msTest = timeSpent * 1000;
    printf("ms = %f\n",msTest);
    
    
    
    
    
    sem_destroy(&mutex);//final version
    return 0;
    
    /* Clean up and exit */
   /* pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&count_threshold_cv);
    pthread_exit (NULL);*/
    
}
