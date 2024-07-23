/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:24 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/23 13:14:30 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	reset_list(t_list **list, t_list *clean_node, char *str)
{
	t_list	*temp_node;

	if (*list == NULL)
		return ;
	while (*list)
	{
		temp_node = (*list)->next;
		free((*list)->str_buf);
		free((*list));
		*list = temp_node;
	}
	*list = NULL;
	if (clean_node->str_buf[0])
		*list = clean_node;
	else
	{
		free(str);
		free(clean_node);
	}
}

int	found_newline(t_list *list_node)
{
	int	i_index;

	if (list_node == NULL)
		return (0);
	while (list_node)
	{
		i_index = 0;
		while (list_node->str_buf[i_index] && i_index < BUFFER_SIZE)
		{
			if (list_node->str_buf[i_index] == '\n')
				return (1);
			i_index++;
		}
		list_node = list_node->next;
	}
	return (0);
}

t_list	*get_last_node(t_list *list_node)
{
	if (list_node == NULL)
		return (NULL);
	while (list_node->next)
		list_node = list_node->next;
	return (list_node);
}

void	copy_str_to_node(t_list *list_node, char *str)
{
	int	i_node_str_index;
	int	j_input_str_index;

	if (list_node == NULL)
		return ;
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
			str[j_input_str_index++] = list_node->str_buf[i_node_str_index++];
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
