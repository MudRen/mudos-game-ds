#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"風恙小舍"NOR);
	set("long", @LONG

這裡是疾風門四大舍之一的風恙小舍，名故其實，當然是有許多的
風才會叫做風恙，在小舍周圍沒有高大的樹林，所以當風大時，小舍裡
就會充滿了沙子，當然也會比較涼快。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"flurry37.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
}

void init()
{
	call_out("delay",2,this_player());
}

void delay(object me)
{
	if( environment(me)!=this_object())return;
	else {
		write(HIY"你發現這裡的風特別的大！\n"NOR);
		return;
	}
}
