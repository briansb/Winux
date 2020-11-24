

BasicGUIandTimer : MyApp.o MyFrame.o
#		g++ -g -std=c++11 -Wall -Wextra -Werror -o BasicGUIandTimer Main.o Stress_Test.o OS_Specific.o GenericSupport.o LinuxSupport.o WindowsSupport.o GenericSocketSupport.o LinuxSocketSupport.o WindowsSocketSupport.o -I.
		g++ MyApp.o MyFrame.o `wx-config --cxxflags --libs std` -o BasicGUIandTimer

MyApp.o : MyApp.h MyApp.cpp
#		g++ -g -c -std=c++11 -Wall -Wextra -Werror MyApp.cpp -I.
		g++ -c MyApp.cpp `wx-config --cxxflags`

MyFrame.o : MyFrame.h MyFrame.cpp
#		g++ -g -c -std=c++11 -Wall -Wextra -Werror MyFrame.cpp -I.
		g++ -c MyFrame.cpp `wx-config --cxxflags`


zap :
		rm BasicGUIandTimer *.o




