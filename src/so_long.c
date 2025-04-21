/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisan <keisan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:34:35 by flren             #+#    #+#             */
/*   Updated: 2025/04/22 01:47:16 by keisan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int    ac, char    **av)
{
    if (ac != 2)
        return (ft_putstr_fd("Invalid number of arguments\n", STDERR_FILENO), EXIT_FAILURE);
    ft_check_map();
}
