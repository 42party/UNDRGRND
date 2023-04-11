/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:56:30 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/09 18:02:04 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// colocar isso em uma pasta que fizer sentido

#include "../header/cub3d.h"

int	lines_counter(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	collumns_counter(char **map) // nas colunas vou pegar a maior coluna pq o mapa não necessariamente é um retangulo.
								// ou a gente fila tudo com espaço em branco e deixa ele sempre um quadrado. q eu acho q é melhor, mais ainda vai precisar da maior linha pra saber.
{
	int	j;
	int	i;
	int bigger_line; // the bigger line have more collums

	i = 0;
	j = 0;
	bigger_line = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		i++;
		if (j > bigger_line)
			bigger_line = j;
		j = 0;
	}
	return (bigger_line);
}

void	load_game(t_window *win)
{
//	int	lines;
//	int	collumns;
	(void)win;

//	lines = lines_counter((char **)map);
//	collumns = collumns_counter((char **)map);
//	printf("lines %i\n", lines);
//	printf("cols %i\n", collumns);
//	get_player_possition((char **)map, lines);
}
