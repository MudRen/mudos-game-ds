#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(MAG"��]"HIW"��"BLU"�e��"NOR, ({ "night boots","boots" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","��W�o���c����A�i�H�e��p���C\n");
                set("unit", "��");
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
