NAME    := interface
CC      := c++
CFLAGS  := -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g


SRCDIR := .
OBJDIR := build
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo  "\nCreated executable '$(NAME)'"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp Makefile *h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re