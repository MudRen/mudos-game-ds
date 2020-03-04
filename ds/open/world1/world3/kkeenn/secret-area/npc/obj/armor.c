#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("電磁光甲", ({ "power armor","armor" }) );
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這是一件由三千福特的電力交集而成的透明寶甲。\n");
                set("unit", "件");
                set("material", "gem");
                //set("no_sell",1);
                set("no_sac",1);
                set("value",1700);          
                set("wear_msg", "$N的身上突然衝出幾道電光包圍著$N。\n");
                set("unequip_msg", "$N按了一個開關, 電光在那一剎那間消失的無影無蹤。\n");
           }
        set("armor_prop/shield",15);
        set("armor_prop/dodge",5);
        set("armor_prop/armor",20);
        setup();
}


