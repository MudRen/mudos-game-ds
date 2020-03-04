#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short", "小墓室");
        set("long",@LONG
這一間墓室比起外面的墓室明顯的小了很多，不過仍然算是十分
的寬敞。角落有一張桌子，桌子上好像有東西在那一樣。不過越靠近
那個東西，感覺越來越熱了。
LONG
        );
        set("exits", ([
        "east" : __DIR__"grav1.c",
        ]));
        set("item_desc",([
        "桌子" : "一張石桌，上面放著一件盔甲，你可以拿起來(get)。\n",
        ]));

        set("light", 0);
        setup();
}

void init()
{
	add_action("get_armors","get");
}

int get_armors(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="armor" || str=="盔甲")
	{
	object me,b;
	me=this_player();

	message_vision(
	RED"\n當$N正打算拿起盔甲時，盔甲忽然燒了起來。\n"NOR
	RED"\n一隻守護獸從火裡慢慢的走了出來。\n"NOR,me);

	b=new(__DIR__"obj/npc/fire_beast.c" );
	b->move(__DIR__"grav2.c" );
	
        set("item_desc",([
        "桌子" : "一張石桌，上面什麼東西也沒有。\n",
        ]));

	set_temp("opened",1);
	return 1;
	}
}
void reset()
{
	delete_temp("opened");
	set("item_desc",([
        "桌子" : "一張石桌，上面放著一件盔甲，你可以拿起來(get)。\n",
        ]));
	::reset();
}