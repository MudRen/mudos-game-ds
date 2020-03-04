inherit MOBROOM;
void create()
{
	set("short", "走廊");
	set("long", @LONG
這是一條不長不短的走廊，走廊上燈火通明，如烈陽般之大，走廊
上偶爾飛進幾隻嘰嘰喳喳叫的麻雀，吃著地上掉下的米穀，也可充飢一
番，走廊上的屋頂好像有些漏洞，並不穩定的樣子。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry25.c",
  "east" : __DIR__"flurry27.c",
]));
	set("no_clean_up", 0);
	set("chance", 60);
        set("mob_amount",4);
        set("mob_object",({
  __DIR__"npc/sparrow",
}));
	set("light",1);
	setup();
}
