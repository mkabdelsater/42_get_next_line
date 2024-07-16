/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:18:14 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/16 14:50:56 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * basic ideas :
 * * we need to get the the next line from a file (i.e. anything)
 * * we need to somehow remember where we stopped when reading from a file
 * * * this makes it obvious why reading from a file that's been modified is problematic
 * ? we need to store a cursor that points to the last line that we got
 * ? where? the input file itself? the program (system file) ? the process file?
 * ! Answer : the file descriptor's offset!
 * ? what is a static variable ???
 * ! Answer : a variable with program lifetime but function bound scope
 */
