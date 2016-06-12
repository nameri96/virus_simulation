all:
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/cyberdns.o src/cyberdns.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/cyberexpert.o src/cyberexpert.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/cyberpc.o src/cyberpc.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/cyberworm.o src/cyberworm.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/cybernetwork.o src/cybernetwork.cpp
	g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/cyberboost.o src/cyberboost.cpp
	
	g++ -o bin/cyber bin/cyberdns.o bin/cyberexpert.o bin/cyberpc.o bin/cyberworm.o bin/cyberboost.o bin/cybernetwork.o
	
	 