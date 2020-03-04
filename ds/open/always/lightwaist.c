#include <armor.h>
#include <ansi2.h>

inherit WAIST;

void create()
{
	set_name(HIW"鑽石腰帶"NOR ,({ "diamond waist", "waist" }) );
	set_weight(10000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("long", @long
這個有如一件裝甲重的鑽石腰帶，是由多粒鑽石打造而成的，是２０
０１年度中秋節『燈謎競逐』比賽大獎，帶上的鑽石排列有序，形成
了幾個字『中秋節快樂』，而那些鑽石由於太大的關係，閃閃發光，
有著照明的作用。

Mid-Autumn Festival Gifts By -Alickyuen@The.Dream.Of.Seven
long);
		set("unit", "條");
                set("value", 1);
                set("no_sell", 1);
		set("material", "diamond");
	}
	set("armor_prop/con",1);
	set("armor_prop/int",1);
	set("armor_prop/shield",15);
	set("armor_prop/armor",25);
	setup();
}

int query_autoload() { return 1; }

void init()
{
	object me= this_player();
        string id;

	add_action("do_wear", "wear");

	if( !me ) return;
	if( !userp(me) ) return;
        id = me->query("id");
        if( id != "bug"
        &&  id != "ttoopp"
        &&  id != "arboria"
        &&  id != "chchiyau"
        &&  id != "alickyuen"
        &&  id != "release"
        )
        {
                tell_object(me, HIW"突然之間，"+this_object()->name()+HIW"的光芒消失了。\n"NOR);
                this_object()->delete("armor_prop");
                this_object()->set("value", 0);
                this_object()->set("name","玻璃腰帶");
                this_object()->start_light(0);
		this_object()->set_durable(0);
                return;
        }
        if( this_object()->query("name") == "玻璃腰帶" ) this_object()->create();
	if( environment(this_object()) == me )
	{
		if( !this_object()->query_light() ) this_object()->start_light(1);
  	}
}

int do_wear(string arg)
{
	object me;
	me = this_player();

	if( arg == "waist" || arg == "diamond waist" ) 
	{
		if( !this_object()->query_durable() )
			return notify_fail("你並沒有資格穿著這件ＥＱ。\n");
	}
}
