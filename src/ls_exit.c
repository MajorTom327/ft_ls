#include <libft.h>
#include <ft_ls.h>
#include <stdio.h>
#include <errno.h>

void	exit_failure(void)
{
	perror(strerror(errno));
	exit(EXIT_FAILURE);
}

void	exit_mem(void *mem)
{
	if (mem == NULL)
	{
		ft_putendl("\033[31mSomething is wrong with the memory...\033[0m");
		exit_failure();
	}
}
