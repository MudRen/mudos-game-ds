#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(WHT"靈絲衣"NOR,({"soul-silk cloth","cloth"}));
        set("long","散發著神秘之氣的絲衣\n");
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "件");
                set("value",10000);
                set("limit_lv",20);
                set("armor_prop/int",3);
                set("armor_prop/dex",1);
                set("armor_prop/armor",5);
                set("armor_prop/show_damage",1);
        }
        setup();
}
