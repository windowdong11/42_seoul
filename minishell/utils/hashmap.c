#include <stdio.h>
#include <stdlib.h>

typedef struct s_stringmapnode
{
	struct s_stringmapnode	*next;
}	t_stringmapnode;

typedef	struct s_stringmap
{
	t_stringmapnode map[1000];
}	t_stringmap;

/*

{
	key : value
}
*/


int	main(void)
{
	return (0);
}
