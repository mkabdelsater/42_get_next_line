/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:21 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/18 15:38:10 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

char	*get_line_from_node(t_list *list_node);
void	append_node(t_list **list, char *buffer);
void	populate_list(t_list **list, int fd);
char	*get_next_line(int fd);

#endif
