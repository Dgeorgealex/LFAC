all:
	flex tokenizer.l
	bison -d -Wcounterexamples -v parser.y
	gcc parser.tab.c
	./a.out < text.txt
clean:
	rm -f lex.yy.c parser.output parser.tab.h parser.tab.c