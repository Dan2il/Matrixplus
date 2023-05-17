SOURCES = s21_matrix_oop/sources/constructors.cpp s21_matrix_oop/sources/assign.cpp s21_matrix_oop/sources/comparison.cpp s21_matrix_oop/sources/arithmetic_operations.cpp s21_matrix_oop/sources/operators.cpp s21_matrix_oop/sources/matrix_operations.cpp s21_matrix_oop/sources/other_methods.cpp

all: test s21_matrix_oop.a

test: gtest_install
	cmake -S . -B build
	cmake --build build
	cd build && ctest --rerun-failed --output-on-failure

s21_matrix_oop.a:
	g++ -c $(SOURCES)
	ar rcs s21_matrix_oop.a constructors.o assign.o comparison.o arithmetic_operations.o operators.o matrix_operations.o other_methods.o
	rm -rf *.o

gtest_install:
	if test ! -d googletest; \
	then \
	`git clone https://github.com/google/googletest.git -b v1.13.0`; \
	cd googletest; cmake -B build googletest/build ..; \
	fi

gtest_uninstall:
	rm -rf googletest

coverage: test
	mkdir report 
	gcovr --html-details report/coverage.html  -r s21_matrix_oop .

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=_valgrind-out.txt ./build/s21_matrix_tests


clean:
	rm -rf build report *.o *.a *.html *.css