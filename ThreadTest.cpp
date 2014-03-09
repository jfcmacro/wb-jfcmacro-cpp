#include <iostream>
#include <thread>
#include <mutex>

std::mutex sample_mutex;

struct p1{
  int		count;
};

p1	sample;
// int full  = 0; 
// int empty = 1;


void incremento1(int sec){
  sample_mutex.lock();
  sample.count++;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  printf("Incremento1 counter: %d \n",sample.count);
  sample_mutex.unlock();
}

void incremento2(int sec){
  sample_mutex.lock();
  sample.count++;
  sample.count++;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  printf("Incremento2 counter: %d \n",sample.count);
  sample_mutex.unlock();
}

int main(){

  sample.count = 0;

  std::thread t1(incremento1,5);
  std::thread t2(incremento2,5);
  t1.join();
  t2.join();
  return 0;
}

