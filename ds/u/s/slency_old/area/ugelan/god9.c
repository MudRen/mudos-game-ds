// Room: /u/s/slency/area/ugelan/god9.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�̬O�@�����������Y�A�ѳo�̤@�����e���i�H��F�@�ӯ�������
���A�o�̨��Ǫ������Q�����R�A�����۷����A����M���w�O�Y�H
��F�ܦh���߫�b���U�o�ǴӪ��W�C
LONG
	);
	

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"god10",
  "south" : __DIR__"god3",
]));
	create_door("north", "���", "south", DOOR_CLOSED);
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
