#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(MAG"月夜"HIW"˙"BLU"疾煉"NOR, ({ "night boots","boots" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","穿上這雙鞋之後，可以疾行如火。\n");
                set("unit", "雙");
                set("material", "cloth");
        set("no_drop",1);
	set("no_sell",1);
        set("value",1);
        }
        set("armor_prop/dex",5);
        set("armor_prop/dodge",30);
        set("armor_prop/armor",10);
        setup();
}

int query_autoload() { return 1; }
