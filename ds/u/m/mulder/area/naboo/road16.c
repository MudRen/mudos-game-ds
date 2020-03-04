// Room: /u/s/sonicct/area/road16.c

inherit ROOM;

void create()
{
	set("short", "Naboo花園");
	set("long", @LONG
這是Naboo城有名的花園，這裡種植了不少花卉。所以給引了不少昆蟲
飛到這裡，令到這兒充滿生氣。
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
