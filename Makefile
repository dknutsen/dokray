CC=g++
CXX=g++
CPPFLAGS= -I.
EXECUTABLE=dokray
TARFILE=dokray.tar

CXX_OBJS= \
	Background.o \
	Camera.o \
	Image.o \
	Light.o \
	main.o 	\
	Material.o \
	Object.o \
	Plane.o \
	Scene.o \
	Sphere.o \
	Timer.o 

HEADERS= \
	Background.hh \
	Camera.hh \
	Color.hh \
	Global.hh \
	HitRecord.hh \
	Image.hh \
	Light.hh \
	Material.hh \
	Object.hh \
	Plane.hh \
	Point.hh \
	Primitive.hh \
	Ray.hh \
	RenderContext.hh \
	Scene.hh \
	Sphere.hh \
	Timer.hh \
	Vector.hh

%.o: %.cc $(HEADERS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)

$(EXECUTABLE): $(CXX_OBJS)
	$(CXX) -o $@ $^ $(CPPFLAGS)

clean: 
	rm *.o dokray

tar: 
	tar -cvf $(TARFILE) *.cc *.hh README Makefile

#CC=g++
#CFLAGS=-c -Wall
#LDFLAGS=
#SOURCES=main.cpp hello.cpp factorial.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
#EXECUTABLE=hello

#all: $(SOURCES) $(EXECUTABLE)
	
#$(EXECUTABLE): $(OBJECTS) 
#	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

#.cpp.o:
#	$(CC) $(CFLAGS) $< -o $@





#OBJS = MovieList.o Movie.o NameList.o Name.o Iterator.o
#CC = g++
#DEBUG = -g
#CFLAGS = -Wall -c $(DEBUG)
#LFLAGS = -Wall $(DEBUG)

#p1 : $(OBJS)
#    $(CC) $(LFLAGS) $(OBJS) -o p1

#MovieList.o : MovieList.h MovieList.cpp Movie.h NameList.h Name.h Iterator.h
#    $(CC) $(CFLAGS) MovieList.cpp

#Movie.o : Movie.h Movie.cpp NameList.h Name.h
#    $(CC) $(CFLAGS) Movie.cpp

#NameList.o : NameList.h NameList.cpp Name.h 
#    $(CC) $(CFLAGS) NameList.cpp

#Name.o : Name.h Name.cpp 
#    $(CC) $(CFLAGS) Name.cpp

#Iterator.o : Iterator.h Iterator.cpp MovieList.h
#    $(CC) $(CFLAGS) Iterator.cpp

#clean:
#	\rm *.o *~ p1

#tar:
#	tar cfv p1.tar Movie.h Movie.cpp Name.h Name.cpp NameList.h \
#	NameList.cpp  Iterator.cpp Iterator.h
