// Room: /u/a/acme/test/stone2.c

inherit ROOM;

void create()
{
	set("short", "高地");
	set("long", @LONG
這高地不廣，僅三丈長五尺寬的一條石縫。天生萬物，造化之奇
，此處可見一二。
LONG
	);
	set("no_clean_up", 0);
  set("exits", ([ /* sizeof() == 1 */
      "down" : __DIR__"swirl2",
  ]));
       set("objects",([
          __DIR__"npc/stone" : 1,
       ]) );

	setup();
	replace_program(ROOM);
}
