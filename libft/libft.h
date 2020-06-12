/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 12:05:32 by rklein            #+#    #+#             */
/*   Updated: 2020/06/08 16:40:43 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_var
{
	char	sign;
	char	*flags;
	char	*fld_min;
	_Bool	dot;
	char	*prec;
	char	*type_spec;
	char	type;
	int		count;
}				t_var;

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
char			*ft_strcat(char *s1, const char *s2);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_strclr(char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_toupper(int c);

/*
** ft_printf prototypes
*/

int				ft_printf(const char *format, ...);
void			ft_double_print(t_var *id, va_list args);
char			*ft_ftoa(t_var *id, long double fl, int pr);
long double		ft_prep(t_var *id, long double fl, int pr);
void			ft_int_print(t_var *id, va_list args);
char			*ft_addsign(t_var *id, char *str);
char			*ft_s_itoa(t_var *id, intmax_t n);
void			ft_uint_print(t_var *id, va_list args);
char			*ft_spad_uint(t_var *id, char *str);
void			ft_base_print(t_var *id, va_list args);
char			*ft_base(uintmax_t value, t_var *id);
char			*ft_itoa_base(uintmax_t value, int base);
void			ft_addr_print(t_var *id, va_list args);
char			*ft_zpad_uint(t_var *id, int size);
void			ft_char_print(t_var *id, va_list args);
int				ft_strchr_int(char *s, int c);
char			*ft_double_flags(t_var *id, char *str);
char			*ft_int_flags(t_var *id, char *str);
char			*ft_strmake(char c, int size);
char			*ft_spacepad(t_var *id, char *str);
char			*ft_uint_flags(t_var *id, char *str);
void			ft_e_print(t_var *id, va_list args);
char			*ft_enum(t_var *id, long double f);
char			*ft_suffix(char type, char sign, int e);
void			ft_g_print(t_var *id, va_list args);
char			*ft_cut_zero(char *str);
t_var			*ft_idalloc(void);
void			ft_reset(t_var *id);
void			ft_free_str(char **str, int s);
int				ft_free_id(t_var *id);
int				ft_is_flag(char c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);

#endif
