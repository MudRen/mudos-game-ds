#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("破布衣" ,({ "junk cloth" , "cloth" }) );
        set("long","會穿這種衣服的不是乞丐就是瘋子..。\n");
        set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value" , 5);
                set("material","cloth");
        }
        set("armor_prop/armor", 1);
        set("armor_prop/shield", 1);
        set("armor_prop/int", -1); 
        setup();
}
