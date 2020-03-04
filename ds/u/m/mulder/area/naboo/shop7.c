// Room: /u/s/sonicct/area/shop7.c

inherit ROOM;

void create()
{
	set("short", "市集");
	set("long", @LONG
這裡的情況和入口差不多激烈，但看來情況開始會有改善的
不過，最主要是小販們的自律。突然一群小販向你展開他的物品
給你買，你左閃右避才逃走了，真狼狽。往南是Naboo城的廣場。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road17",
  "south" : __DIR__"road18",
  ]));		 set("objects",([
  __DIR__"npc/antiquer":1,
 ]));
	set("no_kill",1);
	set("outdoors","land");
	set("room_type","shop");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
