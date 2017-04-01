/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:26:30 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/30 17:30:30 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPEC "sSpdDioOuUxXcC"
# define MODIF "hljz"
# define FLAGS "#0-+ "

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

typedef struct	s_var
{
	int			sharp;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			spec_hh;
	int			spec_h;
	int			spec_l;
	int			spec_ll;
	int			spec_j;
	int			spec_z;
	char		*s;
	int			global_len;
}				t_var;

int				ft_printf(const char *ac, ...);
void			init_all(t_var *var);
int				find_types(char *format);
int				is_specificator(char c);
int				is_flags(char c);
int				is_modif(char c);
char			*init_other_flags(char *format, t_var *var);
char			*init_flags_with_spec(char *format, va_list *ap, t_var *var);
char			*init_width(char *format, t_var *var);
char			*init_precision(char *format, t_var *var);
void			init_flags(char c, t_var *var);
void			init_modif(char *s, t_var *var);
void			identify_specificator(char type, va_list *ap, t_var *var);
int				type_d(va_list *ap, t_var *var);
int				type_u(va_list *ap, t_var *var);
int				type_x(va_list *ap, t_var *var, int flag);
int				type_o(va_list *ap, t_var *var);
int				type_p(va_list *ap, t_var *var);
int				type_c(va_list *ap, t_var *var);
int				type_s(va_list *ap, t_var *var);
int				type_wchar(va_list *ap, t_var *var, int x, int y);
int				write_char(t_var *var, char c);
char			*bits_help_1(char *s, wint_t *i, int *x, int *y);
char			*bits_help_2(char *s, wint_t *i, int *x, int *y);
char			*bits_help_3(char *s, wint_t *i, int *x, int *y);
char			*ft_del_minus(char *s);
char			*my_itoa_base(intmax_t n, int base);
char			*my_unsigned_itoa_base(uintmax_t n, int base);
char			*fillstring(char *s, t_var *var);
char			*fillstring_c(char *s, t_var *var);
char			*ft_function_1(char *s, t_var *var);
char			*ft_function_2(char *s, t_var *var, long long value);
void			*ft_memalloc(size_t size);
int				ft_atoi(const char *str);
void			*ft_memset(void *dest, int c, size_t len);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
char			*ft_strcat(char *dest, const char *append);
char			*ft_strncat(char *dest, const char *append, size_t len);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strrev(char *str);
char			*ft_uppercase(char *s);
int				ft_find(char *s, char *c);
char			*ft_strchr(const char *str, int c);

#endif
