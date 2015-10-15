
GCC = clang++

filesplit.exe: filesplit.cpp
	$(GCC) filesplit.cpp -o filesplit.exe
