# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 15:53:40 by nbeaufil          #+#    #+#              #
#    Updated: 2023/06/03 17:55:53 by nbeaufil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	=	-Wall -Wextra -Werror
NAME	=	hexdump
OBJDIR	=	object
INCLUDE	=	-I./include
FILE1	=	arg_manager
FILE2	=	hexdump
FILE3	=	hex_funct
FILE4	=	hex_utils
FILE5	=	read_file

all :
ifneq (,$(wildcard ${NAME}))
		echo make: \'${NAME}\' is already up to date.
else
	make ${NAME}
endif

objs_crt	:
	${CC} -c ${FLAGS} srcs/${FILE1}.c ${INCLUDE} -o ${OBJDIR}/${FILE1}.o
	${CC} -c ${FLAGS} srcs/${FILE2}.c ${INCLUDE} -o ${OBJDIR}/${FILE2}.o
	${CC} -c ${FLAGS} srcs/${FILE3}.c ${INCLUDE} -o ${OBJDIR}/${FILE3}.o
	${CC} -c ${FLAGS} srcs/${FILE4}.c ${INCLUDE} -o ${OBJDIR}/${FILE4}.o
	${CC} -c ${FLAGS} srcs/${FILE5}.c ${INCLUDE} -o ${OBJDIR}/${FILE5}.o

$(NAME)	: ${OBJDIR} objs_crt
	${CC} ${FLAGS} ${OBJDIR}/*.o -o ${NAME}

$(OBJDIR)	:
	mkdir ${OBJDIR}

clean	:
ifneq (,$(wildcard ./${OBJDIR}/*.o))
	rm ${OBJDIR}/*.o
endif

fclean	: clean
ifneq (,$(wildcard ${NAME}))
	rm ${NAME}
endif

dclean	:
	rm -rf object

re	: fclean ${NAME}

.PHONY: all re clean fclean

.SILENT:

