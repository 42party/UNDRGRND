/* static int verify_content(char *line, int count)
{
	int i;


	i = 0;

	while(line[i] && line[i] == 10)
	{
		if (line[i] && line[i] == 32)
			i++;
		else if (line[i] && (line[i] == '1' || line[i] == '0'))
			i++;
		else if(line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			count--;

	}

	return (0);
}

static int check_map_x_y(int fd)
{
	char	*temp_map_line;
	int		lines;
	int		count;

	lines = 0;
	count = 1;
	temp_map_line = get_next_line(fd);
	while (temp_map_line)
	{
		if (verify_content(temp_map_line, count))
			return(ret_value(1, "Only 1, 0, N, S, W, E or Spaces"));
		free(temp_map_line);
		temp_map_line = get_next_line(fd);
		lines++;
	}
	if (count != 0)
		return(ret_value(1, "Cannot put more than one position"));

	return (0);
}

//fechar fd nos returns
// free em cada gnl */
