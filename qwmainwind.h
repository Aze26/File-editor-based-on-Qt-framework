#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include<QMainWindow>
#include<QLabel>
#include<QSpinBox>
#include<QProgressBar>
QT_BEGIN_NAMESPACE
namespace Ui { class QWMainWind; }
QT_END_NAMESPACE

class QWMainWind : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *label;
    QSpinBox *spinbox;
    QProgressBar *progressbar;
    void iniUI();
    void iniSignalSlots();

public:
    QWMainWind(QWidget *parent = nullptr);
    ~QWMainWind();
private slots:
    void on_actionClear();
    void on_actionUnder();
    void on_actionItalic();
    void on_actionBold();
    void spinbox_value(int FontSize);
    void on_actionBlack();
    void on_actionRed();
    void on_actionBlue();
private:
    Ui::QWMainWind *ui;
};
#endif // QWMAINWIND_H
