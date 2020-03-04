#include <ansi.h>
inherit ITEM;

void create()
{
    set_name( "�������", ({ "pudu boat","boat" }) );
    set_weight(600);
        set("long",@LONG
����O�����`����̭��n�������A�A�i�H�b����W��m���~�έ���A
���m���h�����~����A�N���Ӫe��a�a�A�I�N(burn)����i����
��A�H����������t����C

�A�i�H�ϥΡuinspect�v���O���˵�����W�w�g��F�h�֪F��C
�A�i�H���u help �����`�v�����ԲӪ���T�C
LONG
);
    set_max_capacity(2000);
    set_max_encumbrance(2000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 99);
    }
    setup();
}

void init()
{
    add_action("do_light","burn");
    add_action("do_oil","inspect");
}

int ghost_stock = 0;      // ���~
int ghost_xiang = 0;     // ����


void countWeight() {
        int i;
        object* inv;
        
        ghost_stock = 0;
        ghost_xiang = 0;
        
    inv = all_inventory(this_object());
    if( !sizeof(inv) )
        return;

    for(i=0; i<sizeof(inv); i++)
    {
        if( inv[i]->id("_GHOST_STOCK_") )
                ghost_stock += inv[i]->query("time");
        else if( inv[i]->id("_GHOST_XIANG_") )
                ghost_xiang += inv[i]->query("time");
    }   
}




int dest_all() {
    object *inv;
    int i;
    inv = all_inventory(this_object() );
    for(i=0; i<sizeof(inv); i++)
    {
destruct(inv[i]);
    }
}
int getSize(string type) {
    object *inv;
    int i, total;
    inv = all_inventory(this_object() );
    if( !sizeof(inv) )
        return 0;

    total = 0;
    for(i=0; i<sizeof(inv); i++)
    {
        if( !inv[i]->id(type) ) continue;
        total ++;
    }

    return total;
}

int do_oil()
{
     countWeight();
    return notify_fail( sprintf("���%3d���@%4d�۷N�B%3d������@%4d�����B%2d������C\n",
                                                                getSize("_GHOST_STOCK_"), ghost_stock, 
                                                                getSize("_GHOST_XIANG_"),       ghost_xiang, 
                                                                getSize("_GHOST_STOCK2_")
                               ));
}

// �Ѩt�Ψӭp��ƶq
int getAmount() {
        int am = ghost_stock;
        // ���~�o�O������10��
    if( ghost_stock/10 > ghost_xiang)
                am = ghost_xiang;
        
        // ���~�V�h�A�I��V��
        if(am>1000000)  // �ʸU
                am /= 45;
        else if(am>500000)      // 50�U
                am /= 65;
        else if(am>100000)      // 10�U
                am /= 85;
        else if(am>10000)       // 1 �U
                am /= 95;
        else
                am /= (90+random(30));
        am = am/2 + random(am);
        
        if(am<1 && random(100) < 50 )   
                am = 1; // �� 50% ���v�ܤִ���1��
                
        return am;
}

string BOARD_D = "/open/world1/tmr/game/2008_ghost/board.c";
void light2(object me) {
    string msg;
    object paper;
        int amount, cb;
        
        amount = getAmount();
        
        if(amount>0) {
                cb = getSize("_GHOST_EXTRA_");
                if(cb>30) cb = 30;
                // �[�����\
                if( random(100) < cb ) {
                        amount *= 2;// 2��
                    msg = sprintf(HIW"\n\t%s(%s)"HIW"�Ҷi�檺"HIR"�������"HIW"����"HIM"���m����"HIW"�A�Ѥ�t����@"HIM"%4d��"HIW"�b��夤��o�c�A��b�O�\\�w�L�q�I�I\n"NOR,
                        me->name(), me->query("id"), amount );
                } else {
                    msg = sprintf(HIW"\n\t%s(%s)"HIW"�Ҷi�檺"HIR"�������"HIW"�A�Ѥ�t����@"HIM"%4d��"HIW"�b��夤��o�c�A��b�O�\\�w�L�q�I�I\n"NOR,
                        me->name(), me->query("id"), amount );
                }
                
                
                // �߯�
            paper = new("/open/world1/tmr/game/2008_ghost/paper.c");
            paper->set("amount", amount );
            paper->set("name", "�߯�(���B" + amount + "��)");
            paper->set("long", paper->query("long") + "���B��" + amount + "��");
            paper->move(me);
                BOARD_D->addScore(me, amount);
                
        // �S�O���Gdoll�A�C������5%���v
        if( getSize("_GHOST_STOCK2_")*5 > random(100) ) {
            new("/open/world1/tmr/game/2008_ghost/ghost_doll.c")->move(me);
            msg += HIG"\n\t\t�b�Ť��E�}�@�������A�ۥX�Ӱ\\�Y���������P�����A����"+me->name()+HIG"����W�C\n"NOR;
        }
    } else {
            msg = HBK"\n\t���������j�L�A"+me->name()+HBK"������W�����]�����_�ӡA�S�X�U�N�I�J�����A�����ܼv�C\n"NOR;
        }
        
        message("system",  msg, users() );
    dest_all();
    destruct( this_object() );
}

string PLACE = "/open/world1/wilfred/sand/room42";

int do_light(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg != "boat" )
        return notify_fail("�A�Q�n�I�N����H\n");
    if(me->is_busy() || me->is_fighting() )
        return notify_fail("�A�����ۡC�C\n");
    if( query("ignite") )
        return notify_fail("�o����w�g�I�N�F�C\n");
    if( base_name(environment(me)) != PLACE)
        return notify_fail("�A�o�b�Y�s�I�y�~���|��������C\n");

    countWeight();
    if( ghost_xiang < 1 )
        return notify_fail("����W�S��������A�L�k�I�N�C\n");

    message_vision(HIC"$N�I���I�N$n"HIC"��A��J�����A�u��$n"HIC"�W���U�����~���볣�����_���F...\n"NOR, me, this_object() );
    me->start_busy(2);
    set("ignite", 1);
    call_out("light2", 2 + random(8), me );
    return 1;
}

