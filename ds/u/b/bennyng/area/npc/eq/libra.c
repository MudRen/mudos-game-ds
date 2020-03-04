#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"天秤座黃金聖衣"NOR, ({ "Libra armor","armor" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這件就是黃道十二宮中第七宮的天秤座聖衣\n");
                set("unit", "件");
                set("material", "steel");
                set("value",20000);
                set("armor_prop/con",5);
                set("armor_prop/dex",-3);
                set("armor_prop/str",10);
                set("armor_prop/dodge",-10);
                set("armor_prop/shield",10);
                set("armor_prop/armor", 45);
                set("armor_prop/bar",5);
                set("wear_msg","$N穿上$n,$N感到有一股神力包圍著$N!");
                set("remove_msg","$N除下了$n,你的神力消失了");
        }
        setup();
}
