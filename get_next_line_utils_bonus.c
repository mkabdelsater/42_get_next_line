/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:24 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/18 15:50:41 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	len_to_next_line(t_list *list_node)
{
	int	index;
	int	len;

	if (list_node == NULL)
		return (0);
	len = 0;
	while (list_node)
	{
		index = 0;
		while (list_node->str_buf[index])
		{
			if (list_node->str_buf[index] == '\n')
				return (++len);
			index++;
			len++;
		}
		list_node = list_node->next;
	}
	return (len);
}
