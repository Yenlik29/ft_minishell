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

void			sighandler(int signum);

void			display_prompt(void);

char			**envp_create(char **env, char **envp);
char			*ft_environments(char *word, char **new, char **env);

#endif
