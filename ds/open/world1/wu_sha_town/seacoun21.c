#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D��");
set("long",@LONG
�q�o�̥i�H�ܩ��㪺ť��n��ǨӤ@�ѳپx���n, ������
�L�c�a�O�㥩��, �_���ϩT�M�c�a, �۱q�n���ϧאּ������P�_
���ϦP���c�e!
LONG
    );
 set("exits",([ "north":__DIR__"seacoun20",
		"south":__DIR__"seacoun22",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            