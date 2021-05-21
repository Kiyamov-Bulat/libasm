char		*ft__strdup(const char *s);

void		print_strlen_diff(char *s);
void		print_strcpy_diff(char *src);
void		print_strcmp_diff(char *s1);
void		print_write_diff(char *s);
void		print_read_diff(char *s);
void		print_strdup_diff(char *s);
void		print_errno_diff(void);

typedef	void (*t_checker_f)(char *s);

typedef struct s_checker
{
	char		*name;
	t_checker_f f;
}				t_checker;

#ifdef BONUS

# define NUM_OF_FUNCS 2

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void	ft__list_push_front(t_list **begin_list, void *data);
int		ft__list_size(t_list *begin_list);

void	print_lst_push_front_res(char *s)
{
	static t_list	*lst;
	t_list			*tmp;
	int				i;

	ft__list_push_front(&lst, s);
	tmp = lst;
	i =	1;
	printf("\nRESULT:\n\n");
	while(lst)
	{
		printf("%d) %s ", i++, lst->data);
		lst = lst->next;
	}
	lst = tmp;
	printf("\n");
}

void	print_lst_size_res(char *s)
{
	static t_list	*lst;

	ft__list_push_front(&lst, s);
	printf("\nRESULT:\n\n");
	printf("SIZE: %d", ft__list_size(lst));
	printf("\n");
}

t_checker ch[] = {
		/*
		{"strlen", print_strlen_diff},	\
		{"strcpy", print_strcpy_diff},	\
		{"strcmp", print_strcmp_diff},	\
		{"write",  print_write_diff},	\
		{"read",   print_read_diff},	\
		{"strdup", print_strdup_diff},	\
		*/
		{"ft_list_push_front", print_lst_push_front_res}, \
		{"ft_list_size", print_lst_size_res}
	};

#else

# define NUM_OF_FUNCS 6

t_checker ch[] = {
		{"strlen", print_strlen_diff},	\
		{"strcpy", print_strcpy_diff},	\
		{"strcmp", print_strcmp_diff},	\
		{"write",  print_write_diff},	\
		{"read",   print_read_diff},	\
		{"strdup", print_strdup_diff}
};

#endif

#define INTRO "HELLO!"
#define EMPTY ""
#define COMMON "It's simple text for the testing assemble function@!"
#define BIG "It's big text: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"\
			"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"\
			"cccccccccccccccccccccccccccccccccccccccccccccccccccccccc"\
			"dddddddddddddddddddddddddddddddddddddddddddddddddddddddd"\
			"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"\
			"ffffffffffffffffffffffffffffffffffffffffffffffffffffffff"\
			" - end of big text."
char	*strs[] = {INTRO, EMPTY, COMMON, BIG, NULL};

/*
** ======================
** MAIN FUNCS CHECKERS
** ======================
*/

void	print_strlen_diff(char *s)
{
	int n;
	
	printf("\n[ TEXT ]:\n\t|%s|\n\n\n", s);
	printf("[ RESULT ]:\n\t%-20s %s\n", "Original", "Custom");
	printf("\t |%lu|%n", strlen(s), &n);
	printf("%-*s", 23 - n, "");
	printf("|%lu|\n", ft__strlen(s)); // #############CUSTOM#############
}

void	print_strcpy_diff(char *src)
{
	char	dst1[1000];
	char	dst2[1000];

	printf("\n[ SRC ]:\n\n|%s|\n\n\n", src);
	printf("[ RESULT ]:\n\n---Original:\n\n");
	printf("|%s|\n", strcpy(dst1, src));
	printf("\n---Custom:\n\n");
	printf("|%s|\n", ft__strcpy(dst2, src)); // #############CUSTOM#############
}

void	print_strcmp_diff(char *s1)
{
	int i;
	int n;

	i = 0;
	while (strs[i])
	{
		printf("\n[ S1 ]:\n|%s|\n\n", s1);
		printf("\n[ S2 ]:\n|%s|\n\n", strs[i]);
		printf("[ RESULT ]:\n\t%-20s %s\n", "Original", "Custom");
		printf("\t |%d|%n", strcmp(s1, strs[i]), &n);
		printf("%-*s", 23 - n, "");
		printf("|%d|\n", ft__strcmp(s1, strs[i])); // #############CUSTOM#############
		printf("\n(Press any key)");
		getchar();
		i++;
	}
}

void	print_write_diff(char *s)
{
	ssize_t n;

	printf("\n[ STR ]:\n\n|%s|\n\n\n", s);
	printf("[ RESULT ]:\n\n---Original:\n\n");
	printf("|");
	fflush(stdout);
	n = write(1, s, strlen(s));
	printf("|\nn == %ld\n\n---Custom:\n\n", n);
	printf("|");
	fflush(stdout);
	n = ft__write(1, s, strlen(s)); // #############CUSTOM#############
	printf("|\nn == %ld", n);
}

void	print_read_diff(char *s)
{
	ssize_t		n;
	char		buf[1000];

	write(1, "\n===Print any text: ", 20);
	n = read(1, buf, 1000);
	write(1, "\n[ RESULT ]:\n\n---Original:\n\n", 28);
	write(1, "|", 1);
	write(1, buf, n);
	write(1, "|\nn == ", 7);
	printf("%ld", n);
	fflush(stdout);
	write(1, "\n\nPrint same text: ", 18);
	n = ft__read(1, buf, 1000); // #############CUSTOM#############
	write(1, "\n---Custom:\n\n", 13);
	write(1, "|", 1);
	write(1, buf, n);
	write(1, "|\nn == ", 7);
	printf("%ld", n);
	fflush(stdout);
	write(1, "\n", 1);
}

void	print_strdup_diff(char *s)
{
	char *ori;
	char *cus;
	
	printf("\n[ SRC ]:\n\n|%s, address: %p|\n\n\n", s, s);
	printf("[ RESULT ]:\n\n---Original:\n\n");
	printf("|%s, ", ori = strdup(s));
	printf("address: %p|\n", ori);
	printf("\n---Custom:\n\n");
	printf("|%s, ", cus = ft__strdup(s)); // #############CUSTOM#############
	printf("address: %p|\n", cus);
	free(ori);
	free(cus);
}

void	print_errno_diff(void)
{
	int n;
	char s[20];

	printf("\n\n=====ERRNO CHECK=====\n\n");
	printf("[ WRITE ]\n\n");
	fflush(stdout);
	errno = 0;
	n = write(1, "TEST ERRNO W/O ERROR", 20);
	printf("\nOriginal: n == %d, errno == %d\n\n", n, errno);
	fflush(stdout);
	n = 0;
	errno = 0;
	n = ft__write(1, "TEST ERRNO W/O ERROR", 20);
	printf("\nCustom: n == %d, errno == %d\n\n", n, errno);
	fflush(stdout);
	errno = 0;
	n = write(-1, "TEST ERRNO W ERROR", 20);
	printf("Original: n == %d, errno == %d\n\n", n, errno);
	fflush(stdout);
	n = 0;
	errno = 0;
	n = ft__write(-1, "TEST ERRNO W ERROR", 20);
	printf("Custom: n == %d, errno == %d\n\n", n, errno);	
	fflush(stdout);
	printf("[ READ ]\n\n");
	errno = 0;
	n = read(1, s, 20);
	printf("\nOriginal: n == %d, errno == %d\n\n", n, errno);
	fflush(stdout);
	n = 0;
	errno = 0;
	n = ft__read(1, s, 20);
	printf("\nCustom: n == %d, errno == %d\n\n", n, errno);
	fflush(stdout);
	errno = 0;
	n = read(1, s, -1);
	printf("Original: n == %d, errno == %d\n\n", n, errno);
	fflush(stdout);
	n = 0;
	errno = 0;
	n = ft__read(1, s, -1);
	printf("Custom: n == %d, errno == %d\n\n", n, errno);	
	fflush(stdout);
}

void	print_function_name(char *name)
{
	printf("\n########################################################################\n");
	printf("########################################################################\n");
	printf("########################################################################\n");
	printf("                               %s                               \n", name);
	printf("########################################################################\n");
	printf("########################################################################\n");
	printf("########################################################################\n");
}

int	main (void)
{
	int		i;
	int		k;
	
	k = 0;
	while (k < NUM_OF_FUNCS)
	{
		i = 0;
		print_function_name(ch[k].name);
		while (strs[i])
		{
			printf("(Press any key)");
			getchar();
			printf("\n---------TEST № %d---------\n", i + 1);
			ch[k].f(strs[i++]);
			printf("\n=======================================================\n");
		}
		k++;
	}
	#ifndef BONUS
		print_errno_diff();
	#endif
}
