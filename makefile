CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = a.exe
OBJ_DIR = obj

# Рекурсивный поиск .cpp и .hpp файлов
ifeq ($(OS),Windows_NT)
    SOURCES := $(shell dir /S /B *.cpp 2>nul)
    SOURCES := $(subst \,/,$(SOURCES))
    HEADERS := $(shell dir /S /B *.hpp 2>nul)
    HEADERS := $(subst \,/,$(HEADERS))
    
    # Добавляем пути для include
    INCLUDES := $(sort $(dir $(HEADERS)))
    CXXFLAGS += $(addprefix -I, $(INCLUDES))
else
    SOURCES := $(shell find . -name "*.cpp" -type f | sed 's|^\./||')
    HEADERS := $(shell find . -name "*.hpp" -type f | sed 's|^\./||')
    INCLUDES := $(sort $(dir $(HEADERS)))
    CXXFLAGS += $(addprefix -I, $(INCLUDES))
endif

# Очистка путей
SOURCES := $(strip $(SOURCES))
HEADERS := $(strip $(HEADERS))
SOURCES := $(filter-out obj/%, $(SOURCES))

# Создаем объектные файлы с уникальными именами (используем только имя файла)
OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.cpp=.o)))

# Создаем соответствие между объектными файлами и исходниками
define create_rule
$(OBJ_DIR)/$(notdir $(1:.cpp=.o)): $(1) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $$< -o $$@
endef

# Информация
$(info === Project files ===)
$(info Sources: $(SOURCES))
$(info Headers: $(HEADERS))
$(info Includes: $(INCLUDES))
$(info Objects: $(OBJECTS))
$(info ===================)

ifeq ($(SOURCES),)
$(error No .cpp files found!)
endif

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir $(OBJ_DIR) 2>nul || true

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Build complete!"

# Генерируем правила для каждого исходного файла
$(foreach src,$(SOURCES),$(eval $(call create_rule,$(src))))

clean:
	rmdir /S /Q $(OBJ_DIR) 2>nul
	del $(TARGET) 2>nul
	@echo "Cleaned"

run: $(TARGET)
	$(TARGET)

.PHONY: all clean run