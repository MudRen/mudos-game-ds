// Room: /u/l/lestia/area/sn4.c

inherit ROOM;

void create()
{
 set("short", "北方大森林");
	set("long", @LONG

你走在一片長楊木樹的林子裡，抬頭看見的是濃密的枝葉，低頭看到的
是地氈一般厚厚的落葉。楓葉由黃轉紅，彷彿時序進入秋季，景致美麗如詩
，你用輕快的步伐前進，不忍用力踩踏落葉，深怕發出聲想，使風景如玻璃
般破碎消失。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("no_map",1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sn5",
  "east" : __DIR__"sn5",
  "north" : __DIR__"sn3",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
