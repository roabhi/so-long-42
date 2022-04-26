/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:43:20 by rabril-h          #+#    #+#             */
/*   Updated: 2022/04/26 18:58:06 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int i, char **params)
{
	(void)params;
	printf("el numero de params es %d y la longitud de la entrada es %d", i, (int)ft_strlen(params[1]));
}
