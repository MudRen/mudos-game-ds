// This is a room made by roommaker.
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�p�T��");
	set("long", @LONG
�@���ᬰ�H��²�����p�T�ΡA�b�o�U�H�ҳ��̩~�M�|�X�{�p������
�٭ˬO�O�H������Y�A���L�ݵۨ_�Ǫ��Ѱ��H�����W�a���U�a�ȡA���K
�P��ӧʶQ�ڻP�h�W�~�����j�P�t���C
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road11",
]));
	create_door("west", "���", "east", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
