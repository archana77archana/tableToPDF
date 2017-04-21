# tableToPDF

A dynammically memory allocated student table details are entered by the user and it finally outputs a PDF file in the very same folder.

The program is written in C. It uses a PDF generation library called [JagPDF](http://www.jagpdf.org/).

## Requirements

* [JagPDF](http://www.jagpdf.org/downloads/releases/1.4.0/linux/jagpdf-1.4.0.linux.x86.c_cpp.tar.bz2)
* Linux
* glibc version > 2.3

## Compiling the program

* `gcc tableToPDF.c -o tableToPDF -I/path/to/jagpdf-1.4.0.linux.x86.c_cpp/include -ljagpdf -m32`

## Running the program

* `./tableToPDF`

## Input

Provide the required details that is being asked in the prompt while running. 

## Output

After the program ends, check in the same folder you have stored `tableToPDF.c`. You will find an `output.PDF` file in the same folder with the table created.

## Drawbacks

The spacing given for the items in the table is done manually thus creating alignment problems in the table in the PDF generated.
