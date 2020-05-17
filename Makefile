TARGET_EXEC ?= VeronixBox.exe

ROOT_DIR ?= ../..
OUT_DIR ?= $(ROOT_DIR)/output
OBJ_DIR ?= $(ROOT_DIR)/obj
SRC_DIRS ?= $(ROOT_DIR)

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:$(ROOT_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

#.PHONY: ENV_INFO
#ENV_INFO:
#	$(info OUT_DIR is $(OUT_DIR))
#	$(info OBJ_DIR is $(OBJ_DIR))
#	$(info SRC_DIRS is $(SRC_DIRS))
#	$(info SRCS is $(SRCS))
#	$(info OBJS is $(OBJS))
#	$(info DEPS is $(DEPS))

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

$(OUT_DIR)/$(TARGET_EXEC): $(OBJS)
	$(MKDIR_P) $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# c++ source
$(OBJ_DIR)/%.o: $(SRC_DIRS)/%.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	$(RM) -r $(OUT_DIR)
	$(RM) -r $(OBJ_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p