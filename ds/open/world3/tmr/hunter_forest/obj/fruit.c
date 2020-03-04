#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG "紫色果實" NOR,({"purply fruit","fruit"}) );
        set_weight(200);
        set("long",@long
這是一顆果皮呈紫色的果實，散發著一股酒香味，據說其果肉散發出
來的酒味更是香醇，常被用來誘捕某種動物。你看的出來果皮略厚，
要把皮剝(broke)下來，倒也不輕鬆。

long
);
        if(clonep() )
                set_default_object(__FILE__);
        else {
        set("value",1);
        set("material","plant");
        set("volume",1);
	set("food_remaining",2);
	set("heal_hp",20);
	set("heal_mp",20);
	set("heal_ap",20);
        }
        setup();
}

void init()
{
	add_action("do_broke","broke");
}

int do_broke(string arg)
{
	object me,ob;
	me=this_player();
	if(!arg || arg!="紫色果實") return 0;

	message_vision("$N將一顆果實的皮一層層地剝了下來。\n",me);
	ob=new(__DIR__"fruitb");
	ob->move(me);
	destruct(this_object());
	return 1;
}
