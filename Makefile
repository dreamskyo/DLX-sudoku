# 編譯器設定
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# 目標檔案
TARGET = sudoku.exe
SRCS = main.cpp DLX.cpp
OBJS = $(SRCS:.cpp=.o)

# 預設目標
all: $(TARGET)

# 連結目標檔案
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# 編譯原始檔
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理編譯產生的檔案
clean:
	del /F /Q $(OBJS) $(TARGET)

# 重新編譯
rebuild: clean all

# 防止與同名檔案衝突
.PHONY: all clean rebuild