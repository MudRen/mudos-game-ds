#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "淺海");
        set("long", HIY"這裡有一個深深的海洞, 看來就是玲瓏魚的居所了\n"NOR);
	set("exits",([
  "west" : __DIR__"map_9_8",
]));
	set("item_desc",([
  "海洞":"一個小小的海洞, 你可以放東西(put xxx in 海洞)進去看看.\n"
]));
	setup();
	set("map_long",1);     //show map as long
}

void init()
{
        add_action("do_put","put");
}

int do_put(string arg)
{
	object me,tackle,f;
	object room = environment(this_player());
	me=this_player();

	if( arg != "tackle in 海洞") return 0;
	if(!objectp(tackle=present("gold tackle",me) ) )
		return notify_fail("你身上並沒有可以反光的漁網。\n");
	message_vision("$N拿起一個發著黃色光芒的漁網扔進海洞。\n",me);
	if (room->query_temp("catch") == 0)
	{
		message_vision(HIY "忽然一條螢光小魚衝了出來！！\n" NOR,me);
        f = new("/open/world1/npc/light_fish");
		f->move(__DIR__"map_9_9");
		room->set_temp("catch",1);
	}
	else message_vision("但是$N什麼也沒發現...。\n",me);
	return 1;        
}
