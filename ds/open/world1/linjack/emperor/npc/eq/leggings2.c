#include <armor.h>
inherit LEGGING;
void create()
{
        set_name("脛甲" ,({ "leggings" }) );
        set("long","這個脛甲只包住大腿及小腿的一小部份, 看來防禦力\n"
                   "並不高, 但是對於腿部防禦仍然有不小的幫助。\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value" ,800);
                set("material","iron");
        }
        set("armor_prop/armor", 4);
        set("armor_prop/shield",2);
        setup();
}
