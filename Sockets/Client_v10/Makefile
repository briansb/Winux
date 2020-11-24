

main : Main.o LinuxSocketSupport.o LinuxSupport.o GenericSocketSupport.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o main Main.o LinuxSocketSupport.o LinuxSupport.o GenericSocketSupport.o -I.

Main.o : Main.cpp Support.h SocketSupport.h 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Main.cpp -I.
		
LinuxSupport.o : Support.h LinuxSupport.cpp
		g++ -g -c -std=c++11 -Wall -Wextra -Werror LinuxSupport.cpp -I.

LinuxSocketSupport.o : SocketSupport.h LinuxSocketSupport.cpp
		g++ -g -c -std=c++11 -Wall -Wextra -Werror LinuxSocketSupport.cpp -I.

GenericSocketSupport.o : SocketSupport.h GenericSocketSupport.cpp
		g++ -g -c -std=c++11 -Wall -Wextra -Werror GenericSocketSupport.cpp -I.

zap :
		rm main *.o




