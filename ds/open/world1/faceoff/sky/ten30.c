#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�s��p-�F�_��"NOR);
 set("long",@LONG
�A�O�ɤF�d���U�W�ש󪦤W�F�s��p, �u���o�̪��g�[
���M�O���⪺! ���s��p�O����̱T�򪺤s, �s�W�èS����
�㪺�D���ѧA�樫, �ݨӥu��Ϊ�(climb)���F!
LONG
    );
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
          object me,where1;
        string a;
        me = this_player();
        where1= load_object(__DIR__"ten31.c");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("���O�榡�G climb <��V> .\n");
        if( a!="west" )
                return notify_fail("�o�Ӥ�V�A�����L�h\n");
     if (a = "west")
    {
        message_vision(HIW"$N�q�s���W�u�ۦ���ԾԹ��������h....�C\n"NOR,me);
        me->move(where1);
    }
        return 1;
}
