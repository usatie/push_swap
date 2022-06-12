/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:44:44 by susami            #+#    #+#             */
/*   Updated: 2022/06/12 09:48:39 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

# include <stdarg.h>

int		ft_debug_vdprintf(int fd, const char *format, va_list ap);
int		ft_debug_vprintf(const char *format, va_list ap);
int		ft_debug_dprintf(int fd, const char *format, ...);
int		ft_debug_printf(const char *format, ...);

#endif
