#include <armor.h>
inherit F_UNIQUE;
inherit LEGGING;
void create()
{
        set_name("玄天脛甲" ,({ "sky leggings","leggings" }) );
        set("long","這個脛甲只包住大腿及小腿的一小部份, 看來防禦力\n"
                   "並不高, 但是據說穿上去後腳程會快很多。\n");
        set_weight(4000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value" ,4500);
                set("material","steel");
                set("replica_ob",__DIR__"leggings2");
        }
        set("armor_prop/armor", 7);
        set("armor_prop/shield",4);
        set("armor_prop/dex",2); 
        setup();
}
