// Room: /u/b/bennyng/area/room13.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����c");
	set("long", @LONG
�|�P���G�F�����᪺�խ��D�O�A�p�J�P�ү볳�K�D�n�q�L�����c�A�N
������X�����c�u�@�̡С������y�����t���h�D
LONG
	);
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room14",
  "west" : __DIR__"room15",
  "south" : __DIR__"room16",
  "north" : __DIR__"room10",
]));
        create_door("south", "�����c�j��", "north", DOOR_CLOSED);
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
