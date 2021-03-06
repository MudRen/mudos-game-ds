// Room: /u/s/suez/tsing-yu/map_7_7.c

inherit ROOM;

void create()
{
	set("short", "廣場東");
	set("long", @LONG
    東邊飄來陣陣笑語，琴瑟之聲悠悠不斷。幾個年輕的士子站在街口對
著來往的女孩子品頭論足。一些有錢人打扮的珠光寶氣，乘著馬車來來去
去。四周的街樹上掛滿了花燈，打扮的五顏六色，一群穿著美麗的女子一
邊談笑一邊將紙花絲蝶一類的東西往樹上綁，偶而走來的貴婦人經過以後
留下了令人窒息的香氣，但是眼光卻從來不在任何東西上停留。

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "southwest" : __DIR__"map_8_6",
  "east" : __DIR__"map_7_8",
  "north" : __DIR__"map_6_7",
  "northwest" : __DIR__"map_6_6",
  "west" : __DIR__"map_7_6",
  "south" : __DIR__"map_8_7",
]));

	setup();
	replace_program(ROOM);
}
