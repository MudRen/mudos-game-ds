#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(NOR""YEL"沙人面具"NOR, ({ "desert mask","mask" }) );
        set_weight(700);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","沙漠中人們擋沙塵的面具\n");
                set("unit", "個");
                set("value",2400);
                set("material","fur");
                set("armor_prop/con",2);
                set("armor_prop/armor",4);
        }
        setup();
}

