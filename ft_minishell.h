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
int				ft_count_before(char *str, char c);

int				ft_env_check(char *w_splited);

char			*ft_tilda(char **env, char *word);
char			*ft_dollar(char **env, char *word);


char			*ft_home(char **env);
char			*ft_check(char *sentence, char *word, char c);

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
char			**ft_cd_one(char *w_splited, char **envp);
int				ft_parsed_cd(char *w_splited);
char			**ft_cd_two(char **w_splited, char **envp);
char			*ft_pwd0(char **envp, char *pwd);
char			*ft_look(char **envp, char *pwd, char *find);
int				ft_splited_parse(char **w_splited);

char			**ft_change_envp1(char **envp, char *home_path, char *cur_pwd, char *old_pwd);
char 			**ft_envp(char **envp, char *home_path, char *pwd);
void			ft_parse_env(char **w_splited, char **envp);
void			ft_print_without_env(char *w_splited, char **envp);
char			**ft_pwd(char **envp, char *word, char *pwd);
char			**ft_chdir(char **envp, char *w_splited, char *pwd);

char			**ft_setenv(char **w_splited, char **envp);
int				ft_parse_setenv(char *w_splited);
char			**ft_setenv_work(char *w_splited, char **envp);
int				ft_parse_name(char *name, char **envp);
char			**ft_edit_envp(char *new, char *w_splited, char **envp);
char			**ft_new_envp(char **envp, char *new);

char			**ft_unsetenv(char **w_splited, char **envp);
int				ft_parse_unset(char *w_splited);
char			**ft_unsetenv_work(char *w_splited, char **envp);
char			**ft_new_envp1(char **new_envp, char **envp, char *w_splited);

void			ft_echo(char **w_splited);
void			echo(char **str, int pos);
void			ft_putnstr(char *str, int n);

int				ft_if_path(char **command);
char			**ft_path(char **env);

void			ft_parse_error(void);
void			ft_command_not_found(char *command);
void			ft_wrong_quantity_env(void);
void			ft_opt_require_arg(char c);
void			ft_illegal_env_opt(char c);
void			ft_no_such_file_env_1(char *w_splited);
void			ft_permission_env(char *w_splited);
void			ft_no_such_file(char *w_splited);
void			ft_not_directory(char *w_splited);
void			ft_permission_denied(char *w_splited);
void			ft_not_set(char *word);
void			ft_not_in_cwd(char *w_splited);
void			ft_setenv_arg_error(void);
void			ft_setenv_parse_error(char *w_splited);
void			ft_setenv_overload(void);

void			free_2darray(char ***str);
void			free_2var(char *home_path, char *cur_pwd);
void			free_3var(char *var1, char *var2, char *var3);

#endif
