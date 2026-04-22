/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:59:38 by yayiker           #+#    #+#             */
10: /*   Updated: 2025/03/22 13:20:00 by yayiker          ###   ########.fr       */
11: /*                                                                            */
12: /* ************************************************************************** */
13: 
14: #include "get_next_line_bonus.h"
15: 
16: /**
17:  * @brief Bir dizginin uzunluğunu hesaplar.
18:  */
19: size_t	ft_strlen(char *s)
20: {
21: 	size_t	i;
22: 
23: 	i = 0;
24: 	if (!s)
25: 		return (0);
26: 	while (s[i] != '\0')
27: 		i++;
28: 	return (i);
29: }
30: 
31: /**
32:  * @brief Bir dizgi içerisinde belirli bir karakteri arar.
33:  */
34: char	*ft_strchr(char *s, int c)
35: {
36: 	int	i;
37: 
38: 	i = 0;
39: 	if (!s)
40: 		return (0);
41: 	if (c == '\0')
42: 		return ((char *)&s[ft_strlen(s)]);
43: 	while (s[i] != '\0')
44: 	{
45: 		if (s[i] == (char) c)
46: 			return ((char *)&s[i]);
47: 		i++;
48: 	}
49: 	return (0);
50: }
51: 
52: /**
53:  * @brief İki dizgiyi birleştirerek yeni bir dizgi oluşturur (s1 serbest bırakılır).
54:  */
55: char	*ft_strjoin(char *s1, char *s2)
56: {
57: 	size_t	i;
58: 	size_t	j;
59: 	char	*str;
60: 
61: 	if (!s1)
62: 	{
63: 		s1 = (char *)malloc(1 * sizeof(char));
64: 		if (!s1)
65: 			return (NULL);
66: 		s1[0] = '\0';
67: 	}
68: 	if (!s1 || !s2)
69: 		return (NULL);
70: 	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
71: 	if (str == NULL)
72: 		return (NULL);
73: 	i = -1;
74: 	j = 0;
75: 	if (s1)
76: 		while (s1[++i] != '\0')
77: 			str[i] = s1[i];
78: 	while (s2[j] != '\0')
79: 		str[i++] = s2[j++];
80: 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
81: 	return (free(s1), str);
82: }
