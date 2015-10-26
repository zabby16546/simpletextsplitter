
GCC = clang++
WIN = i686-w64-mingw32-g++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11

msg:
	@echo "Targets:"
	@echo "unix"
	@echo "windows"

unix: filesplit.cpp
	$(GCC) $(OPTIONS) filesplit.cpp -o filesplit

windows: filesplit.cpp
	$(WIN) $(OPTIONS) filesplit.cpp -o filesplit.exe
