// Room: /u/b/bennyng/area/room1.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ЬӪ׫�");
	set("long", @LONG
�@�i�ӡA�A�N�Q�Ьӱj�j���O�q�~��C��A�ߩw�Ӫ��ɭԡA���U�|�P
�A�o�{�o�̪����{�{���\�]�A��z�o���������C�ӱЬӴN�@�ӤH���b����
������A�Y���ҫ䪺��V�X���D�D�D�D�D�D
LONG
	);
        set("light",1);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room2",
]));
        create_door("south","���","north",DOOR_CLOSED);
        set("outdoors","land");
        set("objects", ([
  __DIR__"npc/Gemini.c":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
