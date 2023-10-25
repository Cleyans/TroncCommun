#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	index;

	index = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}
