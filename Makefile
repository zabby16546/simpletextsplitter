
GCC = clang++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11

msg:
	@echo "Targets:"
	@echo "unix"
	@echo "windows"

unix: filesplit.cpp
	$(GCC) $(OPTIONS) filesplit.cpp -o filesplit

windows: filesplit.cpp
	$(GCC) $(OPTIONS) filesplit.cpp -o filesplit.exe
