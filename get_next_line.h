/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:59:51 by yayiker           #+#    #+#             */
10: /*   Updated: 2025/03/22 13:20:00 by yayiker          ###   ########.fr       */
11: /*                                                                            */
12: /* ************************************************************************** */
13: 
14: #ifndef GET_NEXT_LINE_H
15: # define GET_NEXT_LINE_H
16: 
17: # include <unistd.h>
18: # include <stdlib.h>
19: 
20: // Okuma tampon boyutu varsayılanı
21: # ifndef BUFFER_SIZE
22: #  define BUFFER_SIZE 42
23: # endif
24: 
25: // Ana fonksiyon
26: char	*get_next_line(int fd);
27: 
28: // Yardımcı fonksiyonlar (Utils)
29: char	*ft_strjoin(char *s1, char *s2);
30: char	*ft_strchr(char *s, int c);
31: size_t	ft_strlen(char *s);
32: 
33: // İç yardımcı fonksiyonlar
34: char	*read_function(int fd, char *str);
35: char	*ft_getline(char *buffer);
36: char	*ft_getrest(char *buffer);
37: 
38: #endif