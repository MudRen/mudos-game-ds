#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�����p�֦a");
 set("long",@LONG
�A���ߤ@�ӥ�������o�̨�, �o�O�@�ӥѥۦǩ��Һc��
���֦a, ���n���ʤf�F, �s�Ӥp�}���S��, �n���W�h²���O
���i�઺��, �b�F�䪺�����W, �u���@�p�O�C��, ��L�N�S
������F��F....
LONG
    );
set("item_desc",([
        "�C��":HIG"�A�o�{�C�󪺥ͮڳB�U�����@�ӯU�������_...\n"NOR,
      "���_":HIG"�o�ө��_�j���u������A�j�j�q�L(pass)....\n"NOR,
    ]));
set("no_clean_up",0);
set("outdoors","land");
set("no_recall",1);
set("no_map",1);
 setup();
}
void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me,where;
        string a;
        me = this_player();
        where = load_object(__DIR__"ten41");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("�A�n��L����?\n");
        if( a!="���_" )
                return notify_fail("�o�̨S�o�ӪF���\n");
        message_vision(HIW"$N�ĤO���q�p�p�����_�����X�h!\n"NOR,me);
      me->move(where);
        return 1;
}


