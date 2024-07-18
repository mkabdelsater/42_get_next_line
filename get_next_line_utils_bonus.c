/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:24 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/18 15:59:48 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	copy_str_to_node(t_list *list_node, char *str)
{
	int	i_node_str_index;
	int	j_input_str_index;

	j_input_str_index = 0;
	while (list_node)
	{
		i_node_str_index = 0;
		while (list_node->str_buf[i_node_str_index])
		{
			if (list_node->str_buf[i_node_str_index] == '\n')
			{
				str[j_input_str_index++] = '\n';
				str[j_input_str_index] = '\0';
				return ;
			}
			str[j_input_str_index++] = list_node->str_buf[i_node_str_index];
		}
		list_node = list_node->next;
	}
	str[j_input_str_index] = '\0';
}

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
