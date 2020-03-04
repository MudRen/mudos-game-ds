// Room: /u/b/bennyng/area/room4.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ЬӤj��");
	set("long", @LONG
�o�̬O�Q�G�x�᪺�ЬӤj���A�|�B�D�`�����A�������@�i�j�ȡA
�O�ЬӱM�Ϊ��D�o�̬O�ЬӳB�z��`�ưȪ��a��A�D�ФŶi�D���_�O
�ЬөҦ��a��D
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room5",
  "north" : __DIR__"room3",
]));
       create_door("south", "�j������", "north", DOOR_CLOSED);
        set("objects", ([
  __DIR__"npc/guard.c":4,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
