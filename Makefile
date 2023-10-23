# Makefile for f2022, ecs36b
#
# g++ -std=c++14 test_GPS.cpp GPS.cpp -o test_GPS
#
# example: $ ./test_GPS 48.88 2.3

CC 	= g++ -std=c++14
CFLAGS 	= -g -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -lcurl -ljsonrpccpp-client

# rules.
all: 	test_ThingPerson test_Labeled_GPS

#
#

Record.o:	Record.cpp Record.h
	$(CC) -c $(CFLAGS) Record.cpp

GPS.o:		GPS.cpp GPS.h
	$(CC) -c $(CFLAGS) GPS.cpp

Labeled_GPS.o:	Labeled_GPS.cpp Labeled_GPS.h GPS.h
	$(CC) -c $(CFLAGS) Labeled_GPS.cpp

JvTime.o:	JvTime.cpp JvTime.h
	$(CC) -c $(CFLAGS) JvTime.cpp

Person.o:	Person.cpp Person.h
	$(CC) -c $(CFLAGS) Person.cpp

Thing.o:	Thing.cpp Thing.h
	$(CC) -c $(CFLAGS) Thing.cpp

test_ThingPerson.o:	test_ThingPerson.cpp GPS.h Thing.h Person.h JvTime.h Record.h
	$(CC) -c $(CFLAGS) test_ThingPerson.cpp

test_Labeled_GPS.o:	test_Labeled_GPS.cpp GPS.h Labeled_GPS.h
	$(CC) -c $(CFLAGS) test_Labeled_GPS.cpp

test_ThingPerson:	GPS.o Labeled_GPS.o test_ThingPerson.o Thing.o Person.o JvTime.o Record.o
	g++ -std=c++14 test_ThingPerson.o GPS.o Labeled_GPS.o Thing.o Person.o JvTime.o Record.o -o test_ThingPerson $(LDFLAGS)

test_Labeled_GPS:	GPS.o Labeled_GPS.o test_Labeled_GPS.o
	g++ -std=c++14 test_Labeled_GPS.o GPS.o Labeled_GPS.o -o test_Labeled_GPS $(LDFLAGS)

clean:
	rm -f *.o *~ core test_ThingPerson test_Labeled_GPS


