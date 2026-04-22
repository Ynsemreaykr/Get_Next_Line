/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:59:42 by yayiker           #+#    #+#             */
10: /*   Updated: 2025/03/22 13:20:00 by yayiker          ###   ########.fr       */
11: /*                                                                            */
12: /* ************************************************************************** */
13: 
14: #include "get_next_line.h"
15: 
16: /**
17:  * @brief Bir dizginin uzunluğunu hesaplar.
18:  * 
19:  * @param s Uzunluğu hesaplanacak dizgi.
20:  * @return Dizginin uzunluğu.
21:  */
22: size_t	ft_strlen(char *s)
23: {
24: 	size_t	i;
25: 
26: 	i = 0;
27: 	if (!s)
28: 		return (0);
29: 	while (s[i] != '\0')
30: 		i++;
31: 	return (i);
32: }
33: 
34: /**
35:  * @brief Bir dizgi içerisinde belirli bir karakteri arar.
36:  * 
37:  * @param s Arama yapılacak dizgi.
38:  * @param c Aranacak karakter.
39:  * @return Karakterin bulunduğu yerin adresi veya bulunamazsa NULL.
40:  */
41: char	*ft_strchr(char *s, int c)
42: {
43: 	int	i;
44: 
45: 	i = 0;
46: 	if (!s)
47: 		return (0);
48: 	if (c == '\0')
49: 		return ((char *)&s[ft_strlen(s)]);
50: 	while (s[i] != '\0')
51: 	{
52: 		if (s[i] == (char) c)
53: 			return ((char *)&s[i]);
54: 		i++;
55: 	}
56: 	return (0);
57: }
58: 
59: /**
60:  * @brief İki dizgiyi birleştirerek yeni bir dizgi oluşturur.
61:  * s1 belleği bu işlem sonunda serbest bırakılır.
62:  * 
63:  * @param s1 İlk dizgi.
64:  * @param s2 İkinci dizgi.
65:  * @return Birleştirilmiş yeni dizgi.
66:  */
67: char	*ft_strjoin(char *s1, char *s2)
68: {
69: 	size_t	i;
70: 	size_t	j;
71: 	char	*str;
72: 
73: 	if (!s1)
74: 	{
75: 		s1 = (char *)malloc(1 * sizeof(char));
76: 		if (!s1)
77: 			return (NULL);
78: 		s1[0] = '\0';
79: 	}
80: 	if (!s1 || !s2)
81: 		return (NULL);
82: 	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
83: 	if (str == NULL)
84: 		return (NULL);
85: 	i = -1;
86: 	j = 0;
87: 	if (s1)
88: 		while (s1[++i] != '\0')
89: 			str[i] = s1[i];
90: 	while (s2[j] != '\0')
91: 		str[i++] = s2[j++];
92: 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
93: 	return (free(s1), str);
94: }
