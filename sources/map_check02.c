/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:16:17 by jlarue            #+#    #+#             */
/*   Updated: 2023/11/29 15:46:13 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_next_char_line(char **map, int i, int j)
{
	if (!map[i][j + 1] || (map[i][j] == '1' && map[i][j + 1] == '\n'))
		return (FALSE);
	else if ((map[i][j] == ' ' || map[i][j] == '	') &&
			map[i][j + 1] != ' ' && map[i][j + 1] != '	' &&
			map[i][j + 1] != '1')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), TRUE);
	else if (map[i][j] == '1' && map[i][j + 1] != ' '
		&& map[i][j + 1] != '	' && map[i][j + 1] != '1'
		&& map[i][j + 1] != 'N' && map[i][j + 1] != 'E' && map[i][j + 1] != 'S'
		&& map[i][j + 1] != 'W' && map[i][j + 1] != '0')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), TRUE);
	else if ((map[i][j] == '0') && map[i][j + 1] != '1'
		&& map[i][j + 1] != 'N' && map[i][j + 1] != 'E' && map[i][j + 1] != 'S'
		&& map[i][j + 1] != 'W' && map[i][j + 1] != '0')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), TRUE);
	else if ((map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
		map[i][j + 1] == 'W') && map[i][j + 1] != '0'
		&& map[i][j + 1] != '1')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), TRUE);
	else
		return (FALSE);
}

bool	check_prev_char_line(char **map, int i, int j)
{
	if (j == 0 || !map[i][j - 1])
		return (FALSE);
	else if ((map[i][j] == ' ' || map[i][j] == '	')
			&& map[i][j - 1] != ' '
			&& map[i][j - 1] != '	' && map[i][j - 1] != '1')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), TRUE);
	else if (map[i][j] == '1' && map[i][j - 1] != ' '
		&& map[i][j - 1] != '	' && map[i][j - 1] != '1'
		&& map[i][j - 1] != 'N' && map[i][j - 1] != 'E' && map[i][j - 1] != 'S'
		&& map[i][j - 1] != 'W' && map[i][j - 1] != '0')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), TRUE);
	else if ((map[i][j] == '0' || map[i][j] == '2') && map[i][j - 1] != '1'
		&& map[i][j - 1] != 'N' && map[i][j - 1] != 'E' && map[i][j - 1] != 'S'
		&& map[i][j - 1] != 'W' && map[i][j - 1] != '0')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), TRUE);
	else if ((map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
		map[i][j - 1] == 'W') && map[i][j - 1] != '0'
		&& map[i][j - 1] != '1')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), TRUE);
	else
		return (FALSE);
}

bool	check_next_char_col(char **map, int i, int j)
{
	if (!map[i + 1] || !map[i + 1][j])
		return (FALSE);
	else if ((map[i][j] == ' ' || map[i][j] == '	') && map[i + 1][j] == '0')
		return (printf("Error\nCol %d line %d\n", j, i), TRUE);
	else if (map[i][j] == '1')
		return (FALSE);
	else if ((map[i][j] == '0' || map[i][j] == '2')
		&& map[i + 1][j] != '1' && map[i + 1][j] != '0'
			&& map[i + 1][j] != 'N' && map[i + 1][j] != 'W'
			&& map[i + 1][j] != 'S' && map[i + 1][j] != 'E')
		return (printf("Error\nCol %d line %d\n", j, i), TRUE);
	else if ((map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
		map[i + 1][j] == 'W') && map[i + 1][j] != '1'
			&& map[i + 1][j] != '0')
		return (printf("Error\nCol %d line %d\n", j, i), TRUE);
	else
		return (FALSE);
}

int	check_prevline(char **map, int i, int j)
{
	int	iterator;

	iterator = 0;
	if (i == 0)
		return (0);
	while (iterator <= j)
	{
		if (map[i][iterator] == 0)
			return (1);
		iterator++;
	}
	return (0);
}

bool	check_prev_char_col(char **map, int i, int j)
{
	int	check_eol;

	check_eol = check_prevline(map, i - 1, j);
	if ((i == 0 && map[i][j] != '1' && map[i][j] != '\n'))
		return (printf("Error\nCol %d line %d\n", j, i), TRUE);
	else if ((i == 0 || !map[i - 1][j]) && map[i][j] == '1')
		return (FALSE);
	else if ((map[i][j] == ' ' || map[i][j] == '	') && map[i - 1][j] == '0')
		return (printf("11Error\nCol %d line %d\n", j, i), TRUE);
	else if (map[i][j] == '1')
		return (0);
	else if ((map[i][j] == '0' || map[i][j] == '2')
		&& map[i - 1][j] != '1' && map[i - 1][j] != '0'
			&& map[i - 1][j] != 'N' && map[i - 1][j] != 'W'
			&& map[i - 1][j] != 'S' && map[i - 1][j] != 'E')
		return (printf("12Error\nCol %d line %d\n", j, i), TRUE);
	else if ((map[i][j] == '0') && check_eol == 1)
		return (printf("14Error\nCol %d line %d\n", j, i), TRUE);
	else if ((map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
		map[i - 1][j] == 'W') && map[i - 1][j] != '1'
			&& map[i - 1][j] != '0')
		return (printf("13Error\nCol %d line %d\n", j, i), TRUE);
	else
		return (FALSE);
}
