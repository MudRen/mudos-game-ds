#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("爛木條", ({ "junk stick" , "stick" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("material","plant");
                set("long", "這根爛木條地上隨便撿都有, 你正思考著你幹嘛拿著它。\n");
                set("value",1);
        }
        init_staff(1);
        setup();
}
