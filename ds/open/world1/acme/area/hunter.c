// Room: /u/a/acme/area/hunter.c
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "���");
     set("light",1);
	set("long", @LONG
�o�̬O�@���ᬰ²�����p�ΡA�Τ��U�u���@�i��ȡA��W���F����}
�A�٦��@�Ѥj�H���Y���A���観�ӥX�f�A�O�q���p�Ϊ���|�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"backyard",
  "south" : __DIR__"pass8",
]));
    set("objects",([
       __DIR__"npc/hunter" : 2,
    ]) );
	set("no_clean_up", 0);
	setup();
       create_door("west", "���", "east", DOOR_CLOSED);
}
