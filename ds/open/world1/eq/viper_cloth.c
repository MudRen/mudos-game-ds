#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(MAG"蟒錦戰衣"NOR ,({ "viper cloth","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
這是傳說中以水龍之皮所製成的戰袍, 可以提供相當良好的防禦力!
LONG
     );
                set("unit", "件");
                set("value",10000);
                set("material", "steel");
        }
                set("armor_prop/shield",2);
                set("armor_prop/con",2);
                set("armor_prop/armor", 25);

        setup();
}


