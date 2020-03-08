LDFLAGS = -ldl -Wl,--export-dynamic
CXXFLAGS = -std=c++11 -g -pedantic -Wall -Werror -Wextra

TESTS = failing_tests passing_tests debug_tests

.PHONY: test tests
all: test $(TESTS)

test:
	$(CXX) $(CXXFLAGS) -I . -I .. $@.cpp $(LDFLAGS) -o $@

$(TESTS): %: %.cpp
	$(CXX) $(CXXFLAGS) -I .. $< $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f test $(TESTS)
