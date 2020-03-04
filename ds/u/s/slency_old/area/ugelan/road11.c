// This is a room made by roommaker.
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�@���ѫC�۩ҾQ������D�A�o�̪��H�ϵ}�֡A��Ǫ��Ъ٤]������
�}�¡C�F�䦳�@���T��s�����Ъ١A����e���F�@��_��A�j���O�A
�a���b�����ν\�a�C
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road10",
  "east" : __DIR__"road14",
]));
	create_door("east", "���", "west", DOOR_CLOSED);
	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
