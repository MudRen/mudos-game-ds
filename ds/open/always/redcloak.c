#include <armor.h>
#include <ansi2.h>

inherit SURCOAT;

int check(object me);

void create()
{
        set_name(HIR"紅色披肩"NOR ,({ "red cloak", "cloak" }) );
        set_weight(15000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("long", @long
這是一塊好輕的紅色的布，看起來並沒有什麼特別，是２００１年聖
誕節的特別禮品。

2001 Christmas Gifts By -Alickyuen@The.Dream.Of.Seven-
long);
                set("unit", "件");
                set("value", 1);
                set("no_sell", 1);
                set("material", "cloth");
	}
        set("armor_prop/con", -2);
        set("armor_prop/bar", 1);
        set("armor_prop/bio", -1);
        set("armor_prop/armor", -5);
	setup();
}

int query_autoload() { return 1; }

void init()
{
	object me= this_player();

	add_action("do_wear", "wear");

	if( !me ) return;
	if( !userp(me) ) return;

	check(me);
}

int check(object me)
{
	string id;

        id = me->query("id");
        if( id != "jill" // 第一名
        &&  id != "tear" // 第二名
        &&  id != "opek" // 第三名
        &&  id != "alickyuen"
&& id !="jangshow"
        )
        {
                tell_object(me, HIW"突然之間，"+this_object()->name()+HIW"的變得暗淡無色了。\n"NOR);
                this_object()->delete("armor_prop");
                this_object()->set("value", 0);
                this_object()->set("unit", "塊");
                this_object()->set("name", "爛布");
                this_object()->set("long", @long
這是一塊好輕的紅色的布，看起來並沒有什麼特別，是２００１年聖
誕節的特別禮品。但不知為什麼現在變得暗淡無光。

2001 Christmas Gifts By -Alickyuen@The.Dream.Of.Seven-
long);
		this_object()->set_durable(0);
		return 1;
        }
        if( this_object()->query("name") == "爛布" ) this_object()->create();
	if( environment(this_object()) == me )
	{
                this_object()->set("armor_prop/name", ({ "威風凜凜的"+me->query("name") }) );
  	}
	return 1;
}

int do_wear(string arg)
{
	object me;
	me = this_player();

        if( arg == "cloak" || arg == "red cloak" ) 
	{
		if( !this_object()->query_durable() )
			return notify_fail("你並沒有資格穿著這件ＥＱ。\n");
	}
}

