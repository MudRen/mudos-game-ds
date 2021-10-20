#include <armor.h>
#include <ansi.h>
inherit ARMOR;
inherit F_UNIQUE;

void create()
{
        set_name(HIM "點液背鱗" NOR,({ "dab-aqua-armor","armor" }) );
        set("long",
"這是一大片「狡龍  點液」背上的鱗片，看其鱗片十分堅實渾厚。你\n"
"拿近鱗片想細看時，陡地發現整副鱗片散發出一股不知名的香味，不知吸\n"
"入(suck)過多，不知會不會產生什麼作用。\n"
);
	set_weight(18000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("volume",5);
        set("material", "leather");
        set("unit", "副" );
        set("limit_con",30);
        set("limit_level",15);
        set("value",16000);
        set("replica_ob",__DIR__"dab-aqua-armor2");
	set("armor_prop/armor",40);
        set("armor_prop/dex", -4);
	}
	set("beast_armor_prop/armor",40);
	set("beast_armor_prop/dex",-4);
	set("beast_armor_type","armor");
        setup();
}

void init()
{
	add_action("do_suck","suck");
}

int do_suck(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();

	if(!arg || arg!="點液背鱗") return 0;
        if( !ob->query("equipped") ) return 0;
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙著，沒有空做其他事。\n");
	if( me->query("hp") < 500 )
	{	
	message_vision("$N深深地吸了穿在身上的點液背鱗發出的香味。\n",me);
	tell_object(me,HIY"你覺得渾身似乎舒服了不少。\n" NOR);
	me->receive_heal("hp",35);
	}
	else 
	{
	message_vision("$N深深地吸了穿在身上的點液背鱗發出的香味。\n",me);
	tell_object(me,"你並沒有覺得有什麼不一樣。\n");
	}
	return 1;
}
