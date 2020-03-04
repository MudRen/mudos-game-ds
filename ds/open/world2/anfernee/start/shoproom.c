#include <path.h>
inherit ROOM;

void create()
{
	set("short", "夢幻福利站");
	set("long", @LONG
這裡是夢幻旅館的販賣部。這裡的東西大部分是林老闆撿回來的，所
以品質並不是很好，但也勉強能派上用場。這裡用的錢幣是目前一般通行
市面上所使用的現金。

LONG
	);
	set("objects", ([
	LUKY_NOW"test/npc/shoper" : 1,
	]) );
	set("exits", ([ /* sizeof() == 1 */
 "west" : __DIR__"hall",
	]) );
	set("light",1);
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_kill",1);
	setup();
}
