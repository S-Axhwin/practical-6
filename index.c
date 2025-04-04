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

void main() {
  pthread_t t1;
  int n;
  scanf("%d", &n);
  pthread_create(&t1, NULL, show,&n);
  pthread_join(t1, NULL);
  printf("Bye Bye!\n");
}
