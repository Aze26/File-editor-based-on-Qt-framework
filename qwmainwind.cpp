#include "qwmainwind.h"
#include "./ui_qwmainwind.h"
void QWMainWind::iniUI()
{
    label=new QLabel;
    label->setText("Current File");
    ui->statusbar->addWidget(label);

    progressbar=new QProgressBar;
    progressbar->setMaximum(50);
    progressbar->setMinimum(5);
    progressbar->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressbar);

    spinbox=new QSpinBox;
    spinbox->setMaximum(50);
    spinbox->setMinimum(1);
    spinbox->setValue(ui->textEdit->font().pointSize());
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(new QLabel("Font Size"));
    ui->toolBar->addWidget(spinbox);

}

void QWMainWind::on_actionClear(){ui->textEdit->clear();}

void QWMainWind::on_actionUnder()
{
    QTextCharFormat format=ui->textEdit->currentCharFormat();
    format.setFontUnderline(!format.fontUnderline());
    ui->textEdit->mergeCurrentCharFormat(format);
}

void QWMainWind::on_actionItalic()
{
    QTextCharFormat format=ui->textEdit->currentCharFormat();
    format.setFontItalic(!format.fontItalic());
    ui->textEdit->mergeCurrentCharFormat(format);
}

void QWMainWind::on_actionBold()
{
    QTextCharFormat format=ui->textEdit->currentCharFormat();
    QFont font=format.font();
    font.setBold(!font.bold());
    format.setFont(font);
    ui->textEdit->mergeCurrentCharFormat(format);
}

void QWMainWind::spinbox_value(int FontSize)
{
    QTextCharFormat formatsize;
    formatsize.setFontPointSize(FontSize);
    ui->textEdit->mergeCurrentCharFormat(formatsize);
    progressbar->setValue(FontSize);
}

void QWMainWind::on_actionBlack()
{
    QPalette plet=ui->textEdit->palette();
    plet.setColor(QPalette::Text,Qt::black);
    ui->textEdit->setPalette(plet);
}

void QWMainWind::on_actionRed()
{
    QPalette plet=ui->textEdit->palette();
    plet.setColor(QPalette::Text,Qt::red);
    ui->textEdit->setPalette(plet);
}

void QWMainWind::on_actionBlue()
{
    QPalette plet=ui->textEdit->palette();
    plet.setColor(QPalette::Text,Qt::blue);
    ui->textEdit->setPalette(plet);
}

void QWMainWind::iniSignalSlots()
{
    connect(spinbox,SIGNAL(valueChanged(int)),this,SLOT(spinbox_value(int)));
    connect(ui->actionClear,SIGNAL(triggered(bool)),this,SLOT(on_actionClear()));
    connect(ui->actionCopy,SIGNAL(triggered(bool)),ui->textEdit,SLOT(copy()));
    connect(ui->actionCut,SIGNAL(triggered(bool)),ui->textEdit,SLOT(cut()));
    connect(ui->actionPaste,SIGNAL(triggered(bool)),ui->textEdit,SLOT(paste()));
    connect(ui->actionUnderline,SIGNAL(triggered(bool)),this,SLOT(on_actionUnder()));
    connect(ui->actionItalic,SIGNAL(triggered(bool)),this,SLOT(on_actionItalic()));
    connect(ui->actionBold,SIGNAL(triggered(bool)),this,SLOT(on_actionBold()));
    connect(ui->actionBlack,SIGNAL(triggered(bool)),this,SLOT(on_actionBlack()));
    connect(ui->actionRed,SIGNAL(triggered(bool)),this,SLOT(on_actionRed()));
    connect(ui->actionBlue,SIGNAL(triggered(bool)),this,SLOT(on_actionBlue()));
}

QWMainWind::QWMainWind(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWMainWind)
{
    ui->setupUi(this);
    iniUI();
    iniSignalSlots();
}

QWMainWind::~QWMainWind()
{
    delete ui;
}

