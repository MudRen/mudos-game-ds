#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "木門");
	set("long", @LONG
在你的面前有一扇大大的木門，上面刻著許許多多的圖案，顏色鮮
豔，圖案之中有蛇、龍等吉祥物，門的下方有個小洞，似乎是水溝，並
不寬大，旁邊欄杆有些許的蘚苔，似無多人來此地的樣子，牆邊緊緊的
靠著門板。
LONG
	);
	set("exits", ([
  "north" : __DIR__"flurry28.c",
  "southdown" : __DIR__"flurry13.c",
]));
	create_door("north","木門","south",DOOR_CLOSED);
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
}
