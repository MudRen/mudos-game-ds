#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("戰鬥皮甲", ({ "fur armor","armor" }) );
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一件輕皮甲, 看來不會影響活動!\n");
                set("unit", "件");
                set("material","fur");
                set("armor_prop/armor", 16);
        }
        setup();
}