#Makefile is a form of automation that makes compilation of a group of files more efficient

#Name of compiled file
NAME = libft.a

#Flags used to compile the files
GCCFLAG = gcc -Wall -Wextra -Werror

#All the files we want to compile
SRCS 	= ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
        ft_lstadd.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_memcpy.c ft_memdel.c\
		ft_memset.c ft_putchar.c ft_putstr.c ft_split.c ft_strchr.c ft_strcmp.c ft_strcpy.c\
		ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_swap.c ft_tolower.c\
		ft_toupper.c\

#Folder to store all the .o files
SRCS_O 	= $(SRCS:.c=.o)

#Will be the archived file
all:	$(NAME)

#ar -rcs is the most likely command you would use when 
#using a Makefile to compile a library. r means that if the library already exists, replace the old files within the library 
#with your new files. c means create the library if it did not exist. s can be seen to mean 'sort' (create a sorted index of) 
#the library, so that it will be indexed and faster to access the functions in the library. Therefore, rcs can be seen to mean 
#replace, create, sort.

#ranlib doesn't create libraries at all. In Linux, ranlib is a legacy program that adds an (uptodate) symbol table to an ar archive 
#if it doesn't have one. It's effect is exactly the same as ar s, with GNU ar. Historically, before ar was equipped to generate a symbol 
#table itself, ranlib was the kludge that injected the magic phony file into an archive to enable the linker to pick object files out of it. 
#In non-GNU Unix-like OSes, ranlib might still be needed for this purpose.
$(NAME): $(SRCS_O)
		ar rc $(NAME) $(SRCS_O)
		ranlib $(NAME)

#"%.o: %.c" means that any file ending in .o depends on the same filename ending in .c to be present.
%.o: %.c
		$(GCCFLAG) -o $@ -c $<

#Cleans all .o files
clean:
		rm -f $(SRCS_O)

#Cleans the libft.a file
fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re