#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *show(void *msg) {
  sleep(2);
  int mul = 1;
  for(int i = 1; i <= *(int *)msg; i ++) {
    mul *= i;
  }

  printf("%d\n", mul);
}

void* evenOdd(void *msg) {
  printf((*(int *)msg)%2==0?"even\n":"odd\n");
}

void main() {
  pthread_t t1;
  int n;
  scanf("%d", &n);
  pthread_create(&t1, NULL, show,&n);
  pthread_join(t1, NULL);

  pthread_t t2;
  pthread_create(&t2, NULL, evenOdd, &n);
  pthread_join(t2, NULL);
  printf("Bye Bye!\n");
}
