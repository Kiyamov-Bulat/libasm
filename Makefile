NAME		= libasm.a

SRCS		= ft__strlen.s ft__strcpy.s ft__strcmp.s ft__write.s ft__read.s ft__strdup.s

BONUS_SRCS	= ft__list_push_front.s ft__list_size.s ft__list_remove_if.s

OBJS		= ${SRCS:.s=.o}

BONUS_OBJS	= ${BONUS_SRCS:.s=.o}

NASMFLAGS	= -f macho64

AR			= ar rc

.s.o :		${DEPS}
			nasm ${NASMFLAGS} $<

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${NAME} $?

OBJS		+=	${BONUS_OBJS}

bonus:		${OBJS}
			${AR} ${NAME} $?

test:		${NAME}
			gcc main.c ${NAME} -o libasm_test
			./libasm_test

test_bonus:	bonus
			gcc -g -D BONUS main.c ${NAME} -o libasm_test
			./libasm_test
clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f libasm_test
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus test_bonus