#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"���p"NOR);
 set("long",@LONG

             �o�̤@���L��⪺�@���A�A���򳣬ݤ����I�I

LONG
    );
 set("exits",([  "south":__DIR__"ten50",
    ]));
set("no_clean_up",0);set("item_desc",([
       "��⪺�@��":HIG"�b�@���������������@���p�|....\n"NOR,
      "�p�|":HIW"�p�|�b�@�����Y���Y�{�A�A�i�H���W(walk on) �o���p�|\n"NOR,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_walk","walk");
}
int do_walk(string arg)
{
        object me,where1,where;
        string a;
        me = this_player();
        where1=load_object(__DIR__"ten52.c");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "on %s", a )!=1 )
    return notify_fail("���O�榡�G walk on <�a�I> .\n");
        if( a!="�p�|" )
                return notify_fail("�o�Ӥ�V�A�����L�h\n");
        message_vision(HIW"$N���i�F�@������..�C\n"NOR,me);
        me->move(where1);
        return 1;
}
