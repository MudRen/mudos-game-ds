#include <armor.h>
inherit LEGGING;
void create()
{
        set_name("殘星護腿", ({ "break star legging","legging" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","傳說它是以亞力安星球的重金屬合成的護腿。\n");
                set("unit", "雙");
                set("material", "sheet");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1400);          
                set("wear_msg", "$N把$n裝到腿上去時, 似乎變胖了一倍??\n");
           }
        set("armor_prop/dodge",-2);
        set("armor_prop/armor",10);
        setup();
}

