#ifndef DIALOGSEARCHQUERY_H
#define DIALOGSEARCHQUERY_H

#include <QDialog>

namespace Ui {
class DialogSearchQuery;
}

class DialogSearchQuery : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogSearchQuery(QWidget *parent = 0);
    ~DialogSearchQuery();
    void Load();
    QString Query();
    QString Column();
    
private:
    Ui::DialogSearchQuery *ui;
};

#endif // DIALOGSEARCHQUERY_H
