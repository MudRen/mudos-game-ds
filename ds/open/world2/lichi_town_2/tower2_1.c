inherit ROOM;
void create()
{
	set("short", "瞭望塔二樓");
        set("long", @LONG
這裡是瞭望塔的二樓。你看到旁邊有個放東西的綠色儲物櫃，櫃
子旁邊擺了幾張椅子，頭上有個巨大的吊扇正在轉動，牆角還擺著一
些空酒瓶。
LONG
);
	set("exits",([
	"west" : __DIR__"tower2_2",
	"down": __DIR__"map_1_23",
	]));
	set("light",1);
	set("objects",([
	__DIR__"../npc/malo_towerguard_19":1,
	__DIR__"../obj/malo_towershelf":1,
	]));
        setup();
//	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

