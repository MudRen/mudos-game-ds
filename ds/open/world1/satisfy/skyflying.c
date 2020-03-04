#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name(HIB"翔天翼"NOR, ({ "sky flying wing","wing","cloak" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件披風上畫了一對絕美的飛翼, 令你十分著迷,\n"
                           "應該是極品之一。\n");
		set("unit", "件");
		set("material", "cloth");
//		set("no_drop",1);
		set("no_sac",1);
		set("value",40000);
		set("armor_prop/dex",3);
		set("armor_prop/dodge",7);
		set("armor_prop/shield",5);
		set("armor_prop/armor", 5);
	}
	setup();
}

int query_autoload() { return 1; }