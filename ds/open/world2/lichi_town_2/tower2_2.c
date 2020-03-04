#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
	set("short", "瞭望塔二樓");
        set("long", @LONG
一走到這裡你立刻發現窗子旁的四個方形小洞，洞的後方放了幾
個木架子，看起來像是用來架槍的。窗子旁邊有個探照燈，用來夜間
觀察塔外的情況。
LONG
);
	set("exits",([
	"west" : __DIR__"tower2_3",
	"east": __DIR__"tower2_1",
	]));
	set("light",1);
	create_door("west","木門","east",DOOR_CLOSED);
        setup();
//	set("map_long",1);     //show map as long
//      replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

