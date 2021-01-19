#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QColor>
#include <QDesktopServices>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void read(int argc, char *argv[]);



private slots:
    void on_actionSave_as_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionDark_theme_triggered();

    void on_actionText_wrapping_toggled(bool arg1);

    void on_actionDark_theme_toggled(bool arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_actionFont_size_triggered();

    void on_actionFont_size_2_triggered();

    void on_actionAbout_me_triggered();

    void on_textEdit_textChanged();



private:
    Ui::MainWindow *ui;
    QString currentFile = "";
    void keyPressEvent(QKeyEvent * event);

};
#endif // MAINWINDOW_H
