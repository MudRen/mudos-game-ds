// Room: /u/b/bennyng/area/room16.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����c�j��");
	set("long", @LONG
�o�̴N�O�Q�G�c���̫�@�Ӯc�С������c�D�u�n���������y�����t��
�h�A�A�N�i�H����ЬӤF�D�b�o�̧A�o�{�F�@��ǨơA������o�̷|�Ǩ�
�}�}�խ��H�H
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room13",
  "westdown" : __DIR__"room17",
]));
        set("objects", ([
  __DIR__"npc/guard.c":4,
]));
        create_door("north", "�����c�j��", "south", DOOR_CLOSED);
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
