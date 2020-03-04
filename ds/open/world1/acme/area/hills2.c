// Room: /u/a/acme/old_area/hills2.c
inherit ROOM;
void create()
{
	set("short", "黃沙陵");
	set("long", @LONG
你身處在黃沙陵之上，四周盡是沙子，不久你感覺到好像有東西在拉
著你的腳，你心中不禁的想起是否日前所殺之人的冤魂來索命了，你的手
抖動著，卻是不寒而慄，還是快快離開此處較好。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hills1",
  "west" : __DIR__"hills3",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
