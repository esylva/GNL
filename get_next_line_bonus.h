/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:09:02 by esylva            #+#    #+#             */
/*   Updated: 2021/07/13 23:18:28 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 10250
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_checking_ostatok(char *buf, char **line);
char	*ft_clean_buf(char *buf);
char	*ft_lvl_up(char *ostatok, char *i_nl);
char	*ft_strchr(const char *s, char c);
char	*ft_substr(char const *s, int start, int len);

#endif
