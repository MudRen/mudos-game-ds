#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�p�|"NOR);
 set("long",@LONG
���M���O�p�|�A�����u�O�@�Ӧb�@�������Ŧa�}�F�A
�o�̩_�Ǫ��_�X�F�@�ѴH��A�����D�H��O�q���̫_�X�Ӫ�
�H�H�N���A�Q���}�o��....
LONG
    );
 set("exits",([  "south":__DIR__"ten50",
    ]));
set("no_clean_up",0);set("item_desc",([
       "�}��":HIW"�H�𥿬O�q�o�̥X�Ӫ��A�]�\\�i�H�i�h�ݬݨs��?\n"NOR,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me,where1,where;
        string a;
        me = this_player();
        where1=load_object(__DIR__"ten53.c");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
    return notify_fail("���O�榡�G enter <�a�I> .\n");
        if( a!="�}��" )
                return notify_fail("�o�Ӧa��A�i���h\n");
        message_vision(HIW"$N�G���i�J�F�}�ޤ���..�C\n"NOR,me);
        me->move(where1);
        return 1;
}
