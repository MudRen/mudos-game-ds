// Room: /u/s/slency/area/ugelan/god2.c
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"【"NOR"羽聖雅教堂"HIW"】"NOR);
	set("long", @LONG
這裡是本城最大的一座教堂, 你可以看見相當多的人正在這裡做禮
拜, 在彩色玻璃的折射之下, 教堂裡光線矇矓, 配合上大型管風琴的演
奏, 神聖的氣氛更加濃厚, 每個人正誠心的與神接觸, 你不禁也感到肅
穆莊嚴, 往裡面走可以到教堂後面的房舍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"god1",
  "in" : __DIR__"god3",
]));
	create_door("west", "大門", "east", DOOR_CLOSED);
	set("item_desc",(["彩色玻璃":"相當美麗的玻璃, 表面塗滿各色顏料, 在太陽的照射下, 顯得十分美麗\n"]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
