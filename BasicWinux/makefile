

main : main.o OS_Specific.o GenericSupport.o LinuxSupport.o WindowsSupport.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o main main.o OS_Specific.o GenericSupport.o LinuxSupport.o WindowsSupport.o -I.

main.o : main.cpp OS_Specific.h support.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror main.cpp -I.

OS_Specific.o : OS_Specific.h OS_Specific.cpp
		g++ -g -c -std=c++11 -Wall -Wextra -Werror OS_Specific.cpp -I.
		
GenericSupport.o : support.h GenericSupport.cpp 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror GenericSupport.cpp -I.

LinuxSupport.o : LinuxSupport.cpp 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror LinuxSupport.cpp -I.

WindowsSupport.o : WindowsSupport.cpp 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror WindowsSupport.cpp -I.

zap :
		rm main *.o




