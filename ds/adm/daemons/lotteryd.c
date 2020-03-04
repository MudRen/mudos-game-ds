// �|�P�m ���q�m�� 
// -Tmr 2007/01/24
#include <ansi.h>
#define MAX_TICKET 9999
inherit F_SAVE;
inherit F_DBASE;

int times;                      //�ĴX��
int jack1;      // �S��
int jack2;      // �@���
int amount;             //��X�X�i
int flag;               //����O�_�i�H���

void generate_num();

void create()
{
        seteuid(getuid());
                set("name", "�|�P�m�N�m���F");
                set("id", "lotteryd");
        if( !restore() )
        {
                times=0;
                jack1 = jack2 = 0;
                        amount=0;
                        flag=0;
        }
}
string query_save_file() { return DATA_DIR + "lottery2"; }

int set_flag(int arg)
{
        if(arg>0) flag=1;
        else flag=0;
        return flag;
}

int query_max_ticket()
{
        return MAX_TICKET;
}

int find_ticket_num()
{
        return random(MAX_TICKET);
}

void generate_num()
{
        jack1 = random(MAX_TICKET); // 0 ~ MAX_TICKET
        jack2 = random(MAX_TICKET); // 0 ~ MAX_TICKET
        while(jack2 == jack1)
                jack2 = random(MAX_TICKET); // 0 ~ MAX_TICKET

        times += 1;
        amount = 0;
        save();
        flag = 1;
        return;
}

// �ʶR�@�iticket
object createTicket() {
        object ob;
        ob = new("/open/always/ticket.c");
        ob->set("time", LOTTERY_D->query_times() + 1 );
        ob->set("number", LOTTERY_D->find_ticket_num() );
        // �T�w��X�@�i
        LOTTERY_D->release_ticket();
 
        return ob;
}
int query_ticket_amount()
{
        return amount;
}

int release_ticket()
{
        amount++;
        return amount;
}

int can_buy_ticket()
{
        return 1;       // �`�O�i�H�R�A�����i�ơA�]���i�H�R���Ъ��Ʀr
//      return (amount<MAX_TICKET);
}


//�d�߶W�Ťj�����I
int query_jack1()
{
        return jack1;
}

//�d�߶W�Ťj�����I
int query_jack2()
{
        return jack2;
}

//�d�߲ĴX��
int query_times()
{
        return times;
}

// �P�_�O�_���� �^����=���ĴX��(-2~10)
// �Ǧ^��> -2:�|���}��, -1:�L���F, 0:�S��
// 99:�W�ż�
// �䥦���ơG�Q��ƥN��A���ƶq�B�Ӧ�ƥN��B���ƶq�A4A�Y���u40�v
int query_lottery(int num, int time)
{
        int na,nb;
        int p1,p2,p3,p4;
        int q1,q2,q3,q4;
        int k1,k2,k3,k4;
        int j1,j2,j3,j4;
        int temp;
        if( time < times) return -1;
        if(!flag || time>times) return -2;

        if(num==jack1)
                return 99;      // super jack
        if(num==jack2)
                return 40;      // 4A

        // �P�_�XA�XB
        na = nb = 0;
        k1 = k2 = k3 = k4 = 0;
        j1 = j2 = j3 = j4 = 0;

        temp = num;
        p1 = temp % 10;
        temp/=10;
        p2 = temp % 10;
        temp/=10;
        p3 = temp % 10;
        temp/=10;
        p4 = temp;

        temp = jack2;
        q1 = temp % 10;
        temp/=10;
        q2 = temp % 10;
        temp/=10;
        q3 = temp % 10;
        temp/=10;
        q4 = temp;
        
        if(p1==q1) {j1=k1=1; na++;}
        if(p2==q2) {j2=k2=1; na++;}
        if(p3==q3) {j3=k3=1; na++;}
        if(p4==q4) {j4=k4=1; na++;}


        if( p1 == q2 && k1 == 0 && j2 ==0) { k1=1;j2=1; nb++;}
        if( p1 == q3 && k1 == 0 && j3 ==0) { k1=1;j3=1; nb++;}
        if( p1 == q4 && k1 == 0 && j4 ==0) { k1=1;j4=1; nb++;}

        if( p2 == q1 && k2 == 0 && j1 ==0) { k2=1;j1 =1; nb++;}
        if( p2 == q3 && k2 == 0 && j3 ==0) { k2=1;j3 =1; nb++;}
        if( p2 == q4 && k2 == 0 && j4 ==0) { k2=1;j4 =1; nb++;}

        if( p3 == q1 && k3 == 0 && j1 ==0) { k3=1;j1 =1; nb++;}
        if( p3 == q2 && k3 == 0 && j2 ==0) { k3=1;j2 =1; nb++;}
        if( p3 == q4 && k3 == 0 && j4 ==0) { k3=1;j4 =1; nb++;}

        if( p4 == q1 && k4 == 0 && j1 ==0) { k4=1;j1 =1; nb++;}
        if( p4 == q2 && k4 == 0 && j2 ==0) { k4=1;j2 =1; nb++;}
        if( p4 == q3 && k4 == 0 && j3 ==0) { k4=1;j3 =1; nb++;}

        return na*10 + nb;
}

//�M���Ҧ�����
int clean_lottery()
{

        times=0;
        jack1 = -1;
        jack2 = -1;
        flag=0;
        save();
        return 1;
}
