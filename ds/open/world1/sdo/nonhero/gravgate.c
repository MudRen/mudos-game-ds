#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short","英雄之墓大門");
        set("long",@LONG
穿過破洞後，來到一個石室。這是一個很乾淨的石室，並沒有一
般印象中的陰冷潮濕。石室的南方有一扇石門，看起來非常沉重，應
該不是人力所能開啟的,而門旁邊有一個半人高的石碑。
LONG
        );
        set("item_desc",([
        "石門":"這是一扇很沉重的門，門上寫著：此門只為忠義之士而開。\n",
        "石碑":"石碑上寫著『忠義』兩個大字，而且這個石碑看起來是可以轉動(turn)的。\n",
        ]));
        set("light", 0);
        set("exits",([
        "north" : __DIR__"h_d.c",
        ]));
        set("light", 0);
        setup();
}

void init()
{
	add_action("open_door","turn");
}

int open_door(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="石碑")
	{
	object me;
	me=this_player();
	
	message_vision(
	HIG"\n$N用力的抓著石碑，努力的旋轉著。\n"NOR
	HIG"\n當時石碑面對石門時，門慢慢的打開了。\n"NOR,me);

        set("item_desc",([
        "石門":"這是一扇很沉重的門，門上寫著：此門只為忠義之士而開。\n"
               "石門現在被打開了。\n",
        "石碑":"石碑上寫著『忠義』兩個大字，不過它現在已經被轉動過了。\n",
        ]));

	set("exits",([
	"north":__DIR__"h_d.c",
        "south" : __DIR__"grav1.c",
	]));
	
	set_temp("opened",1);
	return 1;
	}
}

void reset()
{
	set("exits", ([
        "north":__DIR__"h_d.c",
        ]));
        set("item_desc",([
        "石門":"這是一扇很沉重的門，門上寫著：此門只為忠義之士而開。\n",
        "石碑":"石碑上寫著『忠義』兩個大字，而且這個石碑看起來是可以轉動(turn)的。\n",
        ]));
	delete_temp("opened");
	::reset();
}