.PHONY : all clean fclean re
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
NAME = libftprintf.a

# DOSSIERS
P_INC = ./
P_SRC = ./
P_OBJ = .obj/
P_LIBFT = libft/
P_TEMP = temp/

# FICHIERS
INC = header.h
SRC =  ft_printf.c 
SRC_LIB = ft_putnbr_base.c ft_putstr_fd.c ft_strchr.c ft_strlen.c ft_convert_base.c

# MANIPULATION
SRCS =	$(addprefix $(P_SRC), $(SRC) $(SRC_LIB))

OBJS = $(subst $(P_SRC), $(P_OBJ), $(SRCS:.c=.o))

P_OBJS = $(subst $(P_SRC), $(P_OBJ), $(P_SRC)) 

# REGLES
all :$(NAME)

# Créer la bibliothèque avec les objets
# $(NAME): $(P_OBJ)$(OBJS) $(P_LIBFT)$(LIBFT)
# 	cp $(P_LIBFT)$(LIBFT) .
# 	ar -x libft.a
# 	mv *.o libft.a $(P_OBJ)
# 	ar -rcs $(NAME) $(P_OBJ)*.o

$(NAME): $(P_OBJ)$(OBJS)
	ar -rcs $(NAME) $(P_OBJ)*.o

$(P_OBJ)%.o : %.c | $(P_OBJS)
	$(CC) $(CFLAGS) -c $< -I $(P_INC) -o $@

$(P_OBJS) : 
	mkdir -p $(P_OBJS)

debug : *.c | $(P_OBJS)
	$(CC) $(CFLAGS) -g -c $< -I $(P_LIBFT) -I $(P_INC) -o $@
	ar -rcs $(NAME) $(OBJS) $(P_LIBFT)$(LIBFT)

# LIBFT
# $(LIBFT) : 
# 	@$(MAKE) --no-print-directory -C libft all

# NETTOYAGE
clean :
	rm -rfd $(P_OBJ)

fclean : clean
	rm -rf $(NAME)
	
# @$(MAKE) clean --no-print-directory
# @$(MAKE) -C $(P_LIBFT) fclean --no-print-directory
	



re : 
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all