#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"薄雲"HIC"藍衫"NOR, ({ "cloud cloth", "cloth"  }) );
        set("long","這是一件輕飄飄的衣衫，雖然很輕薄，但是防禦力卻很高，
算是難得一見的護具了。\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value",4000);
                set("armor_prop/armor",  20);
                set("armor_prop/shield",  10);
                set("armor_prop/dex", 2);
                set("limit_dex",30);
                set("limit_level",30);
                set("material", "cloth");
                set("armor_prop/show_damage",1);
        }
        setup();
}


