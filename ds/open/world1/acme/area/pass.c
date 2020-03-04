// Room: /u/a/acme/area/pass.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�̬O���Ѥs���ܰ��I�A�|�P�ɬO�s�L�A���q�ﶳ�A���_����i��
���r���A���n�i�q���ѫ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pass1",
  "south" : __DIR__"ndoor",
  "southwest" : __DIR__"lea15",
]));
	set("no_clean_up", 0);
    set("no_map",1);
     set("outdoors","land");

	setup();
        create_door("south","�_����","north",DOOR_OPENED,"nokey");
}
