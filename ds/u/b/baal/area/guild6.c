#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"���G�t�Y"NOR);

 set("long",@LONG
�o�̬O�@���Q�ۥۿj���j�۴Y, ���X���j�G�b�۴Y�����ӭ��h, �ݰ_
�ӫ²r�L��...
LONG
    );
 set("exits",([ "south":__DIR__"guild5",
                "north":__DIR__"center",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

