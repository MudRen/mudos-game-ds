// cloth.c
#include <armor.h>
inherit EQUIP;

void setup()
{
	int g,total;
	::setup();
	if( clonep(this_object()) ) return;
	set("armor_type", TYPE_CLOTH);
	set("equip_limbs",({"body"}));
	if(query("auto_set")==2) //�{�N�з�
	{
		g=weight();
		if(g>42000) total=((g-42000)/2300)+40;
		else if(g>25000) total=((g-25000)/1700)+30;
		else if(g>13000) total=((g-13000)/1200)+20;
		else if(g>5000) total=((g-5000)/800)+10;
		else total=g/500;
		set("armor_prop/armor",total);
		set("value",weight()*3/8);
		if(!query("limit_con"))	set("limit_con",weight()/1200);
		if(!query("armor_apply/dodge") && weight() > 6000 )
		set("armor_prop/dodge", - weight() / 4500 );
		return;
	}
	
	if( !query("armor_apply/dodge")
	&&	weight() > 5000 )
		set("armor_prop/dodge", - weight() / 5000 );
	if(!query("armor_limit/con"))	set("armor_limit/con",weight()/1200);
	if(!query("armor_prop/armor")) set("armor_prop/armor",weight()/500);
}

int is_armor(){ return 1; }

/*
void init()
{
	add_action("do_tear", "tear");
}

int do_tear(string str)
{
	object ob;

	if( !id(str) ) return 0;

	if( (string)query("material") != "cloth" )
		return notify_fail("�A�u�༹���ƪ���A�C\n");

	if( (int)query("teared_count") >= 4 )
		return notify_fail( name() + "���S�f�M�U���w�g�S���h�l�����i���F�C\n");

	message_vision("$N�q" + name() + "���U�@�������C\n", this_player() );
	add("teared_count", 1);
	ob = new("/obj/bandage");
	ob->set_name("�q" + name() + "���U������", ({ "cloth piece", "piece", "cloth" }) );
	if( !ob->move(this_player()) )
		ob->move(environment(this_player()));
	return 1;
}
*/