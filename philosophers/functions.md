- `memset`
- `printf`
- `malloc`
- `free`
- `write`

- `int usleep(useconds_t microseconds);`  
함수를 호출한 스레드를 `ms`동안 대기시킴. (실패하면 -1 = 도중에 시그널 받은 경우)
- `int gettimeofday(struct timeval *restrict tp, void *restrict tzp);`  
실패하면 -1
1. 잘못된 인자가 제공된 경우
2. 슈퍼유저가 아닌 유저가 시간을 설정하고자 함
```c
struct timeval {
	time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
	suseconds_t  tv_usec;  /* and microseconds */
};

struct timezone {
	int     tz_minuteswest; /* of Greenwich */
	int     tz_dsttime;     /* type of dst correction to apply */
};
```
- `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);`
새로운 스레드 생성  
(?)thread : 함수 실행에 성공하면, 생성한 thread의 ID를 (인자)thread에 특정한 위치에 저장함  
attr : NULL이면, default가 사용됨.  
start_routine : 시작 함수  
arg : 시작 함수에 주어지는 인자  
errors: EAGAIN EPERM EINVAL  
- `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);`
mutex : attr로 초기화 한 mutex  
attr : 속성, 없으면 기본속성 사용  
errors : EINVAL ENOMEM  
- `int pthread_mutex_destroy(pthread_mutex_t *mutex);`
mutex : mutex에 할당된 자원 반환  
errors : EINVAL, EBUSY
- `int pthread_mutex_lock(pthread_mutex_t *mutex);`
mutex : mutex 
errors : EINVAL, EDEADLK  
- `int pthread_mutex_unlock(pthread_mutex_t *mutex);`
mutex : mutex  
errors : EINVAL, EPERM
- `int pthread_detach(pthread_t thread);`
스레드 종료할 때 알아서 종료되고 자원 반환하도록
errors : EINVAL, ESRCH
- `int pthread_join(pthread_t thread, void **value_ptr);`
스레드 종료까지 대기함
value_ptr :   
errors : EINVAL, ESRCH, EDEADLK

## Structs
- `pthread_attr_t`
- `pthread_mutex_t`

## Errors
- [EAGAIN]  
The system lacked the necessary resources to create another thread, or the system-imposed limit on the total number of threads in a process [PTHREAD_THREADS_MAX] would be exceeded.
- [EPERM]
The caller does not have appropriate permission to set the required scheduling parameters or scheduling policy.
The current thread does not hold a lock on mutex.
- [EINVAL]
The value specified by attr is invalid.
The value specified by mutex is invalid.
- [ENOMEM]
The process cannot allocate enough memory to create another mutex.
- [EBUSY]
Mutex is locked.
- [EDEADLK]
A deadlock would occur if the thread blocked waiting for mutex

## Pthread summerize
POSIX thread functions group
- Thread Routines
- Attribute Object Routines
- Mutex Routines
- Condition Variable Routines
- Read/Write Lock Routines
- Per-Thread Context Routines
- Cleanup Routines