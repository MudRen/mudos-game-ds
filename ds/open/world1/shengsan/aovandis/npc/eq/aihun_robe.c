#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
	set_name(BLU"艾魂法袍"NOR,({"ai-hun robe","ai-hun","robe"}) );
	set("long","傳說中的艾魂所珍愛的法袍之一，它不時的發出躡人魂魄般黯藍的光澤。\n");
	set_weight(3300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "件");
		set("value",28300);
        	set("armor_prop/sou",1);
		set("armor_prop/bar",-1);
        }
        setup();
}

int query_autoload() { return 1; }
