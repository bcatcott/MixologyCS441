#ifndef INGREDIENTDATABASE_H
#define INGREDIENTDATABASE_H

#include <QMainWindow>

namespace Ui {
class IngredientDatabase;
}

class IngredientDatabase : public QMainWindow
{
    Q_OBJECT

public:
    explicit IngredientDatabase(QWidget *parent = 0);
    ~IngredientDatabase();

private:
    Ui::IngredientDatabase *ui;
};

#endif // INGREDIENTDATABASE_H
