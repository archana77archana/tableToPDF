#include <stdio.h>
#include <stdlib.h>
#include <jagpdf/api.h>

struct table {
    int sl_no;
    int roll_no;
    char st_name[30];
    int marks;
};

int main() {
    struct table *ptr;
    int i, n, j;

    printf("Enter no. of entries in the table: ");
    scanf("%d", &n);

    ptr = (struct table*) malloc (n*sizeof(struct table));

    for(i = 0; i < n; i++) {
        printf("\nRow %d\n", i);
        (ptr+i)->sl_no = i;
        printf("\nEnter student details in the order: \nRoll no \tStudent name \tMarks\n");
        scanf("%d %s %d", &(ptr+i)->roll_no, &(ptr+i)->st_name, &(ptr+i)->marks);
    }

    //test
    printf("\nStudent details: \n\n");
    printf("|\tSl.No\t|\tRollNo\t|\tName\t|\tMarks\t|\n|\t\t|\t\t|\t\t|\t\t|");

    for(i = 0; i < n; i++) {
        printf("\n|\t%d\t|\t%d\t|\t%s\t|\t%d\t|", (ptr+i)->sl_no, (ptr+i)->roll_no, (ptr+i)->st_name, (ptr+i)->marks);
    }

   printf("\nGenerating PDF...\n");

   //PDF generation
   jag_Document doc;
   jag_Page page;
   jag_Canvas canvas;
   doc = jag_create_file("output.pdf", 0);
   jag_Document_page_start(doc, 597.6, 848.68);
   page = jag_Document_page(doc);
   canvas = jag_Page_canvas(page);

   char looper[200];  //an array to store the string in a line
   sprintf(looper, "Student Details:");
   jag_Canvas_text_simple(canvas, 70, 800, looper);

   sprintf(looper, "");
   jag_Canvas_text_simple(canvas, 70, 780, looper);

   // line
   jag_Canvas_move_to(canvas, 50, 780);
   jag_Canvas_line_to(canvas, 500, 780);
   jag_Canvas_path_paint(canvas, "s");
   // manual spacing
   sprintf(looper, "Sl.No        Roll No        Name                                                          Marks");
   jag_Canvas_text_simple(canvas, 70, 760, looper);

   // line
   jag_Canvas_move_to(canvas, 50, 750);
   jag_Canvas_line_to(canvas, 500, 750);
   jag_Canvas_path_paint(canvas, "s");
   j = 0;

   for(i = 730; i > 0;) {
     if(j == n)
	    break;
	   // manual spacing
	   sprintf(looper,"   %d                 %d               %s                                                     %d ", (ptr+j)->sl_no, (ptr+j)->roll_no, (ptr+j)->st_name, (ptr+j)->marks);
     jag_Canvas_text_simple(canvas, 70, i, looper);
     i = i-20;
     j = j+1;
   }

   jag_Document_page_end(doc);
   jag_Document_finalize(doc);
   jag_release(doc);

   printf("\noutput.pdf generated in the very same folder.\n\n");
}
