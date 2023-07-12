#ifndef MINI_H
#define	MINI_H

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DELIMS " \t\r\n"
#define READ 0
#define WRITE 1
#define ERROR -1

enum    e_type
{
    T_WORD,
    T_PIPE,
    T_REDIRECT,
    T_DOUBLE_Q,
    T_SINGLE_Q,
    T_SPACE // 추후에 고려해보기
};

typedef struct  s_token
{
    int     type;
    char    *str;
    int     double_flag;
    int     single_flag;
}   t_token; 


typedef struct s_list
{
    struct  s_list *next;
	struct  s_list *pre;
    t_token *token;
    // void    *content;
    char    *env;
}				t_list;


typedef struct s_mini
{
	int     infile;
    int     outfile;
    char    **env;
    
}				t_mini;

typedef struct s_data
{
	char		*input;
	t_list		*tokens;
	t_list		*envs;
    // struct  s_data *next;
}	t_data;


/*ft.c*/
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strncat(char *dest, char *src, int n);
t_list	*ft_lst_new(void *content);
// t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
size_t	ft_strlen(const	char *str);
void	*ft_memset(void *b, int c, size_t len);
int	    ft_lstsize(t_list *lst);
t_list	*ft_lstnews();
t_data *new_data();
void    get_envp(t_data *data);
void	env_init(t_data *data, char **env);
void del_envp(t_data *data, char *key);
t_list    *find_envp(t_data *data, char *key);



int	ft_strncmp(const char *s1, const char *s2, size_t n);
/* minishell.c*/
// t_token     *new_token();
void    addttlist(t_list **head, t_token *token);
void    tokenization(char *str, int *idx, t_list **head, t_token **token);
t_list *lexer(t_list *list, char *str);

/* quote.c */
void    double_quotes(t_list **list, t_token **token, char *str, int *idx);
void    single_quotes(t_list **list, t_token **token, char *str, int *idx);
bool    find_quote(int i, char *str, char quote);
void	env_init(t_data *data, char **env);
/* bonus */
/* gnl */
int		ft_strchr(char *str, int c);
// char	*ft_substr(char const *s, int start, int len);
char	*data_join(char **data, char *buf);
char	*setting_data(char *str);
char	*devide_line(char **data, int idx);
char	*size_is_zero(char **data, int idx);
char	*read_buf(int fd, char **data, char *buf, int size);
char	*get_next_line(int fd);
/* pipe_bonus */
void	read_gnl(t_mini *pp);
void	fileinit_bonus(int ac, char **av, t_mini *pp);


#endif 