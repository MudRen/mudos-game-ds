// Room: /u/s/sonicct/area/road19.c

inherit ROOM;

void create()
{
	set("short", "Naboo城暗巷");
	set("long", @LONG
走過一個熱鬧的廣場後，你看覺這裡和剛才的廣場有好大的分別
在這裡的人不多，但是每個人都凶神惡殺的樣子，好像要殺了你一樣
，你心想要盡快離開這裡。往北走可以返回廣場。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road8",
 "southwest" : __DIR__"road20",
   ]));
		 set("objects",([
  __DIR__"npc/bru":1,
 ]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
