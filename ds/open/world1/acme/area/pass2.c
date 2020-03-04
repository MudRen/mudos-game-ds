// Room: /u/a/acme/area/pass2.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�A���b�o�d�骺�s���W�A�s���ƬO�T��A�p�ۧG���F������A�ᬰ��
��A���F�i�q���ѫ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"wdoor",
  "west" : __DIR__"pass3",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
        create_door("northeast","�諰��","southwest",DOOR_OPENED,"nokey");
}
