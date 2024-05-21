#include "post.h"
#include "ui_post.h"

post::post(QWidget *parent, Users* u)
    : QDialog(parent)
    , ui(new Ui::post)
{
    ui->setupUi(this);
    user = u;
    this->ui->pushButton->setStyleSheet("background-color: #26a95f;border: 1px solid white;");
    setFixedSize(width(), height());
}

post::~post()
{
    delete ui;
}

void post::on_pushButton_clicked()
{

    if(ui->radioButton->isChecked())
    {
        int num = user->addVideo(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString()
                                 ,ui->lineEdit_3->text().toStdString()
                                 ,user->getusername()
                                 );
        QString destinationDir = QCoreApplication::applicationDirPath() + "/videos/" + to_string(num).c_str()+ ".mp4";

        QString filePath = QFileDialog::getOpenFileName(this, "Open Video", "", "Video Files (*.mp4 *.avi *.mkv)");
        QFile::copy(filePath, destinationDir);

    }
    else if(ui->radioButton_2->isChecked())
    {
        user->addArticle(Article(ui->lineEdit->text().toStdString(),
                                 ui->plainTextEdit->toPlainText().toStdString()
                                 ,ui->lineEdit_2->text().toStdString()
                                 ,ui->lineEdit_3->text().toStdString()
                                 ,user->getusername()
                                 ,Date::getCrrentDate(),"article"));
    }
    Article::saveArticles();
    QMessageBox::information(this,"INFO","Article Added Successfully");
    this->close();
}

