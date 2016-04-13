/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman, ghavnga <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:05:22 by khansman          #+#    #+#             */
/*   Updated: 2016/02/13 13:42:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
	int     k;

//log usage
	k = 1;
	if (argc > k)
	{
		while (argv[k])
		{
			solve_map(read_map(argv[k]));
			k++;
		}
	}
	else
	{
		//read in map from the standard input
	}
}

int read_map(char *file_name)
{
	int     fd;

	fd = open(file_name, O_RDONLY);
	return(fd);
	//close(fd); //dont forget
}

void solve_map(int fd)
{
}
