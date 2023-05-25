DEP_LIBS = smart_ptr

LIB_DIR = ..
LIBS = $(foreach d, $(DEP_LIBS), -L$(LIB_DIR)/$(d) -l$(d))

test:
	echo $(LIBS)