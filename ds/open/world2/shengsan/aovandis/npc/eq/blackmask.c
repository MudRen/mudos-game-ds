#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("絲襪", ({ "silk stocking","stocking" }) );
	set_weight(2100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是一件黑色的絲襪。\n[可儲存裝備]\n");
		set("unit", "件");
		set("material", "silk");
		set("no_give",1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("value",180);
	}
	//============以下片段開放區域勿用, 否則會大混亂===============
	//==    若開放區域要寫此種偽裝eq , 必定要設為 Only One EQ    ==
	set("armor_prop/id",({"robber"}));
	set("armor_prop/name",({"蒙面大盜"}));
	set("armor_prop/short",({"蒙面大盜(Robber)"}));
	set("armor_prop/long",({"一個用黑褲襪罩住頭的蒙面大盜。\n"}));
	//==============================================================
	set("armor_prop/shield",15);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",20);
	setup();
}

int query_autoload() { return 1; }