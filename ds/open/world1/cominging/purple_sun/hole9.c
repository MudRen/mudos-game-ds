// 紫陽山頂端山洞內

inherit ROOM;

void create()
{
	set("short", "山洞內");
	set("long", @LONG
這裡是山上的一個山洞內，山洞內廣大，還有許多的野獸，奇怪的
是，這個山洞竟像個小廣場一樣，有模有樣，洞外的強風不時的颳進來
，呼呼的響。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hole8.c",
  "south" : __DIR__"hole6.c",
]));
	set("objects", ([
  __DIR__"npc/big_bear" : 2,
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("light",1);

	setup();
	replace_program(ROOM);
}
