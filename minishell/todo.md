- [ ] 명령어를 기다릴 때, 프롬프트를 띄워야 함
- [ ] working history를 가져야 함 -> 기존에 입력한 명령어 기록
- [ ] `PATH`변수나 상대/절대 경로를 통해서 실행할 수 있어야 함
- [ ] 전역변수를 하나까지만 허용
- [ ] 닫히지 않은 따옴표(quotes)나 과제에서 요구하지 않은 특수문자를 해석하지 않아야 함  
(예시 : `\` 또는 `;`)
- [ ] `'` (single quote)를 처리해서 따옴표에 감싸진 metacharacters를 처리하지 않도록 해야합니다.  
(예시 : echo '~' -> ~)  
(안했을 때 예시 : echo '~' -> '/home/dowon')
- [ ] `"` (double quotes)를 처리해서 따옴표 처리된 metacharacters를 따옴표를 처리하지 않아야 합니다. (`$`제외)  
(예시1 : echo "~" -> ~)  
(안했을 때 예시 : echo "~" -> "/home/dowon")  
(예시2 : echo "\$PATH")
- [ ] 리다이렉션 구현
  - [ ] `<` shoud redirect input
  - [ ] `>` should redirect output
  - [ ] `<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
  - [ ] `>>` should redirect output in append mode
- [ ] `|` PIPE 구현 : The output of each command in the pipeline is connected to the input of the next command via a pipe
- [ ] `$` 환경변수 처리 : `$`로 시작하는 문자열을 그에 대응되는 값으로 치환
- [ ] `$?` : 가장 마지막으로 실행된 foreground pipeline의 exit status로 치환
- [ ] `ctrl-C`, `ctrl-D`, `ctrl-\` [bash](https://www.gnu.org/software/bash/manual/html_node/Signals.html)처럼 처리  
  인터렉티브 모드에서,  
  - [ ] `ctrl-C` 새 줄에 새 프롬프트를 띄움 (SIGINT)
  - [ ] `ctrl-D` 쉘을 종료 (EOF)
  - [ ] `ctrl-\` 아무것도 안함 (SIGQUIT)
- [ ] **Builtins**
  - [ ] `echo` with option `-n`
  - [ ] `cd` with only 상대/절대 경로
  - [ ] `pwd` with 옵션 없이
  - [ ] `export` with 옵션 없이
  - [ ] `unset` with 옵션 없이
  - [ ] `env` with 옵션 없이 or arguments
  - [ ] `exit` with 옵션 없이



## Redirections
`[n]> file` : 출력을 fd n으로부터 file로 돌림  
`[n]< file` : 입력을 fd n으로부터 file로 돌림  
`[n]>> file` : 출력을 fd n으로부터 file로 돌림 (append mode)  
`[n]<< delimiter` : should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
`command | process` : 출력을 다른 프로세스의 입력으로 돌림
The output of each command in the pipeline is
connected to the input of the next command via a pipe.