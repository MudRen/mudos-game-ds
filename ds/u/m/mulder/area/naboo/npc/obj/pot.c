inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("都诀", ({ "drinking machine","machine"}));
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get",1);
		set("no_sac",1);
                set("long", "场都诀竚倒筁┕都ノ\n");
                set("unit", "场");
                set("value", 20);
                set("heal_ap",45+random(6));
                set("heal_mp",45+random(6));
                set("heal_hp",45+random(6));
                  set("water_remaining",100);
	set("drink_msg","$N眖都诀狹〣翽〣翽耻碭\n");
	set("finish_drink_msg","$N盢緇耻\n");
        }
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me;
	if( !this_object() ) return 0;
	if( !this_object()->id(arg) ) return 0;
	me=this_player();
    if(me->query("level")>5)
	{
return notify_fail("猔種都诀禟眎ボ: セ都诀矗ㄑ单き產
都ノ\n");
	}
	else return ::do_drink(arg);
}

