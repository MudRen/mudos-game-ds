#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"���n�u�{"NOR);
set("long",@LONG
�o�̬O�b�L��@�a�ᦳ�W���u�{, ���u�{���D�H, �B����, 
�]���U�ضǻ�, ���H���L�O�q���M�Ӫ��u�K, ���L�ۤv�`���ۤv
�O�I���H, ���L���ަp��, �L���������T�۷���!.
LONG
    );
 set("exits",([ "west":__DIR__"seacoun24",
]));
 set("objects", ([__DIR__"npc/bu" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}            