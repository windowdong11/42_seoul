## 메모리 누수
leaks => -fsanitize=address, system(leaks)
## 스레드 누수
thread leaks => -fsanitize=thread
## 데이터 레이스
data race => -fsanitize=address
## 테스트케이스
2n 410 200 200
2n+1 610 200 200

빙글빙글
./philo 4 410 200 200

주금
./philo 4 390 200 200 5
./philo 1 1000 300 200
./philo 1 1000 300 200 5