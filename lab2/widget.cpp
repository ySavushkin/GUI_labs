#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_invert_stateChanged(int arg1)
{
    if(arg1==2){
    ui->arrow->setText("<-");
    }
    else ui->arrow->setText("->");
}


void Widget::on_input_currentIndexChanged(int index)
{

}


void Widget::on_convert_clicked()
{
    int inputing = ui->textEdit->toPlainText().toInt();
    int inputing2 = ui->textEdit_2->toPlainText().toInt();
    int comboBoxIndex = ui->input->currentIndex();
    int comboBox2Index = ui->output->currentIndex();
    float answer = 0;
    QString arrow = ui->arrow->text();
    if(arrow == "->"){
        if(ui->length->isChecked()){
            if(comboBoxIndex==0){
                if(comboBox2Index==0){
                    answer = inputing*100;
                }
                else answer = inputing*1000;
            }
            if(comboBoxIndex==1){
                if(comboBox2Index==1){
                    answer = inputing*1000000;
                }
                else answer = inputing*100000;
            }
            if(comboBoxIndex==2){
                if(comboBox2Index==0){
                    answer = inputing*30.48;
                }
                else answer = inputing*304.80;
            }
            ui->textEdit_2->setText(QString::number(answer));
        }
        else if(ui->weight->isChecked()){
            if(comboBoxIndex==0){
                if(comboBox2Index==0){
                    answer = inputing*2.44;
                }
            }
            ui->textEdit_2->setText(QString::number(answer));
        }
        else{
            if(comboBoxIndex==0){
                if(comboBox2Index==0){
                    answer = inputing*100;
                }
                else answer = inputing*1000;
            }
            if(comboBoxIndex==1){
                if(comboBox2Index==1){
                    answer = inputing*1000000;
                }
                else answer = inputing*100000;
            }
            if(comboBoxIndex==2){
                if(comboBox2Index==0){
                    answer = inputing*30.48;
                }
                else answer = inputing*304.80;
            }
            if(comboBoxIndex==3){
                if(comboBox2Index==2){
                    answer = inputing*2.44;
                }
            }
            ui->textEdit_2->setText(QString::number(answer));

        }

    }
    else if(arrow == "<-"){
        if(ui->length->isChecked()){
            if(comboBox2Index==0){
                if(comboBoxIndex==0){
                    answer = inputing2/100;
                }
                else if(comboBoxIndex==1){ answer = inputing2/1000;}
                else answer = inputing2/30.48;
            }
            if(comboBox2Index==1){
                if(comboBoxIndex==0){
                    answer = inputing2/1000;
                }
                else if(comboBoxIndex==1){ answer = inputing2/10000;}
                else answer = inputing2/304.8;
            }
            ui->textEdit->setText(QString::number(answer));
        }
        else if(ui->weight->isChecked()){
            if(comboBox2Index==0){
                if(comboBoxIndex==0){
                    answer = inputing2/2.44;
                }
            }
            ui->textEdit->setText(QString::number(answer));
        }
        else{
            if(comboBox2Index==0){
                if(comboBoxIndex==0){
                    answer = inputing2/100;
                }
                else if(comboBoxIndex==1){ answer = inputing2/1000;}
                else answer = inputing2/30.48;
            }
            if(comboBox2Index==1){
                if(comboBoxIndex==0){
                    answer = inputing2/1000;
                }
                else if(comboBoxIndex==1){ answer = inputing2/10000;}
                else answer = inputing2/304.8;
            }
            if(comboBox2Index==2){
                if(comboBoxIndex==3){
                    answer = inputing2/2.44;
                }
            }
            ui->textEdit->setText(QString::number(answer));
        }
    }






}


void Widget::on_clear_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->length->click();
}


void Widget::on_length_toggled(bool checked)
{
    if(!checked){
    ui->input->removeItem(0);
    ui->input->removeItem(1);
    ui->input->removeItem(2);
    ui->output->removeItem(0);
    ui->output->removeItem(1);
    }
}


void Widget::on_length_clicked()
{
    ui->input->removeItem(0);
    ui->input->removeItem(1);
    ui->input->removeItem(2);
    ui->input->removeItem(3);
    ui->output->removeItem(0);
    ui->output->removeItem(1);
    ui->output->removeItem(2);
    ui->input->addItem("Метри");
    ui->input->addItem("Кілометри");
    ui->input->addItem("Фути");
    ui->output->addItem("Сантиметри");
    ui->output->addItem("Міліметри");
}


void Widget::on_weight_clicked()
{
    ui->input->removeItem(0);
    ui->input->removeItem(1);
    ui->input->removeItem(2);
    ui->input->removeItem(3);
    ui->output->removeItem(0);
    ui->output->removeItem(1);
    ui->output->removeItem(2);
    ui->input->addItem("Кілограми");
    ui->output->addItem("Фунти");
}


void Widget::on_weight_toggled(bool checked)
{
    if(!checked){
    ui->input->removeItem(0);
    }
}


void Widget::on_weight_released()
{
    ui->input->removeItem(0);
}


void Widget::on_length_released()
{
    ui->input->removeItem(0);
    ui->input->removeItem(1);
    ui->input->removeItem(2);
    ui->output->removeItem(0);
    ui->output->removeItem(1);
}


void Widget::on_choice_clicked()
{
    ui->input->removeItem(0);
    ui->input->removeItem(1);
    ui->input->removeItem(2);
    ui->input->removeItem(3);
    ui->output->removeItem(0);
    ui->output->removeItem(1);
    ui->output->removeItem(2);
    ui->input->addItem("Метри");
    ui->input->addItem("Кілометри");
    ui->input->addItem("Фути");
    ui->input->addItem("Кілограми");
    ui->output->addItem("Сантиметри");
    ui->output->addItem("Міліметри");
    ui->output->addItem("Фунти");
}


void Widget::on_choice_toggled(bool checked)
{
    if(!checked){
    ui->input->removeItem(0);
    ui->input->removeItem(1);
    ui->input->removeItem(2);
    ui->input->removeItem(3);
    ui->output->removeItem(0);
    ui->output->removeItem(1);
    ui->output->removeItem(2);
    }
}


void Widget::on_choice_released()
{
    ui->input->removeItem(0);
    ui->input->removeItem(1);
    ui->input->removeItem(2);
    ui->input->removeItem(3);
    ui->output->removeItem(0);
    ui->output->removeItem(1);
}


void Widget::on_text_size_valueChanged(int arg1)
{
    ui->textEdit->setFont(QFont("Arial", arg1));
    ui->textEdit_2->setFont(QFont("Arial", arg1));
    ui->arrow->setFont(QFont("Arial", arg1));
}

