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
		exit_failure();
}
