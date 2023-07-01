# TODO

한명 이상의 철학자가 원형 테이블에 앉아 있다.
서로 스파게티를 먹으려 함

먹고(eat), 생각하고(think), 잠(sleep) 중 단 하나만을 해야 한다.
**테이블에 포크는 철학자의 수** 만큼 있다.

철학자는 **양손에 포크**를 쥐고 먹는다. (먹는데 포크를 두개 쓴다)
**먹기를 끝낸** 철학자는 **포크를 테이블에 다시 놓고 잠**을 잔다.

**일어나면 다시 생각한다(?)**
**철학자가 굶어 죽으면 시뮬레이션이 끝난다**

**모든 철학자는 굶어죽지 말아야 한다**
철학자는 서로 이야기하지 않는다.
철학자는 다른 철학자가 죽는지 모른다.

# 과제 내용

- 전역변수 금지
- 인자
  - number_of_philosophers time_to_die time_to_eat time_to_sleep
	[number_of_times_each_philosopher_must_eat]
		+ 철학자의_수
		+ 굶었을_때_죽기까지의_시간
		+ 먹는데_쓰는_시간
		+ 자는데_쓰는_시간
		+ [철학자가_먹어야_하는_횟수]
- 1부터 숫자가 부여됨
- 동그랗게 앉음 (1의 옆에는 N)

# 출력 포맷
- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

ex) `14 1 died`