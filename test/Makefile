CC=g++

PROGRAMS= test1 test2 test3 test4 videoFileToFileTest screenshotTest test7 test8

TAGS= -L.. -lavenconding -g -O0

ALL: $(PROGRAMS)

test1: test1.cpp
	$(CC) test1.cpp -o test1 $(TAGS)
	
test2: test2.cpp
	$(CC) test2.cpp -o test2 $(TAGS)
	
test3: test3.cpp
	$(CC) test3.cpp -o test3 $(TAGS)
	
test4: test4.cpp
	$(CC) test4.cpp -o test4 $(TAGS)
	
videoFileToFileTest: videoFileToFileTest.cpp
	$(CC) videoFileToFileTest.cpp -o videoFileToFileTest $(TAGS)
	
screenshotTest: screenshotTest.cpp
	$(CC) screenshotTest.cpp -o screenshotTest -lcpputil $(TAGS)
	
test7: test7.cpp
	$(CC) test7.cpp -o test7 $(TAGS)
	
test8: test8.cpp
	$(CC) test8.cpp -o test8 $(TAGS)
	
clean:
	rm -f $(PROGRAMS)
	

