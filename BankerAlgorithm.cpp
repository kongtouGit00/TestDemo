#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QList>

class Customer : public QThread{

protected:
    int m_need;
    int m_current;
    QMutex m_mutex;

    void run(){

        qDebug() << objectName() << " begin to apply money...";

        bool condition = false;

        do{
            m_mutex.lock();
            condition = m_current < m_need;
            m_mutex.unlock();

            msleep(15);

        }while(condition);

        qDebug() << objectName() << "end(get enough money)...";
    }

public:
    Customer(int need, int current){

        this->m_need = need;
        this->m_current = current;
    }

    void addMoney(int money){

        m_mutex.lock();
        this->m_current += money;
        m_mutex.unlock();
    }

    int getCurrent(){

        int ret = 0;

        m_mutex.lock();
        ret = this->m_current;
        m_mutex.unlock();

        return ret;
    }

    int backMoeny(){

        int ret = 0;

        m_mutex.lock();
        ret = this->m_current;
        this->m_current = 0;
        m_mutex.unlock();

        return ret;
    }

    int getNeed(){

        return this->m_need;
    }
};

class Bank : public QThread{

protected:
    int m_total;
    QList<Customer*> m_list;

    void run(){

        qDebug() << objectName() << "begin to give money...";

        int index = -1;

        do{
            index = -1;
            //需求得到满足的客户，返回资源
            for(int i = 0; i < m_list.count(); ++i){

                if(m_list[i]->getCurrent() == m_list[i]->getNeed()){

                    qDebug() << objectName() << " take back money from " << m_list[i]->objectName() << " " << m_list[i]->getNeed();
                    m_total += m_list[i]->backMoeny();
                }
            }

            qDebug() << objectName() << " current: " << m_total;
            int toGet = 0x00FFFFFF;
            for(int i = 0; i < m_list.count(); ++i){

                if(m_list[i]->isRunning()){

                    int tmp = m_list[i]->getNeed() - m_list[i]->getCurrent();
                    if(toGet > tmp){

                        tmp = toGet;
                        index = i;
                    }
                }
            }

            if(index >= 0){

                if(toGet <= m_total){

                    qDebug() << objectName() << " give money to: " << m_list[index]->objectName();
                    --m_total;
                    m_list[index]->addMoney(1);

                }else{

                    qDebug() << objectName() << " terminate: " << m_list[index]->objectName();
                    m_total += m_list[index]->backMoeny();
                    m_list[index]->terminate();
                }

            }

        }while(index >= 0); //如果index < 0，就意味着已经没有需要资源的客户了

        qDebug() << objectName() << "end to give money...";
    }

public:
    Bank(int total){

        this->m_total = total;
    }

    void addCustomer(Customer* customer){

        m_list.append(customer);
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Customer P(8, 4);
    Customer Q(3, 2);
    Customer R(11, 2);

    Bank bank(2);

    bank.addCustomer(&P);
    bank.addCustomer(&Q);
    bank.addCustomer(&R);

    P.setObjectName("P");
    Q.setObjectName("Q");
    R.setObjectName("R");

    bank.setObjectName("Bank");

    P.start();
    Q.start();
    R.start();

    bank.start();

    return a.exec();
}
