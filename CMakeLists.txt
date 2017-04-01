cmake_minimum_required(VERSION 3.6)
project(ft_printf_c_lion_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ft_printf.c identify_specificator.c init_flags_with_spec.c init_other_flags.c initialize.c other_flags.c fill_s.c my_itoa_base.c functions.c ft_atoi.c ft_memalloc.c ft_putstr.c ft_strcat.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c ft_strncpy.c ft_putchar.c ft_strchr.c ft_memset.c ft_strnew.c ft_strchr.c my_unsigned_itoa_base.c ft_strrev.c ft_uppercase.c type_p.c type_c.c type_s.c type_wchar.c bits_help.c type_d.c type_o.c type_u.c type_x.c write_char.c ft_strstr.c moulitest.c)
add_executable(ft_printf_c_lion_ ${SOURCE_FILES})