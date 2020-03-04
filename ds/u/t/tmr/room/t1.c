// Room: /u/t/tmr/room/t1.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�x�|");
	set("long", @LONG
�@�y���j���x�|�A���n�N�O�u�_�v���ѩСA
�u�O���f���ۨ���@�áA�ݨӷQ�i�h�ѩ�...
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"square.c",
  "south" : __DIR__"bookroom.c",
]));
       create_door("south", "���", "north", DOOR_CLOSED);
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/guard" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
