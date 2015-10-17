
GCC = clang++

unix: filesplit.cpp
	$(GCC) filesplit.cpp -o filesplit

windows: filesplit.cpp
	$(GCC) filesplit.cpp -o filesplit.exe
