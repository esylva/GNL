/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:28:08 by esylva            #+#    #+#             */
/*   Updated: 2021/07/15 08:25:27 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_lvl_up(char *ost, char *nl)
{
	char	*tmp;

	tmp = ost;
	ost = ft_strdup(nl);
	free(tmp);
	return (ost);
}

char 	*ft_checking_ostatok(char *ostatok, char **line)
{
	char	*i_nl;

	if (ft_strlen(ostatok))
	{
		i_nl = ft_strchr(ostatok, '\n');
		if (!i_nl)
		{
			*line = ft_strdup(ostatok);
			ostatok = ft_clean_buf(ostatok);
		}
		else
		{
			*line = ft_substr(ostatok, 0, i_nl - ostatok + 1);
			ostatok = ft_lvl_up(ostatok, i_nl + 1);
		}
	}
	else
	{
		ostatok = ft_clean_buf(ostatok);
		*line = NULL;
	}
	return (ostatok);
}

char	*ft_clean_buf(char *buf)
{
	free(buf);
	buf = NULL;
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*ostatok = NULL;
	size_t		rd_from_fd;
	char		*line;
	char		*buf;

	line = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (ft_clean_buf(buf));
	rd_from_fd = 1;
	while (rd_from_fd > 0 && !ft_strchr(ostatok, '\n'))
	{
		rd_from_fd = read(fd, buf, BUFFER_SIZE);
		buf[rd_from_fd] = 0;
		ostatok = ft_strjoin_mod(ostatok, buf);
	}
	free(buf);
	ostatok = ft_checking_ostatok(ostatok, &line);
	return (line);
}
