#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("梟形皮甲", ({ "owl armor","armor" }) );
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一件有梟形輕皮甲, 看來不會影響活動!\n");
                set("unit", "件");
                set("material","skin");
                set("armor_prop/armor", 17);
        }
        setup();
}
