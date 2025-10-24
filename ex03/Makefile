NAME = interface

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = build

SRC = AMateria.cpp  Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo  "\nCreated executable '$(NAME)'"


$(OBJDIR)/%.o: %.cpp Makefile *h | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
