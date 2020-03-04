#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIR"奇倪骨履"NOR ,({ "chini boots","boots"}) );
        set("long",@LONG
奇倪的外骨骼形成的護足,看起來不怎麼好用的樣子.
LONG);
                set_weight(1000);
                set("material", "diamond");
                set("unit", "對");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                set("armor_prop/wit", 0);
                set("armor_prop/bar", 0);
	set("armor_type", "boots");
        setup();
}

void init()
{
/*
        if( userp(environment(this_object()) ) )
        {
                add_action("do_wear", "wear");
                add_action("do_remove", "remove");

        }
*/
}

int do_wear(string arg)
{
        object me;

        me = this_player();

	if( !this_object()->query("equipped") ) {
        if( arg == "boots" || arg == "chini boots" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
                        set("wear_msg",HIW"$N套上了奇倪骨履,剎時間天搖地動,眾神獸的元靈進入$N的體內!\n"NOR);
    me->add_temp("wear_boots",1);
		me->add_temp("god_armor", 1);
                set("armor_prop/bar", 2);
                set("armor_prop/wit", 2);
                set_weight(1000);
                set("material", "diamond");
                set("unit", "對");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                }
                else {
                   if(me->query_temp("wear_boots") == 0)
                {
                        me->add_temp("god_armor", 1);
                        me->add_temp("wear_boots",1);
                }
                }
        }
	}
}

int do_remove(string arg)
{
        object me;

        me = this_player();
        if( this_object()->query("equipped") ) {
        if( arg == "boots" || arg == "chini boots" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
			this_object()->create();
			present("chini wrists", environment(this_object()))->create();
			present("maigu gloves", environment(this_object()))->create();
			present("maigu leggings", environment(this_object()))->create();
			present("wo cloak", environment(this_object()))->create();
			present("wo waist", environment(this_object()))->create();
			delete("wear_msg");
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_boots",-1);
			me->add_temp("apply/wit", -2);
			me->add_temp("apply/bar", -2);

                }
                else
                {
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_boots",-1);
                }
        }
	}
}

