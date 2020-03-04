#include <ansi2.h>

inherit ITEM;

void create()
{
	set_name(YEL"木雪橇"NOR, ({ "wooden sledge", "sledge" }));

	set("long", @long
一個由木頭手製而成的木雪橇。
long);
	set("ridable",1);
	set("value", 1);
	set("speed", 0);

	setup();
}

int ride_before_action(object me)
{
	object ob=this_object();

	message_vision("$N一跳就跳上了"+this_object()->name()+"。\n",me);

	return 1;
}

int ride_after_action(object me)
{	
	message_vision("$N穩穩的坐在"+this_object()->name()+"的上面了。\n",me);
	
	return 1;
}

int ride_off_action(object me)
{
	message_vision("$N從"+this_object()->name()+"的跳了下來。\n",me);

	return 1;
}