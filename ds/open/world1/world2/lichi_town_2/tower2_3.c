
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
	set("short", "瞭望塔指揮室");
        set("long", @LONG
這個小房間就是瞭望塔的指揮室，中間放了一張辦公桌，桌上凌
亂的堆了許多瞭望報告紀錄。牆上掛了一些軍用雨衣，不過都已經破
舊不堪使用了。
LONG
);
	set("exits",([
	"east": __DIR__"tower2_2",
	]));
	set("objects",([
	__DIR__"../npc/malo_towerguard_25":1,
	]));
	set("light",1);
	create_door("east","木門","west",DOOR_CLOSED);
        setup();
//	set("map_long",1);     //show map as long
//        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

