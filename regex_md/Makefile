md_convert: main.o parser.o markdownconvert.o
	g++ -g -o md_convert main.o parser.o markdownconvert.o

markdownconvert.o: markdownconvert.cpp markdownconvert.h
	g++ -g -c -o markdownconvert.o markdownconvert.cpp

parser.o: parser.cpp parser.h
	g++ -g -c parser.cpp
main.o: main.cpp
	g++ -g -c main.cpp


#Usage: 
#md_convert -i markdown_sample.md -o index.html
# -i: the input file.  Could be markdown_sample.md or something else
# -o: the output file. e.g. index.html  

clean:
	rm -f md_convert  
	rm -f *.o *.bak *~*

