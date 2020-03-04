// Room: /u/s/slency/area/ugelan/sell.c

inherit ROOM;

void create()
{
	set("short", "當鋪");
	set("long", @LONG
這裡是一間大型當鋪，櫃子裡擺滿了奇珍異寶，乍看之下幾乎都是
價值連城的寶物，想不到在這街角偏僻的地帶會有這麼一間大當鋪，你
可以將身上物品典當在此，也可以向老闆搜購你所想要的寶物。往西走
可以回到街道上。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road7",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
