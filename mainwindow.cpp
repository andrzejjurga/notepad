#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    //text area config
    ui->textEdit->setFontPointSize(20);

    //slider config
    ui->statusbar->addPermanentWidget(ui->horizontalSlider);
    ui->horizontalSlider->setMaximumWidth(200);
    ui->horizontalSlider->setValue(ui->textEdit->fontPointSize());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read(int argc,char *argv[])
{
    QFile file(argv[1]);
    currentFile = argv[1];
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        return;
    }
    setWindowTitle(argv[1]);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open the file"));
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save to file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();

}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot access Printer");
        return;
    }
    ui->textEdit->print(&printer);

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionDark_theme_triggered()
{

}

void MainWindow::on_actionText_wrapping_toggled(bool arg1)
{
    if(arg1)
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    else
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
}

void MainWindow::on_actionDark_theme_toggled(bool arg1)
{
    if(arg1)
        this->setStyleSheet("color: white;"
                        "background-color: #2e2e2e;"
                        "selection-color: rgba(0, 0, 0, 255);"
                        "selection-background-color: rgba(144, 200, 246, 127);");
    else
        this->setStyleSheet("color: black;"
                        "background-color: white;"
                        "selection-color: rgba(0, 0, 0, 255);"
                        "selection-background-color: rgba(144, 200, 246, 127);");
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->textEdit->selectAll();
    ui->textEdit->setFontPointSize(value);
    QTextCursor tc = ui->textEdit->textCursor();
    ui->textEdit->setTextCursor(tc);
}

void MainWindow::on_actionFont_size_triggered()
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()+1);
}

void MainWindow::on_actionFont_size_2_triggered()
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()-1);
}

void MainWindow::on_actionAbout_me_triggered()
{
    QDesktopServices::openUrl(QUrl("https://andrzejjurga.github.io/", QUrl::TolerantMode));
}

void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    QString last = text[text.length()-1]+" ";
    //ui->statusbar->showMessage(last);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == QT::Key_U)
    {

    }

    QString textto = "";
    textto += char(e->key());
    ui->statusbar->showMessage(textto);
    ui->statusbar->showMessage("k");
}
