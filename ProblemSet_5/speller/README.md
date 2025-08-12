In speller.c, we’ve put together a program that’s designed to spell-check a file after loading a dictionary of words from disk into memory. That dictionary, meanwhile, is implemented in a file called dictionary.c. (It could just be implemented in speller.c, but as programs get more complex, it’s often convenient to break them into multiple files.) The prototypes for the functions therein, meanwhile, are defined not in dictionary.c itself but in dictionary.h instead. That way, both speller.c and dictionary.c can #include the file.


How to use this problem...
First copy all the content in the files called (Makefile, dictionary.c, speller.c, dictionary.h) then copy the folders called(dictionaries, texts) this are the folder that contain the different files that have the words and the sentences respectively. You have to put all the data as it is in the files with the same extenstions(i.e. speller.c , dictionary.c, ...) make sure that put all the code files in the same directory.
The whole instruction is like make sure that as my parent file named speller contain the things you have to put all the things same like this make sure the you havce same files amd the same folders in your speller directory.

How to run....
First use (make speller)
Then ./speller dictionaries/large texts/grimm.txt
In this two commands first one must be same and in the second (./speller dictionaries/large texts/(any you want).
