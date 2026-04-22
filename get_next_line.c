/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:59:46 by yayiker           #+#    #+#             */
10: /*   Updated: 2025/03/22 13:20:00 by yayiker          ###   ########.fr       */
11: /*                                                                            */
12: /* ************************************************************************** */
13: 
14: #include "get_next_line.h"
15: 
16: /**
17:  * @brief Verilen dosya tanımlayıcısından (fd) bir sonraki satırı okur.
18:  * 
19:  * @param fd Okunacak dosyanın tanımlayıcısı.
20:  * @return Okunan satır (yeni satır karakteri dahil), hata veya EOF durumunda NULL.
21:  */
22: char	*get_next_line(int fd)
23: {
24: 	static char	*buffer;
25: 	char		*line;
26: 
27: 	if (fd < 0 || BUFFER_SIZE <= 0)
28: 		return (0);
29: 	// Dosyadan okuma yapar ve statik tamponu günceller
30: 	buffer = read_function(fd, buffer);
31: 	if (!buffer)
32: 		return (NULL);
33: 	// Tampondan bir tam satırı ayıklar
34: 	line = ft_getline(buffer);
35: 	// Satırdan sonra kalan kısmı bir sonraki çağrı için saklar
36: 	buffer = ft_getrest(buffer);
37: 	return (line);
38: }
39: 
40: /**
41:  * @brief Dosyadan BUFFER_SIZE kadar veri okur ve mevcut veriye ekler.
42:  * 
43:  * @param fd Dosya tanımlayıcısı.
44:  * @param buffer Mevcut veri tamponu.
45:  * @return Güncellenmiş tampon.
46:  */
47: char	*read_function(int fd, char *buffer)
48: {
49: 	char	*tmp;
50: 	int		len;
51: 
52: 	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
53: 	if (!tmp)
54: 		return (NULL);
55: 	len = 1;
56: 	// Yeni satır karakteri bulana veya dosya sonuna gelene kadar oku
57: 	while (!ft_strchr(buffer, '\n') && (len != 0))
58: 	{
59: 		len = read(fd, tmp, BUFFER_SIZE);
60: 		if (len == -1)
61: 		{
62: 			free(tmp);
63: 			free(buffer);
64: 			return (NULL);
65: 		}
66: 		tmp[len] = '\0';
67: 		buffer = ft_strjoin(buffer, tmp);
68: 	}
69: 	free(tmp);
70: 	return (buffer);
71: }
72: 
73: /**
74:  * @brief Tamponun başından ilk yeni satır karakterine (\n) kadar olan kısmı alır.
75:  * 
76:  * @param buffer Veri tamponu.
77:  * @return Ayıklanan satır.
78:  */
79: char	*ft_getline(char *buffer)
80: {
81: 	int		i;
82: 	char	*line;
83: 
84: 	i = 0;
85: 	if (!buffer[i])
86: 		return (NULL);
87: 	while (buffer[i] && buffer[i] != '\n')
88: 		i++;
89: 	// Bellek ayırma: satır uzunluğu + '\n' (varsa) + '\0'
90: 	line = (char *)malloc(sizeof(char) * (i + 2));
91: 	if (!line)
92: 		return (NULL);
93: 	i = 0;
94: 	while (buffer[i] && buffer[i] != '\n')
95: 	{
96: 		line[i] = buffer[i];
97: 		i++;
98: 	}
99: 	if (buffer[i] == '\n')
100: 	{
101: 		line[i] = buffer[i];
102: 		i++;
103: 	}
104: 	line[i] = '\0';
105: 	return (line);
106: }
107: 
108: /**
109:  * @brief Tampondan döndürülen satırı temizler ve geri kalan veriyi döndürür.
110:  * 
111:  * @param buffer Veri tamponu.
112:  * @return Satırdan sonra kalan veri.
113:  */
114: char	*ft_getrest(char *buffer)
115: {
116: 	int		i;
117: 	int		j;
118: 	char	*restof;
119: 
120: 	i = 0;
121: 	while (buffer[i] && buffer[i] != '\n')
122: 		i++;
123: 	if (!buffer[i])
124: 	{
125: 		free(buffer);
126: 		return (NULL);
127: 	}
128: 	restof = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
129: 	if (!restof)
130: 		return (NULL);
131: 	i++;
132: 	j = 0;
133: 	while (buffer[i])
134: 		restof[j++] = buffer[i++];
135: 	restof[j] = '\0';
136: 	free(buffer);
137: 	return (restof);
138: }
