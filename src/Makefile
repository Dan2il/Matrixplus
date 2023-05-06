test: clean gtest_install
	cmake -S . -B build
	cmake --build build
	cd build && ctest --rerun-failed --output-on-failure

gtest_install:
	if test ! -d googletest; \
	then \
	`git clone https://github.com/google/googletest.git -b v1.13.0`; \
	cd googletest; cmake -B build googletest/build ..; \
	fi

gtest_uninstall:
	rm -rf googletest

clean:
	rm -rf build
	rm -rf *.html