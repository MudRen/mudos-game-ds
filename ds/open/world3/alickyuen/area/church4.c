// updated 26/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Church＠Secret"NOR);
	set("long", "進來這裡後，你感覺到這樣異常陰暗。你不禁顫抖了起來。與此同時，
你四處看看後發現了好像有一些可怕的東西正看著你‥‥‥\n");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"church2.c",

]));
set("light",1);

	set("objects", ([ /* sizeof() == 1 */
 // __DIR__"npc/lu.c" : 1,
]));
	setup();
	replace_program(ROOM);
}
/*--遠古時代的生物地邪正在虎
視眈眈的看著你--看來不殺掉牠你是無法平安地走出去了。另想辦法吧﹗可能還有辦法離開的
*/