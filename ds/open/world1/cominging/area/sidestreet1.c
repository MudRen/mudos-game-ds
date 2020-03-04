#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
	set("short", "側街中");
	set("long",@LONG
你在這裡聽到剛剛在西大街上所聽到的吵架聲，你仔細聽了聽，大
概是西邊的一戶人家，你看到那只是一個小小的三合院，上面寫著「龍
發堂」，你也攪不清楚那是什麼東西，北邊是往側街頭，而東邊則是繼
續往側街前進。
LONG
	);
	set("exits", ([
  "north" : __DIR__"sidestreet.c",
  "east" : __DIR__"sidestreet2.c",
  "enter" : __DIR__"quarrelhouse.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	create_door("enter","門","out",DOOR_CLOSED);
}
