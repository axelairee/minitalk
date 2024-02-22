/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:38:30 by abolea            #+#    #+#             */
/*   Updated: 2023/11/20 18:18:13 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	void	*result;
	t_list	*newelem;

	list = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		result = f(lst->content);
		newelem = ft_lstnew(result);
		if (newelem == NULL)
		{
			ft_lstclear(&list, del);
			del(result);
			return (NULL);
		}
		ft_lstadd_back(&list, newelem);
		lst = lst->next;
	}
	return (list);
}
