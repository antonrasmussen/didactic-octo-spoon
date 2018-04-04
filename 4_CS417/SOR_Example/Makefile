LDFLAGS		:= -lm 
CXXFLAGS	:= -O3 -DNDEBUG

EXECNAME	:= tridiagonal_solver

all: tridiagonal_solver

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

tridiagonal_solver: LinearSystem.o tridiagonal_solver.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) *.o *~ tridiagonal_solver

