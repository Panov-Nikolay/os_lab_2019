#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

void *thread1(void *arg) {
    (void)arg;

    pthread_mutex_lock(&m1);
    printf("T1: захватил m1\n");
    // fflush(stdout);

    sleep(1); /* даём второму потоку захватить m2 */

    pthread_mutex_lock(&m2); /* ждёт m2, который держит T2 */
    printf("T1: захватил m2\n");
    // fflush(stdout);

    pthread_mutex_unlock(&m2);
    pthread_mutex_unlock(&m1);
    return NULL;
}

void *thread2(void *arg) {
    (void)arg;

    pthread_mutex_lock(&m2);
    printf("T2: захватил m2\n");
    fflush(stdout);

    sleep(1); /* даём первому потоку захватить m1 */

    pthread_mutex_lock(&m1); /* ждёт m1, который держит T1 */
    printf("T2: захватил m1\n");
    fflush(stdout);

    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m2);
    return NULL;
}

int main(void) {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}