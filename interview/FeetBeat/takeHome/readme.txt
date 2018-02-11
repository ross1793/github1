Write a C99 program which takes as arguments the name of a binary input file and a text output file.  The binary input file will contain 12 bit unsigned values.  The output file should contain the 32 largest values from the input file.  It should also contain the last 32 values read from the input file.  Try to write the portions of the code that are not related to I/O as you would for a memory and speed limited device.  Attached you will find three sample input (.bin) and output (.out) files which you can use for testing. 

 

Notes

1.    If there are an odd number of 12 bit readings in the file, then the last nibble in the file will be zero and can be ignored.

2.    The file format should be as follows

a.    Start with “--Sorted Max 32 Values--"

b.    The 32 largest values in the file, one value per line.  Duplicates are allowed if a large value appears multiple times.  The list should be sorted smallest to largest.

c.    Output “--Last 32 Values--" on its own line

d.    The last 32 values read, one per line.    They should appear in the order they were read.  The last value read from the file will appear last.

3.    If there are fewer than 32 values in the file then whatever is read should be output

4.    Your output files should match the output files provided with the given input.

5.    If your program is passed bogus values, it should not core dump.

6.    test#.bin is the binary file that corresponds with test#.out   Three test inputs and outputs have been provided.

7.    Bonus point for providing a make file or some other build script.

8.    Please provide comments in the top of your code describing design decisions / trade-offs and  if you did any optimizations for speed, memory, etc.  Most of our projects are on MCUs with limited memory powered by a small battery.  Optimizations are not required but a good way to show off if they work.

9.    If you have any questions, please let us know.  We also welcome any feedback you might have on the questions, the way it is worded etc.  Our goal is to make interviews fun and interesting and a way for us to find people with whom we can enjoy conquering hard problems.
