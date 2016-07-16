#include <libft.h>
#include <ft_ls.h>

void	exit_failure(void)
{
	ft_putendl("\033[31;5mAn error occured.\033[0m");
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
