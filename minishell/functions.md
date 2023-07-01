- `char *readline(const char *prompt)` : 터미널에서 한줄을 읽어서 반환  
    반환된 포인터는 (free)해제해줘야함. [man7.org](https://man7.org/linux/man-pages/man3/readline.3.html)  
	`-lreadline` 옵션을 넣어야 컴파일 가능  
	매개변수  
	+ `prompt` : prompt로 사용할 문자열, NULL이면 prompt하지 않음  

	반환값  
	1. 읽어들인 한 줄  
	2. NULL : 줄이 비어있는 상태에서 EOF를 만났을 때  
- `rl_clear_history` : 
- `int rl_on_new_line(void)` : 업데이트 함수들에게 새 줄로 이동했다고 알림
- `void rl_replace_line (const char *text, int clear_undo)` : `rl_line_buffer`의 내용을 `text`로 변경, `clear_undo`가 0이 아니면, 이전의 모든 변경 사항을 취소할 수 없게 됨
- `void rl_redisplay(void)` : Change what’s displayed on the screen to reflect the current contents of rl_line_buffer.
- `add_history` : Place string at the end of the history list. The associated data field (if any) is set to NULL. If the maximum number of history entries has been set using stifle_history(), and the new number of history entries would exceed that maximum, the oldest history entry is removed.
- `printf` : 
- `malloc` : 
- `free` : 
- `write` : 
- `int access(const char *path, int mode)` : `path` 파일에 대해서 `mode`접근 권한이 있는지 확인  
	매개변수
	+ `mode` : `R_OK`, `W_OK`, `X_OK`의 비트 OR연산 또는 `F_OK`(존재 확인)으로 나타내짐  
	반환값  
	+ 0 : 성공  
	+ -1 : 실패  
- `open` : 
- `read` : 
- `close` : 
- `fork` : 부모 프로세스(fork를 호출하는 프로세스)를 복제해서 자식 프로세스를 만듬  
	단, PID는 다름, 자식들은 서로 다른 부모 pid를 가짐, 

	The child process has a unique process ID.

		o   The child process has a different parent process ID (i.e., the process ID of the parent process).

		o   The child process has its own copy of the parent's descriptors.  These descriptors reference the same underlying objects, so that, for instance, file pointers in file objects
			are shared between the child and the parent, so that an lseek(2) on a descriptor in the child process can affect a subsequent read or write by the parent.  This descriptor
			copying is also used by the shell to establish standard input and output for newly created processes as well as to set up pipes.

		o   The child processes resource utilizations are set to 0; see setrlimit(2).

	fork() will fail and no child process will be created if:
	[EAGAIN]           The system-imposed limit on the total number of processes under executi
on would be exceeded.  This limit is configuration-dependent.

     [EAGAIN]           The system-imposed limit MAXUPRC (<sys/param.h>) on the total number of
 processes under execution by a single user would be exceeded.

     [ENOMEM]           There is insufficient swap space for the new process.
- `wait` : 
- `waitpid` : 
- `wait3` : 
- `wait4` : 
- `signal` : 
- `sigaction` : 
- `sigemptyset` : 
- `sigaddset` : 
- `kill` : 
- `exit` : 
- `getcwd` : 
- `chdir` : 
- `stat` : 
- `lstat` : 
- `fstat` : 
- `unlink` : 
- `execve` : 
- `dup` : 
- `dup2` : 
- `pipe` : 
- `opendir` : 
- `readdir` : 
- `closedir` : 
- `strerror` : 
- `perror` : 
- `isatty` : 
- `ttyname` : 
- `ttyslot` : 
- `ioctl` : 
- `getenv` : 
- `tcsetattr` : 
- `tcgetattr` : 
- `tgetent` : 
- `tgetflag` : 
- `tgetnum` : 
- `tgetstr` : 
- `tgoto` : 
- `tputs` : 