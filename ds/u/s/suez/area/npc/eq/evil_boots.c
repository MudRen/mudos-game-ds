
#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("邪氣靴" ,({ "evil boots","boots" }) );
        set("long","這是一雙普通的長靴，但是上面沾染了不少邪氣。\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
        set("unit", "雙" );
        set("value",1500);
        }
         set("armor_prop/armor", 5);
       set("armor_prop/shield", 2);
         set("armor_prop/dodge", 5);
        setup();
}