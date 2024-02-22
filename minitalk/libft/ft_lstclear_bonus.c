/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:59:11 by abolea            #+#    #+#             */
/*   Updated: 2023/11/17 15:38:01 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst2;
	t_list	*next;

	if (*lst && lst && del)
	{
		lst2 = *lst;
		while (lst2)
		{
			next = lst2->next;
			del(lst2->content);
			free(lst2);
			lst2 = next;
		}
		*lst = NULL;
	}
}
