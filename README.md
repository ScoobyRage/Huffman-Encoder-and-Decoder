# Huffman-Encoder-and-Decoder
Huffman Coding Implementation
Overview
This C++ program implements Huffman Coding, a lossless data compression algorithm. It compresses a string from an input file by assigning variable-length binary codes to characters based on their frequencies and decompresses the encoded string back to its original form. The program creates and manages text files for input, frequency data, compressed output, and decoded output.
Features
File Creation: Creates an input.txt file for users to provide the string to be compressed.
Encoding: Reads a string from input.txt, builds a Huffman tree based on character frequencies, generates Huffman codes, and saves the compressed binary string to output.txt. Character frequencies are saved to frequency.txt.
Decoding: Reads the compressed string from output.txt and frequency data from frequency.txt, reconstructs the Huffman tree, and decodes the string, saving the result to decoded.txt.
Interactive Menu: Provides a simple console-based menu to create the input file, encode, or decode.
Prerequisites
A C++ compiler
A text editor to modify the input.txt file
Basic understanding of file I/O and Huffman Coding
How to Use:
Compile the Program:
bash
g++ main.cpp -o huffman
Run the Program:
bash
./huffman
Follow the Menu Options:
Option 1: Creates an empty input.txt file in the same directory as the program.
Option 2: Encodes the string from input.txt, saving the compressed string to output.txt and frequency data to frequency.txt.
Option 3: Decodes the compressed string from output.txt using frequency data from frequency.txt and saves the decoded string to decoded.txt.
Provide Input:
After selecting Option 1, open input.txt in a text editor and write the string you want to compress (e.g., "hello world").
Save and close input.txt, then return to the program to encode or decode.
File Structure
input.txt: User-provided file containing the string to compress.
frequency.txt: Stores character frequencies (character and count pairs) used for encoding and decoding.
output.txt: Stores the compressed binary string (e.g., "010101...").
decoded.txt: Stores the decoded string after decompression.
main.cpp: The source code implementing Huffman Coding.
Example Workflow
Run the program and select Option 1 to create input.txt.
Edit input.txt and add the string "hello".
Select Option 2 to encode. The program generates:
frequency.txt (e.g., h 1, e 1, l 2, o 1)
output.txt (e.g., 01010110)
Select Option 3 to decode. The program generates:
decoded.txt (e.g., hello)
Notes
Ensure input.txt contains a valid string before encoding.
The program assumes output.txt and frequency.txt are present and correctly formatted for decoding.
The program uses a simple bubble sort for sorting nodes, which may be inefficient for large inputs. Consider optimizing with a priority queue for better performance.
Memory management is handled via a freeTree function to prevent memory leaks.
Limitations
The program supports characters within a limited ASCII range (0–99).
Large input strings may result in long binary strings in output.txt.
Error handling for file operations or invalid inputs is minimal.
Future Improvements
Add error handling for missing or malformed files.
Implement a priority queue for efficient Huffman tree construction.
Support binary file output for compressed data to reduce storage size.
Add a user interface for easier interaction.
