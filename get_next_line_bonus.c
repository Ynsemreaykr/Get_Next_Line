/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:59:30 by yayiker           #+#    #+#             */
10: /*   Updated: 2025/03/22 13:20:00 by yayiker          ###   ########.fr       */
11: /*                                                                            */
12: /* ************************************************************************** */
13: 
14: #include "get_next_line_bonus.h"
15: 
16: /**
17:  * @brief Çoklu dosya tanımlayıcı (fd) desteği ile bir sonraki satırı okur.
18:  * 
19:  * @param fd Okunacak dosyanın tanımlayıcısı.
20:  * @return Okunan satır, hata veya EOF durumunda NULL.
21:  */
22: char	*get_next_line(int fd)
23: {
24: 	static char	*buffer[4096]; // Her fd için ayrı bir tampon
25: 	char		*line;
26: 
27: 	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4095)
28: 		return (0);
29: 	buffer[fd] = read_function(fd, buffer[fd]);
30: 	if (!buffer[fd])
31: 		return (NULL);
32: 	line = ft_getline(buffer[fd]);
33: 	buffer[fd] = ft_getrest(buffer[fd]);
34: 	return (line);
35: }
36: 
37: /**
38:  * @brief Dosyadan veri okuyup tamponu doldurur.
39:  */
40: char	*read_function(int fd, char *str)
41: {
42: 	char	*tmp;
43: 	int		len;
44: 
45: 	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
46: 	if (!tmp)
47: 		return (NULL);
48: 	len = 1;
49: 	while (!ft_strchr(str, '\n') && (len != 0))
50: 	{
51: 		len = read(fd, tmp, BUFFER_SIZE);
52: 		if (len == -1)
53: 		{
54: 			free(tmp);
55: 			free(str);
56: 			return (NULL);
57: 		}
58: 		tmp[len] = '\0';
59: 		str = ft_strjoin(str, tmp);
60: 	}
61: 	free(tmp);
62: 	return (str);
63: }
64: 
65: /**
66:  * @brief Tampondan tek bir satırı ayıklar.
67:  */
68: char	*ft_getline(char *buffer)
69: {
70: 	int		i;
71: 	char	*line;
72: 
73: 	i = 0;
74: 	if (!buffer[i])
75: 		return (NULL);
76: 	while (buffer[i] && buffer[i] != '\n')
77: 		i++;
78: 	line = (char *)malloc(sizeof(char) * (i + 2));
79: 	if (!line)
80: 		return (NULL);
81: 	i = 0;
82: 	while (buffer[i] && buffer[i] != '\n')
83: 	{
84: 		line[i] = buffer[i];
85: 		i++;
86: 	}
87: 	if (buffer[i] == '\n')
88: 	{
89: 		line[i] = buffer[i];
90: 		i++;
91: 	}
92: 	line[i] = '\0';
93: 	return (line);
94: }
95: 
96: /**
97:  * @brief Satırdan sonra kalan kısmı saklar.
98:  */
99: char	*ft_getrest(char *buffer)
100: {
101: 	int		i;
102: 	int		j;
103: 	char	*restof;
104: 
105: 	i = 0;
106: 	while (buffer[i] && buffer[i] != '\n')
107: 		i++;
108: 	if (!buffer[i])
109: 	{
110: 		free(buffer);
111: 		return (NULL);
112: 	}
113: 	restof = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
114: 	if (!restof)
115: 		return (NULL);
116: 	i++;
117: 	j = 0;
118: 	while (buffer[i])
119: 		restof[j++] = buffer[i++];
120: 	restof[j] = '\0';
121: 	free(buffer);
122: 	return (restof);
123: }
