#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�C�۴Y"NOR);

 set("long",@LONG
�C�⪺�j�ۥ��Q�b�a�O�W, �o�̬O�в��P���઺�@��, �۴Y��, ����
�b�W���L������ӥh, �۴Y��, �Ю{�p����@�몺��i.
LONG
    );
 set("exits",([ "south":__DIR__"guild6",
                "north":__DIR__"guild7",
                "west":__DIR__"center1",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

