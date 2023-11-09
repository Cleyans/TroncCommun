/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:42:18 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/09 16:07:27 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
#define GET_NEXT_LINE.H

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);

size_t  ft_strlen(char *str);

int verif_retour(char *str);

void    *ligne_save(char *reserve, char *ligne);
void    clean_ligne(char *str, size_t count);

#endif