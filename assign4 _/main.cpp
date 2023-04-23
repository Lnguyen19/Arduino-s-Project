/**
* Assignment 4: Producer Consumer Problem
 * @file main.cpp
 * @author Eric Escareno, Lam Nguyen (TODO: your name)
 * @brief The main program for the producer consumer problem.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "buffer.h"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

// global buffer object
Buffer buffer;
pthread_mutex_t mutex ;
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
sem_t empty;
sem_t full;
   pthread_attr_t attr;
// Producer thread function
// TODO: Add your implementation of the producer thread here
void *producer(void *param) {
    // Each producer insert its own ID into the buffer
    // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.
    buffer_item item = *((int *) param);
    //sem_wait(&full);
    while (true) {
      /* sleep for a random period of time */
      usleep(rand()%1000000);
      
      sem_wait(&empty);
      pthread_mutex_lock(&mutex);
      // TODO: Add synchronization code here
      if (buffer.insert_item(item)) {
        cout << "Producer " << item << ": Inserted item " << item << endl;
        buffer.print_buffer();
      } else {
        cout << "Producer error condition"  << endl;    // shouldn't come here
      }
      pthread_mutex_unlock(&mutex);
      sem_post(&full);
    }
  return NULL;
}

// Consumer thread function
// TODO: Add your implementation of the consumer thread here
void *consumer(void *param) {
    buffer_item item;

    while (true) {
      /* sleep for a random period of time */
      usleep(rand() % 1000000);
      
      // sem_wait(&empty);
      sem_wait(&full);      
      pthread_mutex_lock(&mutex);
      // TODO: Add synchronization code here
      if (buffer.remove_item(&item)) {
          cout << "Consumer " << item << ": Removed item " << item << endl;
          buffer.print_buffer();
      } else {
          cout << "Consumer error condition" << endl;    // shouldn't come here
      }
      pthread_mutex_unlock(&mutex);
      sem_post(&empty);
    }
  return NULL;
}

int main(int argc, char *argv[]) {
  int sleep_time = atoi(argv[1]);
  int producer_ = atoi(argv[2]);
  int consumer_ = atoi(argv[3]);
 // cout<<"passed the extraction"<<endl;

  /* TODO: 2. Initialize buffer and synchronization primitives */
 // buffer = Buffer();

  sem_init(&full, 0, 0);
    sem_init(&empty, 0, 5);
//  cout<<"passed the sem"<<endl;
  pthread_mutex_init(&mutex, NULL);
  pthread_t producerA[producer_];
  pthread_t consumerA[consumer_];
 // cout<<"passed the pthread"<<endl;
//  pthread_attr_init(&attr);

  /* TODO: 3. Create producer thread(s).
  * You should pass an unique int ID to each producer thread, starting from 1 to number of threads */
 // int each[producer_];
  for (int i = 0; i < producer_; i++) {
    // cout<<"passed the "<<i<<" p"<<endl;
    // int *id = new int(i + 1);
   int *p_id  = new int (i+1);
   // each[i] = i+1;
    if(p_id==NULL){
      exit(0);
    }
   // *p_id = i+1;
    pthread_create(&producerA[i],&attr,producer,(void*)p_id);
   // cout<<"passed the "<<i<<" p"<<endl;
  }
  
  /* TODO: 4. Create consumer thread(s) */
  for (int i = 0; i < consumer_; i++) {
     // int c_id = i + 1;
  //  int c_id  = i +1;
      pthread_create(&consumerA[i],&attr , consumer,NULL);
     // cout<<"passed the "<<i<<" c"<<endl;
  }

  /* TODO: 5. Main thread sleep */
  sleep(sleep_time);
 // exit(0);
  /* TODO: 6. Exit */
  return 0;
}