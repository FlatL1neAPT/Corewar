/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:14:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/27 16:13:37 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

/*
**
** Instructions: Opcode 4. Take three registries, add the first two, and place
** the result in the third, right before modifying the carry.
**
*/

int		ft_is_reg(int r1, int r2, int r3)
{
	if (r1 < 0 || r1 > REG_SIZE ||
			r2 < 0 || r2 > REG_SIZE ||
				r3 < 0 || r3 > REG_SIZE)
		return (0);
	return (1);
}
void	ft_add(t_env *e, t_cursor *cursor)
{
	int			value1;
	int			value2;
	int			opc_ind;
	int			r1;
	int			r2;
	int			r3;

	opc_ind = cursor->index;
	r1 = e->a[MODA(opc_ind + 2)].hex;
	r2 = e->a[MODA(opc_ind + 3)].hex;
	r3 = e->a[MODA(opc_ind + 4)].hex;
	if (!ft_is_reg(r1, r2, r3))
	{
		cursor->index += 1;
		return ;
	}
	value1 = cursor->reg[r1];
	value2 = cursor->reg[r2];
	cursor->reg[r3] = value1 + value2;
	cursor->index += 5;
	cursor->carry = 1;
}
