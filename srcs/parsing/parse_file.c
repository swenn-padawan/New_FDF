#include "fdf.h"
#include <ctype.h>

# define HEX "0123456789abcdef"


char	*get_file(char *map){
	int			map_fd;
	off_t		file_size;
	struct stat	file_info = {0};
	char		*buffer;

	map_fd = open(map, O_RDONLY);
	if (map_fd == -1) exit(1);
	if (fstat(map_fd, &file_info) == -1) exit(-1);
	file_size = file_info.st_size;
	buffer = malloc(file_size * sizeof(char) + 1);
	if (read(map_fd, buffer, file_size) == -1) {
		free(buffer);
		exit (READ_FAILED);
	}
	return (buffer);
}

static int	fdf_bufferhex(char *buffer, char **remain)
{
	int		nb;
	char	*index;

	nb = 0;
	if (buffer[0] != '0' || !buffer[1] || (buffer[1] | 32) != 'x')
		return (0);
	buffer += 2;
	while (*buffer && buffer != (*remain + 10))
	{
		index = ft_strchr(HEX, (*buffer | ((*buffer - 'A' < 6) * 32)));
		if (!index)
			break ;
		if (*buffer >= '0' && *buffer <= '9')
			nb = (nb << 4) + (*buffer - '0');
		else if (*buffer >= 'a' && *buffer <= 'f')
			nb = (nb << 4) + (*buffer - 'a' + 10);
		else if (*buffer >= 'A' && *buffer <= 'F')
			nb = (nb << 4) + (*buffer - 'A' + 10);
		buffer++;
	}
	if (remain)
		*remain = buffer;
	return (nb);
}

int	ft_strtoi(char *buffer, char **remain, uint8_t base){
	int	n;
	int	sign;

	n = 0;
	if (base == 16)
		return (fdf_bufferhex(buffer, remain));
	sign = (*buffer == '-');
	if (sign) sign *= -1;
	if (*buffer == '-' || *buffer == '+')
		buffer++;
	while (ft_isdigit(*buffer)){
		n = n * 10 + *buffer - '0';
		buffer++;
	}
	if (remain)
		*remain = buffer;
	return (n * sign);
}

static int	fdf_parse_col_row(t_data *data, char *buffer, char **remain)
{
	while (*buffer && (*buffer - 9 < 5 || *buffer == 32))
	{
		if (*buffer == '\n')
		{
			data->nb_rows++;
			if (!data->nb_cols)
				data->nb_cols = data->parse_index;
			if (data->parse_index % data->nb_cols)
				return (6);
		}
		buffer++;
	}
	if (remain)
		*remain = buffer;
	return (0);
}

int	fdf_parse_map(t_data *data, char *buffer, char **remain){
	int	n;

	while (*buffer && isspace(*buffer))
		buffer++;
	if (!*buffer)
		return (1);
	n = ft_strtoi(buffer, &buffer, 10);
	data->data[data->parse_index] = n;
	if (*buffer == ','){
		buffer++;
		n = ft_strtoi(buffer, &buffer, 16);
		//error
		data->colors[data->parse_index].rgba = (uint32_t)n;
	}
	data->parse_index++;
	fdf_parse_col_row(data, buffer, remain);
	return (0);
}

t_data	*fdf_fill_data(char *buffer){
	t_data	*data = {0};
	char	*base_buffer;

	data = malloc(sizeof(int) * BUFFER_SIZE);
	base_buffer = buffer;
	if (fdf_parse_map(data, buffer, &buffer)){
		free(base_buffer);
		return (NULL);
	}
	return (data);
}





