## 살아있음
./philo 3 610 200 200
./philo 5 610 200 200
./philo 2 410 200 200
./philo 4 410 200 200

## hard
./philo 199 610 200 200
./philo 200 410 200 200

## 주금
./philo 1 500 200 200
./philo 4 400 200 300
./philo 4 400 300 200
./philo 4 400 500 200


./philo number_of_philosophers time_to_die    time_to_eat     time_to_sleep [number_of_times_each_philosopher_must_eat]
./philo 철학자의 수               안먹으면 죽는시간  먹는데 걸리는 시간   자는데 걸리는 시간  몇번 먹으면 끝나는지
철학자는 : 먹고 -> 자고 -> 생각(=기다림)
먹을라면 : 왼쪽 오른쪽 포크가 필요함
먹는시간동안 : 두 포크를 들고 먹음

4 410 200 200
4 310 200 200
5 610 200 200

400
    1   2
1 : 먹음 -> 잠 -> 띵킹 -> 잠
2 :     먹음 -> 잠
3 : 먹음 -> 잠 -> 먹음 -> 잠
4 :     먹음 -> 잠
5 :             먹음 -> 잠
