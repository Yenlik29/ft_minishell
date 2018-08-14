/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:51:58 by ybokina           #+#    #+#             */
/*   Updated: 2018/06/14 21:51:58 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <termcap.h>
# define IS_QUOTE(x) (x == '"' || x == '\'')

char			**split_word(char *word);
char			**read_line(char **env);
char			**str_split(char const *s, char c);
char			**parsed_word(char **word, char **env);
char			**ft_word(char **word, char **env);

int				ft_env_check(char *w_splited);

char			*ft_tilda(char **env, char *word);
char			*ft_dollar(char **env, char *word);


char			*ft_home(char **env);

size_t			word_count(char const *s, char c);
char			*ft_join_f2(char *s1, char *s2);
char			*ft_join_f(char *s1, char *s2);
int				len_env(char **envp);
int				ft_find(char **envp, char *word);

void			sighandler(int signum);

void			display_prompt(void);

char			**envp_create(char **env, char **envp);
char			*ft_environments(char *word, char **new, char **env);

char			**ft_core(char **w_splited, char **env);

void			ft_available_command(char **command, char **envp);

void			ft_exec_sys(char **path, char **command, char **envp);
char			**ft_exec_buil_in(char **w_splited, char **envp);
int				ft_check_build_in(char **w_splited);

char			**ft_cd(char **w_splited, char **envp);
char			**ft_only_cd(char **envp);

char			**ft_change_envp1(char **envp, char *home_path, char *cur_pwd);

int				ft_if_path(char **command);
char			**ft_path(char **env);

void			ft_parse_error(void);
void			ft_command_not_found(char *command);

void			free_2darray(char ***str);
void			free_2var(char *home_path, char *cur_pwd);

#endif
