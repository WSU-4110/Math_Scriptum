#include "print.h"
#include "equationsarea.h"
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextImageFormat>
#include <QTextCursor>
#include <QTextCharFormat>

print::print(QWidget *parent) : EquationsArea(parent)
{
}

void print::printToPDF(QString text, QImage image)
{
    ///Add new lines to the note area string some image of graph will be on its own line
    text = text + "\n\n";

    ///Open dialog box to get file name and directory to save pdf to
    QString fileName = QFileDialog::getSaveFileName(this, tr("Create Save File"), "/home/jana/untitled.pdf", tr("Text (*.pdf)"));

    ///Create printer object
    QPrinter printer(QPrinter::PrinterResolution);

    ///explicitly set printer output to pdf
    printer.setOutputFormat(QPrinter::PdfFormat);

    ///set paper size to letter (8.5"*11")
    printer.setPaperSize(QPrinter::Letter);

    ///set file name to name defined in dialog box
    printer.setOutputFileName(fileName);

    ///set page margins
    printer.setPageMargins(QMargins(30,30,30,30));

    ///set output font
    QFont textFont("Times New Roman", 12);

    ///create text format object
    QTextCharFormat txtfmt = QTextCharFormat();

    ///create text document object
    QTextDocument doc;

    ///set page size to printer page size
    doc.setPageSize(printer.pageRect().size());

    ///create text cursor object
    QTextCursor cursor(&doc);

    ///set font for text format
    txtfmt.setFont(textFont);

    ///insert note area text to text document
    cursor.insertText(text, txtfmt);

    ///insert graph from equation area on window
    cursor.insertImage(image);

    ///call print method to create pdf in user defined directory
    doc.print(&printer);
}
