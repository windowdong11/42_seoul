# FT_IRC

TCP/IP를 통해서 채팅을 하는 서버 server-to-server형식으로 연결이 되어 서로 다른 서버의 채널에도 입장할 수 있다.  
이러한 이유로 Internet Relay chat이라 부른다.

여기에서는 server-to-server구현은 없는 채팅서버를 만드는 것을 목표로 한다.  
채팅서버에는 User가 존재하고, Channel이 존재한다.  

## User

유저는 채널에 들어갈 수 있다.
채널에서 op 권한을 가지고 있을 수 있다.

## Channel

채널은 모드를 가지며, op는 채널의 모드를 변경할 수 있다.

## Command

일반 유저와 op 유저가 사용할 수 있는 명령어가 존재한다.
