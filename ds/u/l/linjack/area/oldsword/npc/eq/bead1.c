#include <ansi.h>
#include <dbase.h>
#include <name.h>
inherit ITEM;
void create()
{
	set_name("算珠", ({ "abacus bead","bead" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是一顆十分普通的算珠, 不過你想不透這小東西怎麼會和算盤分開了？\n");
		set("unit", "顆");
		set("quantity",1);
		set("abacus/damage",10);
		set("abacus/unit","顆");
		set("abacus/name","小算珠");
		set("abacus/type","small");
		set("material", "wood");
	}
	setup();
}
void init()
{
	add_action("do_loadit", "loadit");
}
int do_loadit(string arg)
{
	string type,msg;
	object weapon;
	if( !this_object()->id(arg) ) return 0;
	if(!weapon = this_player()->query_temp("weapon"))
		return notify_fail("你身上並沒有算盤。\n");
	if( this_player()->is_busy() )
		return notify_fail("你上一個動作還沒有完成。\n");
	if(weapon->query_temp("loaded")==weapon->query("capacity"))
		return notify_fail("這個算盤又沒有缺算珠。\n");
	if(weapon->query("can_load")!=query("abacus/type"))
		return notify_fail("這個算盤的型式和這種算珠不合。\n");
	if(weapon->query_temp("abacus") && weapon->query_temp("loaded") > 0)
	{
		if(weapon->query_temp("abacus/name") != this_object()->query("abacus/name"))
			return notify_fail("你不能同時在一個算盤中裝兩種算珠.\n");
	}
	weapon->set_temp("loaded",weapon->query_temp("loaded")+query("quantity"));
	if(weapon->query_temp("loaded") > weapon->query("capacity"))
		weapon->set_temp("loaded",weapon->query("capacity"));

	weapon->set_temp("abacus",query("abacus"));	//附加屬性於槍上
	
	if( this_player()->is_fighting() ) this_player()->start_busy(2);
		else this_player()->start_busy(1);
	
	if(stringp(msg=query("load_msg")))
		message_vision(msg+"\n", this_player(),this_object());
	else message_vision("$N取出$n, 熟練的裝入"+weapon->name()+"中。\n", this_player(),this_object());
	tell_object(this_player(),"你看到這個"+weapon->name()+"上有"+chinese_number(weapon->query_temp("loaded"))+"顆算珠。\n");

	destruct(this_object());
	return 1;
}

