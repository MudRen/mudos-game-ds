#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
	set_name(HIG"翠玉戒"NOR, ({ "Jade ring","ring" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是一只很漂量的戒指, 聽說有什麼神奇的力量附加其中,\n"
                           "你可以試著配帶看看。\n");
		set("unit", "只");
		set("material", "jade");
//		set("no_drop",1);
		set("no_sac",1);
		set("value",25000);
		set("armor_prop/wit",1);
		set("armor_prop/int",4);
		set("armor_prop/armor", 5);
		set("wear_msg",HIG"$N戴上了這只翠玉戒, 頓時一股力場環繞$N周圍!"NOR);
		set("remove_msg",GRN"$N拿下了翠玉戒, 身邊力場漸漸散去.."NOR);
	}
	setup();
}

int query_autoload() { return 1; }