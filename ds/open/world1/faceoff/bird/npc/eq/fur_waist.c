#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
        set_name("獸皮巾帶",({"fur waist","waist"}) );
        set("long","一條用獸皮製成的皮帶。\n");
      set_weight(200);
        set("unit","條");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","條");        
                set("material","fur");
                set("armor_prop/armor",2);
        }
        setup();
}
