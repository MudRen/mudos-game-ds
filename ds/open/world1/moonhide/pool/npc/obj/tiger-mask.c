#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIC"猛虎面罩"NOR, ({ "tiger mask","mask" }) );
        set_weight(3500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","龍骨所打造的面罩!\n");
                set("unit", "面");
        set("value",6600);
        set("material","gold");
        }
        set("armor_prop/con",1);
        set("armor_prop/int",1);
        set("armor_prop/bar",1); 
        set("armor_prop/blade", 3); 
        set("limit_lv",25);
        set("limit_con",40);
        setup();
}

