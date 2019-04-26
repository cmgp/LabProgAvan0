
ifndef verbose
  SILENT = @
endif

.PHONY: clean

TARGETDIR = build/bin
TARGET = $(TARGETDIR)/PALab00.app
OBJDIR = build/obj

SRC_FILES := $(wildcard source/*.cpp)
OBJ_FILES := $(addprefix $(OBJDIR)/,$(SRC_FILES:source/%.cpp=%.o))

INCLUDES = -Iinclude
CPPFLAGS = -MMD -MP $(INCLUDES) -std=c++17
LINKCMD = $(CXX) -o "$@" $(OBJ_FILES) -s

all: $(TARGET)
	@:

run: $(TARGET)
	@clear
	@$(TARGET)

$(TARGET): $(OBJ_FILES) | $(TARGETDIR)
	@echo Linkeando PA_Lab_00
	$(SILENT) $(LINKCMD)

$(TARGETDIR):
	@echo Creando $(TARGETDIR)
	$(SILENT) mkdir -p $(TARGETDIR)

$(OBJDIR):
	@echo Creando $(OBJDIR)
	$(SILENT) mkdir -p $(OBJDIR)


clean:
	@echo Limpiando PA_Lab_00
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)

$(OBJ_FILES): | $(OBJDIR)

$(OBJDIR)/%.o: source/%.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"


-include $(OBJ_FILES:%.o=%.d)
