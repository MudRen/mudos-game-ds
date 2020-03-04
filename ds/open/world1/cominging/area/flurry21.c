#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"樺葉小舍"NOR);
	set("long", @LONG

這裡是疾風門之中的一間客房，在這裡有一些的灰塵，牆板上也有
些壁虎，床舖橫擺屋中，燈火鮮明，有如桃外仙境，四周牆上題了幾首
詩，也掛了幾幅名畫，頗詩情畫意的樣子，正如其名，在小舍之中，不
時有些從外面樹上的樹葉飄進屋內，也偶爾幾隻動物在窗邊晃來晃去，
頗悠哉的樣子。

LONG
	);
	set("exits", ([
  "west" : __DIR__"flurry20.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me=this_player();
	if( arg!="名畫" )return 0;
	else {
		message_vision("$N推了推一下名畫，似乎有些聲音傳來。\n",me);
		return 1;
	}
}