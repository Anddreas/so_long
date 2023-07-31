/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:14:02 by handrias          #+#    #+#             */
/*   Updated: 2023/07/31 13:14:04 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>

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
int		ft_strlen1(char *str);
int		ft_strstr(char *str, char *to_find);
int		check_ber(char **argv, t_list *game);
int		matrix_rows(char **arr);
int		matrix_column(char **arr);
char	*process_file(int a, t_list *game);
char	**check(char *q, t_list *game);
void	check_row(char **arr);
void	check_column(char **arr);
void	check_utils(char **arr, t_list *game);
void	check_symbols(char **arr, int *hasE, int *hasP, int *hasC);
void	check_missing_symbols(int hasE, int hasP, int hasC);
void	check_utils2(char **arr);
void	check_symbols(char **arr, int *hasE, int *hasP, int *hasC);
// void	check_missing_symbols(int hasE, int hasP, int hasC);
char	**ft_strdup_matrix(const char **matrix, int rows, int cols);
char	*ft_strdup2(const char *s1);
size_t	ft_strlcpy2(char *dst, const char *src, size_t size);
int		ft_strlen1(char *str);
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
void	go_up(int key, t_list *game);
void	go_down(int key, t_list *game);
void	go_left(int key, t_list *game);
void	go_right(int key, t_list *game);
int		move_p(int key, t_list *game);
int		ft_exit(t_list *game);
void	check_door(t_list *game);
void	c_exit(t_list *game);
void	flood_fill(t_list *game, char **map, int x, int y);
int		logic(t_list *game);
void	check_missing_symbols(int hasE, int hasP, int hasC);
void	count_coins(char **arr, t_list *game);
void	img(t_list *game);
void	last_check(t_list *game);

#endif
