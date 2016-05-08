#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../CocktailDB.h"

// Global variables
extern Cabinet *Cab;
extern IngredientDatabase *IngDB;
extern CocktailDB *CDB;

namespace Ui {
class MainWindow;
}

class QListWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_cabinetSearch_textChanged(const QString &arg1);

    void on_possibleIngredients_currentTextChanged(const QString &currentText);

    void on_clearCabinet_clicked();

    void on_myCabinet_currentTextChanged(const QString &currentText);

    void on_clearSelectedIngredients_clicked();

    void on_possibleIngredients_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
