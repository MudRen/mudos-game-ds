#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�s��"NOR);
 set("long",@LONG 
���e�o�f�ƤQ�~���j���O�o�ǧ����ͬ����̥D�n���ѵ��ӷ�
�A�A�X�Q�~�e�N�Q�o�̷�a���~�������X�ӡA�ݵ۸̭��M�����b
�S�ŷx���u���A�A���T�Q�ܤ@�f�I
LONG
    );

       set("exits",([
       "north":__DIR__"town8",
       "south":__DIR__"town6",
       "west":__DIR__"town14",
       "east":__DIR__"town15",
           ]));

        set("objects", ([
           ]));
        set("item_desc",([

                  "�j��" : GRN"�@�f�֦��ƤQ�~���v���j���A�i�ѤH����(drink water from well)�C\n"

                ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}        
void init()
{
          add_action("do_drink","drink");
}

void gone(object me)
{
        if( !me ) return ; 
        me->set_temp("str_drinked", 0);
        me->add_temp("apply/str", -5);
        me->set("hp", me->query("hp")/2);
        tell_object(me, "�A�}�lı�o�h�¤F�C\n");
}

void again()
{
        set("drinked", 0);
}

int do_drink(string str)
{

        object me;
        me = this_player();
        if(str!="water from well") return notify_fail("�A�Q�ܤ���H�I\n");
        if(me->is_fighting()) return notify_fail (HIC"�԰�������ܡC\n"NOR);
        if( query("drinked") )
                return notify_fail("���̪������G���Ӱ��F�C\n");
        me->add("hp", 50); 
        me->add("mp", 50);
        me->add("ap", 50); 
        if( me->query_temp("str_drinked") || me->query("level") > 4 )
                return notify_fail("�Aı�o���̪����Q���M�D�C\n");
        tell_object( me, "�A�ܤF���̪�������Aı�o�������O�q����X�ӤF�C\n");
        me->add_temp("apply/str", 5);
        me->set_temp("str_drinked", 1);
        set("drinked", 1);
        return 1;
}



