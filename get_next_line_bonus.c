/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:27 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/18 15:50:09 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line_from_node(t_list *list_node)
{
	int		line_len;
	char	*next_line;

	if (list_node == NULL)
		return (NULL);
	line_len = len_to_next_line(list_node);
	next_line = malloc(line_len + 1);
	if (next_line == NULL)
		return (NULL);
	copy_str_to_node(list_node, next_line);
	return (next_line);
}

void	append_node(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = get_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buffer;
	new_node->next = NULL;
}

void	populate_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!found_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		append_node(list, buffer);
	}
}

// read will return -1 if the file can't be opened
// the check is there to see if we have permission to read

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	populate_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line_from_node(list);
	polish_list(&list);
	return (next_line);
}
