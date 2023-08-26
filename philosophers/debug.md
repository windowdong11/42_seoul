(lldb) p data->philosophers 
(t_philo *) $101 = 0x0000611000000540
(lldb) p data->philosophers+1
(t_philo *) $102 = 0x0000611000000588
(lldb) p data->philosophers+2
(t_philo *) $103 = 0x00006110000005d0

(lldb) p data->forks_mutex
(pthread_mutex_t *) $104 = 0x0000610000000040
(lldb) p data->forks_mutex + 1
(pthread_mutex_t *) $105 = 0x0000610000000080
(lldb) p data->forks_mutex + 2
(pthread_mutex_t *) $106 = 0x00006100000000c0

0x0000611000000588

0x0000002000000040


2n 410 200 200
2n+1 610 200 200