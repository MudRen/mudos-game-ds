// Room: /u/s/sonicct/area/road16.c

inherit ROOM;

void create()
{
	set("short", "Naboo���");
	set("long", @LONG
�o�ONaboo�����W�����A�o�̺شӤF���֪�c�C�ҥH���ޤF���֩���
����o�̡A�O��o��R���ͮ�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road5",
  "west" : __DIR__"shop6",
]));
	 set("objects",([
  __DIR__"npc/bee":3,
 ]));

	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
