/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:42:18 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/13 17:07:50 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *stash, char *buff);
char	*ft_strchr(char *s, int c);
char	*ft_ligne_suivante(char *reserve);
char	*ft_extraire_ligne(char *reserve);
char	*ft_read(int fd, char *reserve);

size_t	ft_strlen(char *str);

#endif
