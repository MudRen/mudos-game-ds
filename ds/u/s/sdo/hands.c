#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(MAG"月夜"HIW"˙"BLU"十字墜"NOR, ({ "night hands","hands" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","這個小小的墜子，雖然不起眼，但是充滿了夜的思念。\n");
        set("unit", "條");
        set("material", "cloth");
        set("no_drop",1);
	set("no_sell",1);
        }
        set("armor_prop/wit",2);
        set("armor_prop/bio",1);
        set("armor_prop/bar",1);
        set("armor_prop/int",10);
        set("armor_prop/shield",25);
        set("armor_prop/show_damage",1);
        setup();
}

int query_autoload() { return 1; }
