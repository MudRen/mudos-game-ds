// Room: /u/s/sonicct/area/road8.c

inherit ROOM;

void create()
{
	set("short", "Naboo�s������");
	set("long", @LONG
�o�ONaboo�����s�����ߡA�o�ONaboo���������g�`�Ӫ��a��C
���ݦb�Q����������@�ﱡ�Q���b���ɤ��A�M�@�Z���b�U�Ѫ��ѤH
�A�ӳo�̩��F��i�H����Naboo�����j�˪L�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road9",
  "north" : __DIR__"road18",
  "west" : __DIR__"road7",
  "south" : __DIR__"road19",
]));
		 set("objects",([
  __DIR__"npc/beauty":1,
__DIR__"npc/child":2,
__DIR__"npc/citizen":2,
 ]));

	set("outdoors","road");
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
