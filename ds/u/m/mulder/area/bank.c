// Room: /u/m/mulder/area/shop4.c

inherit ROOM;

void create()
{
	set("short", "新彼得銀行 -");
	set("long", @LONG
這是新彼得城的最大銀行，你可以在這�奡ㄣ琠峖s款．那麼
你一會兒可到新彼得城的商店街，來一次大購物．清一清你的錢
包，如你要存款那就要快了，因為可能有一些人正在虎視眈眈你
你的錢．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road5",
]));
	set("no_clean_up", 0);
	set("objects",([
__DIR__"npc/security" : 2,

	]));

set("light",1);
	setup();
	replace_program(ROOM);
}
