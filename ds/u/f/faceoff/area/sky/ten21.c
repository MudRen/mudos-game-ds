#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_�ٮp"NOR);
 set("long",@LONG
�A���b���Ѿª�����A�]���樫�b�Q�U�j�s���Ĥ@�p --
�_�ٮp���s�y�W�A�ܩ�_�ٮp���s���h�N�O���Ѿ¤F�A�ӪF
�_��h�O�q�����p���D���A���p�����ѤU�Ĥ@�_�����W���A 
�]�\�A�ӥh¤���@�U.
LONG
    );
 set("exits",([  "northwest":__DIR__"ten23",
               "southeast":__DIR__"ten5",
                   "northdown":__DIR__"ten49",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}
int valid_leave(object me, string dir)
{
        if( dir== "northdown" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
