#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s��p"NOR);
 set("long",@LONG
�A�O�ɤF�d���U�W�ש󪦤W�F�s��p, �u���o�̪��g�[
���M�O���⪺! ���s��p�O����̱T�򪺤s, �s�W�èS����
�㪺�D���ѧA�樫, �ݨӥu��Ϊ�(climb)���F!
LONG
    );
 set("exits",([  "down":__DIR__"ten27",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_climb","climb");
}
int do_climb(string arg)
{
        object me,where1,where2;
        string a;
        me = this_player();
        where1= load_object(__DIR__"ten30.c");
      where2 =load_object(__DIR__"ten32.c");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("���O�榡�G climb <��V> .\n");
        if( a!="north" )
                return notify_fail("�o�Ӥ�V�A�����L�h\n");
     if (a = "north")
    {
        message_vision(HIW"$N�q�s���W�u�ۥ_��ԾԹ��������h....�C\n"NOR,me);
        me->move(where1);
    }
        return 1;
}

