#include <ansi2.h>
#include <path.h>
inherit ITEM;
void create()
{
        set_name("鐵箱子", ({"iron box","box"}) );
        set("long", 
"一個鐵做的箱子，好像可以打開的樣子。\n"
);
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("no_get",1);
	set("no_drop",1);
        set("unit", "個");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
	add_action("open_box","open");
}

int open_box(string str)
{
	object me=this_player();
	object b,room;
	room=load_object(SDO_PAST+"nonhero/grav6");
	
	if(!me) return 0;
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="box" || str=="鐵箱子")
	{

	message_vision(
	HIG"\n$N打開箱子後，箱子忽然射出一道綠光。\n"NOR
	HIG"\n綠光消失之後，發現守護石獸已經站在$N的面前。\n"NOR,me);
	
	b=new(__DIR__"npc/wood_beast.c" );
	b->move(environment(this_object()) );

	destruct(this_object());
	
	room=set_temp("opened",1);
	return 1;
	}
}