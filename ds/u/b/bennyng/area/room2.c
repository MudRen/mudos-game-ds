// Room: /u/b/bennyng/area/room2.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���Y�q�D");
	set("long", @LONG
�b�Q�G�������h���e������A�A�o�{���@�T�ԯ�����R���o�e�C�̭�
������R���b�M�c�]�԰��ۡC�A�o�{���@�u�����ѥ_�����ж��g��ӡA�A
�Q�i�਺�̴N�O�A���̫�ت��a�A�A�N�Q��B���e���h�D�D�D�D�D�D
LONG
	);
        set("exits", ([ /* sizeof() == 2 */

  "north" : __DIR__"room1",
  "south" : __DIR__"room3",
]));
        create_door("north","���","south",DOOR_CLOSED);
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
