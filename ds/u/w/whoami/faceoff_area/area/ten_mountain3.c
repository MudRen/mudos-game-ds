#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�U�D"NOR);

 set("long",@LONG
�A�����ǴN�O�Q�U�j�s���[���j���k���F, �j�����T�h�Ӱ�, 
���誺�Q�U�j�s�U�p�]�U�ۮ���, �h�h���|, �b�A���_��O�@��
�T�ê����f, �F��h�O�@�Ӥp�p���s��.
LONG
    );
 set("exits",([ "north":__DIR__"ten_mountain4",
                "south":__DIR__"ten_mountain1",
                "east":__DIR__"ten_mountain2",

    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
