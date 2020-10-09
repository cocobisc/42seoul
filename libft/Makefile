# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youpark <youpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 16:40:41 by youpark           #+#    #+#              #
#    Updated: 2020/10/09 16:43:38 by youpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
SRCDIR = srcs
OBJDIR = objs
INCDIR = includes
OUTDIR = .
CFLAGS = -c -Wall -Wextra -Werror#-g
NAME = libft.a
OS = $(shell uname)
NORM = $(shell find /usr ~ -name 'norminette*' 2>/dev/null | head -1)

$(shell mkdir -p $(OBJDIR))

$(NAME): all
$(OBJDIR)/%.o: $(SRCDIR)/%.c
    $(CC) $< $(CFLAGS) -o $@ -I $(INCDIR)

all: $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
    ar -rcs $(OUTDIR)/$(NAME) $^
clean:
    rm -rf $(OUTDIR)/$(NAME)
fclean: clean
    rm -rf $(OBJDIR)/*.o
re: fclean
    make all
bonus: all
norm:
    @if [ -z $(NORM) ]; then\
        echo "[-] No norminette T.T";\
    else\
        $(NORM) srcs/*.c includes/*.h;\
    fi
so:
    @if [ $(OS) = Linux ] ; then\
        $(CC) -fPIC -c $(wildcard $(SRCDIR)/*.c);\
        $(CC) -shared -o $(OUTDIR)/libft.so *.o;\
        rm -rf *.o;\
    else\
        echo "[-] This feature only supports Linux";\
    fi
soclean:
    @if [ $(OS) = Linux ] ; then\
        rm -rf $(OUTDIR)/libft.so;\
    else\
        echo "[-] This feature only supports Linux";\
    fi
.PHONY: all clean fclean re bonus norm so soclean
