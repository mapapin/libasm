/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mapapin@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:19:01 by user42            #+#    #+#             */
/*   Updated: 2020/12/13 21:52:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define CYA "\x1B[36m"
# define WHT "\x1B[0m"


size_t	ft_strlen(const char *s);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char	*ft_strcpy(char *dst,const char *src);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

void	ft_cpy(void)
{
	char dest[500];

	printf("%sft_strcpy :\n\n%s", GRN, YEL);
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, "HELLO"));
	printf("   strcpy = |%s|\n\n", strcpy(dest, "HELLO"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, "Bonjour le monde !"));
	printf("   strcpy = |%s|\n\n", strcpy(dest, "Bonjour le monde !"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, "#42MAISON"));
	printf("   strcpy = |%s|\n\n", strcpy(dest, "#42MAISON"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, "vide"));
	printf("   strcpy = |%s|\n\n", strcpy(dest, "vide"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, ""));
	printf("   strcpy = |%s|\n\n", strcpy(dest, ""));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, "abc"));
	printf("   strcpy = |%s|\n\n", strcpy(dest, "abc"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, "asl;fjl;asdjfjkasdl;fjadjsf"));
	printf("   strcpy = |%s|\n\n", strcpy(dest, "asl;fjl;asdjfjkasdl;fjadjsf"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, "yope\0la"));
	printf("   strcpy = |%s|\n\n", strcpy(dest, "yope\0la"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, "Lorem ipsum\fdolor\vsit"));
	printf("   strcpy = |%s|\n\n", strcpy(dest, "Lorem ipsum\fdolor\vsit"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcpy = |%s|\n", ft_strcpy(dest, "\x00\x01\x02\x03\x04\x05"));
	printf("   strcpy = |%s|\n\n%s", strcpy(dest, "\x00\x01\x02\x03\x04\x05"), WHT);
}

void	ft__read(void)
{
	char	buffer[100];
	int		fd;

	printf("%sft_read :\n\n%s", GRN, YEL);
	errno = 0;
	fd = -1;
	printf("%s---\n%s", CYA, YEL);
	printf("ft_read = |%ld| errno = %d\n", ft_read(fd, buffer, 8), errno);
	errno = 0;
	printf("   read = |%ld| errno = %d\n\n", read(fd, buffer, 8), errno);
	errno = 0;
	fd = open("read_file1.txt", O_RDONLY);
	printf("%s---\n%s", CYA, YEL);
	printf("ft_read = |%ld| errno = %d\n", ft_read(fd, buffer, 8), errno);
	close(fd);
	errno = 0;
	fd = open("read_file1.txt", O_RDONLY);
	printf("   read = |%ld| errno = %d\n\n", read(fd, buffer, 8), errno);
	printf("%s---\n%s", CYA, YEL);
	errno = 0;
	fd = open("read_file2.txt", O_RDONLY);
	printf("ft_read = |%ld| errno = %d\n", ft_read(fd, buffer, 8), errno);
	close(fd);
	errno = 0;
	fd = open("read_file2.txt", O_RDONLY);
	printf("   read = |%ld| errno = %d\n\n", read(fd, buffer, 8), errno);
	printf("%s---\n%s", CYA, YEL);
	close(fd);
	errno = 0;
	fd = 450;
	printf("ft_read = |%ld| errno = %d\n", ft_read(fd, buffer, 8), errno);
	errno = 0;
	printf("   read = |%ld| errno = %d\n\n%s", read(fd, buffer, 8), errno, WHT);
	close(fd);
}

void	ft_dup(void)
{
	char *dst;

	dst = NULL;
	printf("%sft_strdup :\n\n%s", GRN, YEL);
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strdup = |%s|\n", dst = ft_strdup("Bonjour"));
	free(dst);
	printf("   strdup = |%s|\n\n", (dst = strdup("Bonjour")));
	free(dst);
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strdup = |%s|\n", dst = ft_strdup("Hello"));
	free(dst);
	printf("   strdup = |%s|\n\n", (dst = strdup("Hello")));
	free(dst);
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strdup = |%s|\n", (dst = ft_strdup("asl;fjl;asdjfjkasdl;fjadjsf")));
	free(dst);
	printf("   strdup = |%s|\n\n", (dst = strdup("asl;fjl;asdjfjkasdl;fjadjsf")));
	free(dst);
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strdup = |%s|\n", (dst = ft_strdup("42atom\0maison")));
	free(dst);
	printf("   strdup = |%s|\n\n", (dst = strdup("42atom\0maison")));
	free(dst);
}

void	ft_len(void)
{
	printf("%sft_strlen :\n\n", GRN);
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strlen = |%zd|\n", ft_strlen("hello"));
	printf("   strlen = |%zd|\n\n", strlen("hello"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strlen = |%zd|\n", ft_strlen("hello_world !"));
	printf("   strlen = |%zd|\n\n", strlen("hello_world !"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strlen = |%zd|\n", ft_strlen("#stayathome"));
	printf("   strlen = |%zd|\n\n", strlen("#stayathome"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strlen = |%zd|\n", ft_strlen("#42atom"));
	printf("   strlen = |%zd|\n\n", strlen("#42atom"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strlen = |%zd|\n", ft_strlen(""));
	printf("   strlen = |%zd|\n\n", strlen(""));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strlen = |%zd|\n", ft_strlen("\n"));
	printf("   strlen = |%zd|\n\n", strlen("\n"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strlen = |%zd|\n", ft_strlen("asdfasdf''///##!!@"));
	printf("   strlen = |%zd|\n\n", strlen("asdfasdf''///##!!@"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strlen = |%zd|\n", ft_strlen("the\0hidden"));
	printf("   strlen = |%zd|\n\n", strlen("the\0hidden"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strlen = |%zd|\n", ft_strlen("Lorem \bipsum\vdollar"));
	printf("   strlen = |%zd|\n\n", strlen("Lorem \bipsum\vdollar"));
}

void	ft_cmp(void)
{
	printf("%sft_strcmp :\n\n", GRN);
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("hello", "hello"));
	printf("   strcmp = |%d|\n\n", strcmp("hello", "hello"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("hello", "HELLA"));
	printf("   strcmp = |%d|\n\n", strcmp("hello", "HELLA"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("hello_world !", "Bonjour le monde !"));
	printf("   strcmp = |%d|\n\n", strcmp("hello_world !", "Bonjour le monde !"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("stayathome", "#restezchezvous"));
	printf("   strcmp = |%d|\n\n", strcmp("#stayathome", "#resterchezvous"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("Hi", "Hi"));
	printf("   strcmp = |%d|\n\n", strcmp("HI", "HI"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("#42atom", "#42aAISON"));
	printf("   strcmp = |%d|\n\n", strcmp("#42atom", "#42MAISON"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("", "vide"));
	printf("   strcmp = |%d|\n\n", strcmp("", "vide"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("\n", "rien"));
	printf("   strcmp = |%d|\n\n", strcmp("\n", "rien"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("the\0hidden", "thehidden"));
	printf("   strcmp = |%d|\n\n", strcmp("the\0hidden", "thehidden"));
	printf("%s---\n%s", CYA, YEL);
	printf("ft_strcmp = |%d|\n", ft_strcmp("asdklfjasdfj////asdf'''asdf3##",
				"asdklfjasdfj////asdf'''asdf3##"));
	printf("   strcmp = |%d|\n\n", strcmp("asdklfjasdfj////asdf'''asdf3##",
				"asdklfjasdfj////asdf'''asdf3##"));
}

void	ft__write(void)
{
	int fd;

	fd = 1;
	errno = 0;
	printf("%sft_write :\n\n", GRN);
	printf("%s---\n%s", CYA, YEL);
	printf("ft_write = %ld errno = %d\n", ft_write(5000, "hello world", 11), errno);
	errno = 0;
	printf("   write = %ld errno = %d\n\n", write(5000, "hello world", 11), errno);
	printf("%s---\n%s", CYA, YEL);
	errno = 0;
	printf("ft_write = %ld errno = %d\n", ft_write(fd, "hi", 2), errno);
	errno = 0;
	printf("   write = %ld errno = %d\n\n", write(fd, "hi", 2), errno);
	printf("%s---\n%s", CYA, YEL);
	errno = 0;
	printf("ft_write = %ld errno = %d\n", ft_write(50000, "hola, como estas ?", 18),
			errno);
	errno = 0;
	printf("   write = %ld errno = %d\n\n", write(50000, "hola, como estas ?", 18),
			errno);
	printf("%s---\n%s", CYA, YEL);
	errno = 0;
	printf("ft_write = %ld errno = %d\n", ft_write(fd, "welcome hi", 9), errno);
	errno = 0;
	printf("   write = %ld errno = %d\n\n", write(fd, "welcome hi", 9), errno);
}

int		main(void)
{
	ft_len();
	getchar();
	ft_cmp();
	getchar();
	ft__write();
	getchar();
	ft__read();
	getchar();
	ft_cpy();
	getchar();
	ft_dup();
	return (0);
}
