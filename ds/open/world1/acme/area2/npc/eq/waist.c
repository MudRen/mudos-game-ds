#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name("人皮腰帶" ,({ "human skin waist","waist" }) );
        set("long","一個用人皮製成的腰帶，上頭還有乾掉的血跡，相當噁心。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(600);
        set("material", "skin");
      set("unit","條");
        set("value",0);
        set("armor_prop/armor", 3);
        set("limit_str",8);
        set("armor_prop/int",2);
        set_temp("apply/hit",-3);
        }
        setup();
}
