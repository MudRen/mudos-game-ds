#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("無絕披風" ,({ "wu-jiue surocat","surcoat" }) );
        set("long","是個讓人穿了很舒服的一個披風。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(900);
        set("material", "skin");
        set("unit", "個" );
        set("value",600);
        set("armor_prop/armor",13);          
        set("armor_prop/dex",1);
                }
        setup();
}

