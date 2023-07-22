#include <stdlib.h>
#include <unistd.h>

int	my_strlen(char *str)
{
	const char	*start;

	start = str;
	while (*str != '\0')
		str++;
	return (str - start);
}

void	my_putstr(char *str)
{
	if (str == NULL)
		write(1, "(NULL)", 6);
	else
		write(1, str, my_strlen(str));
}

int	my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	my_atoi(char *str)
{
	int	num;
	int	is_negative;

	is_negative = *str == '-';
	if (is_negative && my_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	if (*str == '-' || *str == '+')
		str++;
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (is_negative)
		return (-num);
	return (num);
}

void	my_strcpy(char *src, char *dest)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

char	*my_itoa(int num)
{
	char	buffer[12];
	char	*result;
	int		idx;
	int		is_negative;

	buffer[11] = '\0';
	idx = 10;
	if (num == 0)
		buffer[idx--] = '0';
	is_negative = num < 0;
	if (is_negative)
	{
		buffer[idx--] = -(num % 10) - '0';
		num = -(num / 10);
	}
	while (num)
	{
		buffer[idx--] = num % 10 + '0';
		num = num / 10;
	}
	result = malloc(sizeof(char) * (11 - idx));
	my_strcpy(buffer + idx + 1, result);
	return (result);
}

void	my_putnum(int num)
{
	char	*str_num;

	str_num = my_itoa(num);
	write(1, str_num, my_strlen(str_num));
	free(str_num);
}

int	main(int argc, char *argv[])
{
	int idx;
	int num;
	int count;

	if (argc <= 2)
	{
		my_putstr("Need more than 2 arguments.\n");
		return (0);
	}
	count = my_atoi(argv[1]);
	if (argc - 2 != count)
	{
		my_putstr("Args count does not match!\n");
		return (0);
	}
	idx = 2;
	while (idx < argc)
	{
		num = my_atoi(argv[idx++]);
		num += 10;
		my_putnum(num);
		write(1, "\n", 1);
	}
	return (0);
}