#include <armor.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name( "破爛衣服" ,({ "worn-out cloth","cloth" }) );
        set("long",
"一件破破爛爛的衣服，看起來髒聞起來臭，摸起來黏黏的，\n"
"最好是不要穿...\n"
);
        set_weight(105);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
        set("unit", "件" );
        set("value",0);
        set("armor_prop/armor",-5);
        set("armor_prop/dex",-5);
        }
        setup();
}
