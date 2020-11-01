CXX = g++

all: optional program_options any signals2 filesystem string bimap

optional: optional.cpp
	$(CXX) $^ -o $@

program_options: program_options.cpp
	$(CXX) $^ -lboost_program_options -o $@

any: any.cpp
	$(CXX) $^ -o $@

signals2: signals2.cpp
	$(CXX) $^ -o $@

filesystem: filesystem.cpp
	$(CXX) $^ -lboost_filesystem -o $@

string: string.cpp
	$(CXX) $^ -o $@

bimap: bimap.cpp
	$(CXX) $^ -o $@

clean:
	rm optional
	rm program_options
	rm any
	rm signals2
	rm filesystem
	rm string
	rm bimap