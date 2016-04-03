#ifndef INGREDIENTDATABASE_H
#define INGREDIENTDATABASE_H

#include <QMainWindow>
#include <vector>
#include "ingredient.h"

namespace Ui {
	class IngredientDatabase;
}

class IngredientDatabase : public QMainWindow
{
    Q_OBJECT

public:
    explicit IngredientDatabase(QWidget *parent = 0);
    ~IngredientDatabase();
	void populateDB(string filename);

private:
    Ui::IngredientDatabase *ui;
	vector<ingredient> ingredientList;
};

#endif // INGREDIENTDATABASE_H
