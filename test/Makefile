
NAME = test
SRCS = 

all: $(NAME)

$(NAME): ./obj/main.o ./obj/someutils.o
	ar cr ./obj/main.o

./obj:
	mkdir ./obj

libft/libft.a:
	make -C libft

clean:
	rm -rf ./obj

.PHONY: all

# 1. 실행파일 (링킹 해야함)
# 	gcc <오브젝트> <아카이브(정적 라이브러리)> -o <실행파일 이름>

# 2. 정적 라이브러리 (링킹 필요없음)
# 	ar cr <라이브러리 이름> <오브젝트>