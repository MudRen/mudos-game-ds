// Room: /u/s/sonicct/area/road18.c

inherit ROOM;

void create()
{
	set("short", "Naboo�s��");
	set("long", @LONG
�o�O�q���s�����ߤ@�q�D�A�ѩ�Naboo�����H�����O�M���D�q
�̡A�ҥH���l���᪺�ɶ��j�h�ƤH���|����s���ͤѻ��a�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shop7",
  "south" : __DIR__"road8",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
