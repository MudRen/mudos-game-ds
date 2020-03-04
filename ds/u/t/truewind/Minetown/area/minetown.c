// Room: /u/t/truewind/Minetown/area/minetown.c

inherit ROOM;

void create()
{
	set("short", "礦村大門");
	set("long", @LONG
這是礦村的大門，門口附近堆滿了酒瓶和一些器械。兩道厚重的
白色牆壁自大門由東西延伸出去，繞成一個圓形，把整個村包圍了起
來。隱隱約約還可以聽見裡頭傳來各種吵雜的聲音。
LONG
	);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/t/truewind/workroom1.c",
  "south" : __DIR__"minetown1",
 "out":"/u/k/kkeenn/secret-area/min1",
]));

	setup();
	replace_program(ROOM);
}
