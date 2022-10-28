/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:10:34 by ykot              #+#    #+#             */
/*   Updated: 2022/10/14 12:33:43 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define BUFF_SIZE 10000
# define TRUE 1
# define FALSE 0
# define FD_MAX	4096
# define HASH 1109

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct s_dblist
{
	void			*content;
	size_t			content_size;
	struct s_dblist	*next;
	struct s_dblist	*prev;
}				t_dblist;

typedef struct s_dynlist
{
	t_dblist	*head;
	t_dblist	*tail;
	size_t		size;
}				t_dynlist;

typedef struct s_hash
{
	char	*name;
	void	*ptr;
}			t_hash;

/*
**	String manipulation
*/

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, \
							size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_strtoup(char *str);
void			ft_strrev(char *str);
int				ft_char_count(char *line, char c);

/*
**	Memory
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
**	FD
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				get_next_line(const int fd, char **line);

/*
**	Char
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	Lists
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstappend(t_list **begin_list, t_list *lstnew);
t_list			*ft_lstelem(t_list **begin_list, size_t	elem);
size_t			ft_lstsize(t_list *begin_list);
void			ft_lstdelelem(t_list **lst, size_t elem, \
							void (*del)(void *, size_t));
void			ft_lstaddelem(t_list **alst, t_list *new, size_t pos);
t_list			*ft_lstnewptr(void *content);

/*
**	Dynamic lists (double lists)
*/

void			ft_dblstdel(t_dynlist *alst, void (*del)(void *));
void			ft_dblstdelone(t_dblist **alst, void (*del)(void*));
t_dblist		*ft_dblstnew(void const *content, size_t content_size);
void			ft_dynlstadd(t_dynlist *alst, t_dblist *new);
void			ft_dynlstappend(t_dynlist *alst, t_dblist *new);
void			ft_dynlstdelelem(t_dynlist *alst, size_t elem, \
							void (*del)(void *));
t_dblist		*ft_dynlstelem(t_dynlist alst, size_t elem);
t_dblist		*ft_dblstnew_pointer(void *content);

/*
**	Display output
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putllnbr(long long n);
int				ft_printf(const char *str, ...);

/*
**	Hashmap
*/

unsigned long	ft_hash_key(const char *s, unsigned long m);
void			*ft_hash_get(t_list **hashmap, char *str);
int				ft_hash_set(t_list **hashmap, char *str, void *ptr);
int				ft_hash_isin(t_list **hashmap, char *str);
void			ft_hash_free(t_list **hashmap);

/*
** Other
*/

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_numdig(long long num, int base);
int				ft_numundig(unsigned long long num, int base);
char			*ft_demtobase(unsigned long long num, int base);
long long		ft_bigger(long long a, long long b);
long double		ft_pow(long double base, int exp);
int				ft_isint(const char *str);

#endif
