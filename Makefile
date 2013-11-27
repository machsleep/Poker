# Program name
program_NAME := poker

# .cpp files#
program_CXX_SRCS := $(wildcard src/*/*.cpp)

# .o files (what we are to build)#
program_CXX_OBJS := $(program_CXX_SRCS:.cpp=.o)

# All objects. (if we have other objs, define them above, then list them here)# 
program_OBJS := $(program_CXX_OBJS)

# BOOST DEPENDENCIES
# Please ensure you have $(BOOST_ROOT) defined for your system
BOOST_ROOT = $(HOME)/boost_1_55_0 
boost_INCLUDE_DIR := $(BOOST_ROOT)/boost
boost_LIB_DIR :=

# Include directories#
program_INCLUDE_DIRS := $(boost_INCLUDE_DIR)

# Library directories#
program_LIBRARY_DIRS := $(boost_LIB_DIR)

# Specific libraries
program_LIBRARIES :=

# Add all of our include directories
# Remember, CPPFLAGS are preprocessor flags
CPPFLAGS += $(foreach includeddir, $(program_INCLUDE_DIRS), -I$(includeddir)) 

# Add all of our library directories
# Remember, LDFLAGS are used during linking
LDFLAGS += $(foreach libdir,$(program_LIBRARY_DIRS), -L$(libdir))
LDFLAGS += $(foreach lib, $(prrogram_LIBRARIES), -l$(lib))

.PHONY: all clean distclean

all: $(program_NAME)

# This target builds our program
$(program_NAME): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

# This target cleans everything
clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

# Final program
distclean: clean



# Color codings
#NO_COLOR=\x1b[0m
#OK_COLOR=\x1b[32;01m

# Build progress
#OK_BUILD=$(OK_COLOR)[OK]$(NO_COLOR)

#prog : ${OBJ_FILES}
#	${CXX} ${LDFLAGS} -o $@ $^
	@echo Built executable "$(OK_BUILD)"

#obj/Card.o : src/%/%.cpp
#	@echo "$(NO_COLOR)"
#	${CXX} ${CXXFLAGS} -c  $@ $<
#	@echo Built $@ "$(OK_BUILD)"

#print :
#	@echo $(CPP_FILES) "\n"
#	@echo $(OBJ_FILES)

#clean : 
#	-rm -f *.o
#	-rm -f prog
