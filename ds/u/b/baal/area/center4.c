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
 set("exits",([ "east":__DIR__"center3",
                "north":__DIR__"guildg",
                "south":__DIR__"guildf", 
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
