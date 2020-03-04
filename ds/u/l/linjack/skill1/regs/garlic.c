inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("苦蒜", ({ "smell bad garlic", "garlic" }));
        set("long",@LONG
這是一種特別的蒜頭, 味道比一般料理用到的蒜頭要來得苦,
它是一種藥材, 以製作治皮外傷的藥為主, 它可以生吃, 不過嘗
起來的味道有多爛就不得而知囉。
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
		set("value", 20);
                set("heal",([
			"hp":5,
			"mp":-25,
			"ap":20,
		]));
		set("attr",([
			"hp":0,
			"mp":0,
			"ap":0,
			"wound":4,
			"yang":0,
			"yin":1,
			"fol":0,
			"animal":0,
			"plant":1,
			"needfire":40,
			"mixedtime":0,
			"poundtime":-1,
			"can_eat":1,
		]));
                set("food_remaining", 1);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) || !this_object()->query("attr/can_eat") ) return 0;
        me=this_player();
        if(me->query("mp")<24)
        {
                return notify_fail("你的精神力(MP)已經不夠了, 再吃就破表囉。\n");
        }
        else
        {
                set("heal",([
			"hp":5,
			"mp":-25,
			"ap":20,
		]));
                return ::do_eat(arg);
        }
}
