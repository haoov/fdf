NAME= fdf
CC= cc
CFLAGS= -Wall -Wextra -Werror
LIBFTDIR= ./lib/libft
LIBFTHDIR= $(LIBFTDIR)/header
MLXDIR= ./lib/minilibx
LIBFLAGS= -L $(MLXDIR) -lm -lmlx -lXext -lX11
SRCDIR= ./srcs
HDIR= ./inc
LIBFT= $(LIBFTDIR)/libft.a
SRCS=	$(SRCDIR)/main.c\
		$(SRCDIR)/init/init.c\
		$(SRCDIR)/init/init_matrix.c\
		$(SRCDIR)/init/init_proj.c\
		$(SRCDIR)/parsing/parse.c\
		$(SRCDIR)/parsing/check.c\
		$(SRCDIR)/parsing/parse_color.c\
		$(SRCDIR)/parsing/parse_corners.c\
		$(SRCDIR)/mlx/start.c\
		$(SRCDIR)/mlx/new_image.c\
		$(SRCDIR)/mlx/key_action.c\
		$(SRCDIR)/mlx/mouse_action.c\
		$(SRCDIR)/map/zoom_in.c\
		$(SRCDIR)/map/zoom_out.c\
		$(SRCDIR)/math/translation_matrix.c\
		$(SRCDIR)/math/scaling_matrix.c\
		$(SRCDIR)/math/rotation_matrix.c\
		$(SRCDIR)/math/projection_matrix.c\
		$(SRCDIR)/math/apply_matrix.c\
		$(SRCDIR)/math/combine_matrix.c\
		$(SRCDIR)/math/max.c\
		$(SRCDIR)/colors/rgb.c\
		$(SRCDIR)/colors/get_color.c\
		$(SRCDIR)/colors/apply_theme.c\
		$(SRCDIR)/colors/change_theme.c\
		$(SRCDIR)/geometry/isometric.c\
		$(SRCDIR)/geometry/parallel.c\
		$(SRCDIR)/geometry/mvp.c\
		$(SRCDIR)/display/display.c\
		$(SRCDIR)/display/draw.c\
		$(SRCDIR)/display/draw_pixel.c\
		$(SRCDIR)/display/draw_line.c\
		$(SRCDIR)/display/draw_side.c\
		$(SRCDIR)/display/draw_menu.c\
		$(SRCDIR)/exit/free_tab.c\
		$(SRCDIR)/exit/exit_prg.c\
		$(SRCDIR)/exit/leave.c\
		$(SRCDIR)/utils/get_index.c\
		$(SRCDIR)/utils/inside_window.c\
		$(SRCDIR)/utils/update_angle.c\
		$(SRCDIR)/utils/get_next_line_mod.c
HD=		$(HDIR)/fdf.h\
		$(HDIR)/fdf_struct.h\
		$(HDIR)/fdf_colors.h
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -I $(MLXDIR) -I $(LIBFTHDIR) -I $(HDIR) $(OBJS) $(LIBFT) $(LIBFLAGS) -o $@

%.o:%.c $(HD)
	$(CC) $(CFLAGS) -I $(MLXDIR) -I $(LIBFTHDIR) -I $(HDIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re