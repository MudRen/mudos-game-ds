// Room: /u/a/acme/area/pass7.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�s��");
	set("long", @LONG
���B�K�O�q���ѫ����s���A�����@�h�i�ݨ��ѫ��������A�����V�F��
�h���@���p�ˡA�٦��y�j����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"edoor",
  "east" : __DIR__"wewd",
]));
	set("no_clean_up", 0);
       set("outdoors","land");

	setup();
        create_door("west","�F����","east",DOOR_OPENED,"nokey");
}
