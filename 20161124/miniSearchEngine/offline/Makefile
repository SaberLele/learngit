INC_DIR:= ./
SRC_DIR:= ./
SRCS:=$(wildcard ./*.cc)
OBJS:= $(patsubst %.cc, %.o, $(SRCS))
LIBS:= -lpthread

CXX:=g++

CXXFLAGS:= -w -g -std=c++11 -lboost_regex $(addprefix -I, $(INC_DIR)) $(LIBS) -Wno-deprecated

EXE:=./main.exe

$(EXE):$(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS)

clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
	rm -rf *.lib
