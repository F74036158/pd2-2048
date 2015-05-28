#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include "block.h"
#include <iostream>
#include <time.h>
using namespace std;
block b[17];
void MainWindow::keyPressEvent(QKeyEvent *event){
    srand(unsigned(time(NULL)));
    int i,truetime=0;
    if(win==false){
        for(i=0;i<17;i++){
            b[i].move2=false;
        }

        if(event->key()==Qt::Key_Left){
            moveleft();
            plusleft();
            moveleft();
        }
        if(event->key()==Qt::Key_Right){
            moveright();
            plusright();
            moveright();
        }
        if(event->key()==Qt::Key_Up){
            moveup();
            plusup();
            moveup();
        }
        if(event->key()==Qt::Key_Down){
            movedown();
            plusdown();
            movedown();
        }
        for(i=0;i<17;i++){
            if(b[i].move2)
                truetime++;
        }
        movefalse();
        shownum();
        if(truetime!=0){
            rand2();
        }
    }
    QString str=QString::number(sco);
    ui->score->setText(str);
    winn();
    gameover();
}
void MainWindow::winn(){
    int i;
    for(i=1;i<17;i++){
        if(b[i].num==2048&&wintime==false){
            win=true;
            wintime=true;
            ui->gameover->setPixmap(QPixmap(":/new/prefix1/wing.jpg"));
            ui->conti->setIcon(QPixmap(":/new/prefix1/continue.png"));
            ui->conti->show();
        }
    }
}

void MainWindow::gameover(){
    int i,j;
    bool allnzero=true,allcantplus=true;
    for(i=1;i<17;i++){
        if(b[i].num==0){
            allnzero=false;
        }
    }
    for(i=1;i<17;i=i+4){
        for(j=i;j<i+4;j++){
            if(b[j].num==b[j+1].num&&j!=i+3){
                allcantplus=false;
            }
            if(b[j].num==b[j+4].num&&j<13){
                allcantplus=false;
            }
        }
    }
    if(allnzero&&allcantplus){
        ui->gameover->setPixmap(QPixmap(":/new/prefix1/gameoverg.jpg"));
    }
}

void MainWindow::movefalse(){
    int i;
    for(i=0;i<17;i++){
        b[i].move=false;
    }
}

void MainWindow::moveleft(){
    int i,j,k;
    for(i=1;i<17;i=i+4){
        for(j=i+1;j<i+4;j++){
            for(k=i;k<j;k++){
                if(b[j].num!=0){
                    if(b[k].num==0){
                        b[k].num=b[j].num;
                        b[j].num=0;
                        b[k].move2=true;

                    }
                }

            }
        }
    }
}
void MainWindow::moveright(){
    int i,j,k;
    for(i=4;i<17;i=i+4){
        for(j=i-1;j>i-4;j--){
            for(k=i;k>j;k--){
                if(b[j].num!=0){
                    if(b[k].num==0){
                        b[k].num=b[j].num;
                        b[j].num=0;
                        b[k].move2=1;

                    }
                }
            }
        }
    }
}
void MainWindow::moveup(){
    int i,j,k;
    for(i=1;i<5;i++){
        for(j=i+4;j<17;j=j+4){
            for(k=i;k<j;k=k+4){
                if(b[j].num!=0){
                    if(b[k].num==0){
                        b[k].num=b[j].num;
                        b[j].num=0;
                        b[k].move2=1;

                    }
                }
            }
        }
    }
}
void MainWindow::movedown(){
    int i,j,k;
    for(i=13;i<17;i++){
        for(j=i-4;j>0;j=j-4){
            for(k=i;k>j;k=k-4){
                if(b[j].num!=0){
                    if(b[k].num==0){
                        b[k].num=b[j].num;
                        b[j].num=0;
                        b[k].move2=1;

                    }
                }
            }
        }
    }
}
void MainWindow::plusleft(){
    int i,j,k;
    for(i=1;i<17;i=i+4){
        for(j=i+1;j<i+4;j++){
            for(k=j-1;k<j;k++){
                if(b[j].num==b[k].num&&b[k].move==false&&b[j].num!=0){
                    b[k].num=b[k].num+b[j].num;
                    b[j].num=0;
                    sco=sco+b[k].num;
                    b[k].move=true;
                    b[k].move2=true;
                }
            }
        }
    }
}
void MainWindow::plusright(){
    int i,j,k;
    for(i=4;i<17;i=i+4){
        for(j=i-1;j>i-4;j--){
            for(k=j+1;k>j;k--){
                if(b[j].num==b[k].num&&b[k].move==false&&b[j].num!=0){
                    b[k].num=b[k].num+b[j].num;
                    b[j].num=0;
                    sco=sco+b[k].num;
                    b[k].move=true;
                    b[k].move2=true;
                }
            }
        }
    }
}
void MainWindow::plusup(){
    int i,j,k;
    for(i=1;i<5;i++){
        for(j=i+4;j<17;j=j+4){
            for(k=j-4;k<j;k=k+4){
                if(b[j].num==b[k].num&&b[k].move==false&&b[j].num!=0){
                    b[k].num=b[k].num+b[j].num;
                    b[j].num=0;
                    sco=sco+b[k].num;
                    b[k].move=true;
                    b[k].move2=true;
                }
            }
        }
    }
}
void MainWindow::plusdown(){
    int i,j,k;
    for(i=13;i<17;i++){
        for(j=i-4;j>0;j=j-4){
            for(k=j+4;k>j;k=k-4){
                if(b[j].num==b[k].num&&b[k].move==false&&b[j].num!=0){
                    b[k].num=b[k].num+b[j].num;
                    b[j].num=0;
                    sco=sco+b[k].num;
                    b[k].move=true;
                    b[k].move2=true;
                }
            }
        }
    }
}
void MainWindow::rand2(){
    int i,n0=0,y=0,a=rand()%16+1,c=rand()%10;
    bool num4=false;
    if(c==1){
        num4=true;
    }
    for(i=1;i<17;i++){
        if(b[i].num!=0){
            n0++;
        }
        if(n0==16){
            return;
        }
        if(b[i].loc==a&&b[i].num==0&&!num4){
            b[i].num=2;
            switch (b[i].loc) {
            case 1:ui->b1->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 2:ui->b2->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 3:ui->b3->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 4:ui->b4->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 5:ui->b5->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 6:ui->b6->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 7:ui->b7->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 8:ui->b8->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 9:ui->b9->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 10:ui->b10->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 11:ui->b11->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 12:ui->b12->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 13:ui->b13->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 14:ui->b14->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 15:ui->b15->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            case 16:ui->b16->setPixmap(QPixmap(":/new/prefix1/2.png"));y=1;break;
            default:
                break;
            }
        }
            else if(b[i].loc==a&&b[i].num==0&&num4){
                b[i].num=4;
                switch (b[i].loc) {
                case 1:ui->b1->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 2:ui->b2->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 3:ui->b3->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 4:ui->b4->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 5:ui->b5->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 6:ui->b6->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 7:ui->b7->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 8:ui->b8->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 9:ui->b9->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 10:ui->b10->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 11:ui->b11->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 12:ui->b12->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 13:ui->b13->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 14:ui->b14->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 15:ui->b15->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                case 16:ui->b16->setPixmap(QPixmap(":/new/prefix1/4.png"));y=1;break;
                default:
                    break;
                }
        }
    }
    if(y==0){
        rand2();
    }
}
void MainWindow::bloc(){

    int i;
    for(i=1;i<17;i++){
        b[i].loc=i;
    }
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->exit->setIcon(QPixmap(":/new/prefix1/exit.png"));
    ui->reset->setIcon(QPixmap(":/new/prefix1/reset.png"));
    ui->frame->setPixmap(QPixmap(":/new/prefix1/frameg.jpg"));
    sco=0;
    win=false;
    wintime=false;
    bloc();
    rand2();
    rand2();
    shownum();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::shownum(){
    int i;
    for(i=1;i<17;i++){
        switch (b[i].loc) {
        case 1:switch(b[i].num){
            case 0:ui->b1->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b1->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b1->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b1->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b1->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b1->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b1->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b1->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b1->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b1->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b1->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b1->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b1->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 2:switch(b[i].num){
            case 0:ui->b2->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b2->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b2->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b2->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b2->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b2->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b2->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b2->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b2->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b2->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b2->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b2->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b2->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 3:switch(b[i].num){
            case 0:ui->b3->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b3->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b3->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b3->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b3->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b3->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b3->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b3->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b3->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b3->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b3->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b3->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b3->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 4:switch(b[i].num){
            case 0:ui->b4->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b4->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b4->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b4->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b4->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b4->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b4->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b4->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b4->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b4->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b4->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b4->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b4->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 5:switch(b[i].num){
            case 0:ui->b5->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b5->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b5->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b5->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b5->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b5->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b5->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b5->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b5->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b5->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b5->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b5->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b5->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 6:switch(b[i].num){
            case 0:ui->b6->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b6->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b6->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b6->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b6->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b6->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b6->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b6->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b6->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b6->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b6->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b6->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b6->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 7:switch(b[i].num){
            case 0:ui->b7->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b7->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b7->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b7->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b7->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b7->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b7->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b7->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b7->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b7->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b7->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b7->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b7->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 8:switch(b[i].num){
            case 0:ui->b8->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b8->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b8->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b8->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b8->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b8->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b8->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b8->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b8->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b8->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b8->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b8->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b8->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 9:switch(b[i].num){
            case 0:ui->b9->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b9->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b9->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b9->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b9->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b9->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b9->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b9->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b9->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b9->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b9->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b9->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b9->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 10:switch(b[i].num){
            case 0:ui->b10->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b10->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b10->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b10->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b10->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b10->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b10->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b10->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b10->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b10->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b10->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b10->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b10->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 11:switch(b[i].num){
            case 0:ui->b11->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b11->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b11->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b11->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b11->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b11->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b11->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b11->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b11->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b11->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b11->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b11->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b11->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 12:switch(b[i].num){
            case 0:ui->b12->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b12->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b12->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b12->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b12->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b12->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b12->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b12->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b12->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b12->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b12->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b12->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b12->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 13:switch(b[i].num){
            case 0:ui->b13->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b13->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b13->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b13->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b13->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b13->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b13->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b13->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b13->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b13->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b13->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b13->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b13->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 14:switch(b[i].num){
            case 0:ui->b14->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b14->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b14->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b14->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b14->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b14->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b14->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b14->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b14->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b14->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b14->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b14->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b14->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 15:switch(b[i].num){
            case 0:ui->b15->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b15->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b15->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b15->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b15->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b15->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b15->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b15->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b15->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b15->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b15->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b15->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b15->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;
        case 16:switch(b[i].num){
            case 0:ui->b16->setPixmap(QPixmap(":/new/prefix1/0.png"));break;
            case 2:ui->b16->setPixmap(QPixmap(":/new/prefix1/2.png"));break;
            case 4:ui->b16->setPixmap(QPixmap(":/new/prefix1/4.png"));break;
            case 8:ui->b16->setPixmap(QPixmap(":/new/prefix1/8.png"));break;
            case 16:ui->b16->setPixmap(QPixmap(":/new/prefix1/16.png"));break;
            case 32:ui->b16->setPixmap(QPixmap(":/new/prefix1/32.png"));break;
            case 64:ui->b16->setPixmap(QPixmap(":/new/prefix1/64.png"));break;
            case 128:ui->b16->setPixmap(QPixmap(":/new/prefix1/128.png"));break;
            case 256:ui->b16->setPixmap(QPixmap(":/new/prefix1/256.png"));break;
            case 512:ui->b16->setPixmap(QPixmap(":/new/prefix1/512.png"));break;
            case 1024:ui->b16->setPixmap(QPixmap(":/new/prefix1/1024.png"));break;
            case 2048:ui->b16->setPixmap(QPixmap(":/new/prefix1/2048.png"));break;
            case 4096:ui->b16->setPixmap(QPixmap(":/new/prefix1/4096.png"));break;
            }break;

        default:
            break;
        }
    }
}



void MainWindow::on_reset_clicked()
{

    int i;
    for(i=0;i<17;i++){
        b[i].num=0;
    }
    ui->gameover->clear();
    sco=0;
    win=false;
    wintime=false;
    ui->score->clear();
    rand2();
    rand2();
    shownum();
}

void MainWindow::on_conti_clicked()
{
    win=false;
    ui->gameover->clear();
    ui->conti->close();
}
