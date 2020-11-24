

main : Main.o LinuxSocketSupport.o LinuxSupport.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o main Main.o LinuxSocketSupport.o LinuxSupport.o -I. -pthread

Main.o : Main.cpp Support.h SocketSupport.h 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Main.cpp -I.
		
LinuxSupport.o : Support.h LinuxSupport.cpp
		g++ -g -c -std=c++11 -Wall -Wextra -Werror LinuxSupport.cpp -I.

LinuxSocketSupport.o : SocketSupport.h LinuxSocketSupport.cpp
		g++ -g -c -std=c++11 -Wall -Wextra -Werror LinuxSocketSupport.cpp -I.

zap :
		rm main *.o




