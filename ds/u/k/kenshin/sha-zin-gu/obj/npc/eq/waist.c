#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name("無雙腰帶" ,({ "wu-shuang waist","waist" }) );
        set("long","是個讓人帶了很舒服的一個腰帶。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(900);
        set("material", "skin");
        set("unit", "個" );
        set("value",600);
        set("armor_prop/armor",2);          
       set("armor_prop/con",1);
                }
        setup();
}

