	#ifndef SO_LONG_H
	# define SO_LONG_H
	
	# include "gnl/get_next_line.h"
	# include <mlx.h>
	# include <stdio.h>
	# include <unistd.h>
	# include <stdlib.h>
	# include <fcntl.h>

	// # define SIZE 32
	// # define COLORS "RBKOGYP"

	typedef struct s_list
	{
		char		*res;
		char		*q;
		char		**arr;
		void		*mlx;
		void		*wall_img;
		void		*exit1;
		void		*exit2;
		void		*player_img;
		void		*coin_img;
		void		*open_door_img;
		void		*close_door_img;
		void		*win;
		void		*mlx_win;
		void		*background;
		void		*bord;
		void		*coin1;
		int			fd;
		int			steps;
		int			i;
		int			b;
		int			a;
		int			j;
		int			x;
		int			y;
		int			k;
		int			h;
		int			coins;
		int			width;
		int			height;
	}	t_list;
	
	int ft_strlen1(char *str);
	char	*ft_itoa(int n);
	void	width(char **map, t_list *game);
	void	height(char **map, t_list *game);
	char	*ft_strjoin_1(char const *s1, char const *s2);
	char	**ft_split(char const *s, char c);
	void	*ft_memcpy(void *dst, const void *src, size_t n);
	int		ft_strncmp(const char *s1, const char *s2, size_t n);
	char	*ft_strrchr(const char *s, int c);
	// int		*ft_atoi(const char *str);
	char	*ft_strtrim(char const *s1, char const *set);
	#endif
