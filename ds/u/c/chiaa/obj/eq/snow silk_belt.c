//u/c/chiaa/obj/eq/snow silk_belt.c
#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
    set_name(HIW"雪"HIB"蠶"MAG"腰帶"NOR,({"snow silk belt","belt"}) );
    set("long","用珍貴的雪蠶絲編製的腰帶。\n");

        if (clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(300);
                set("unit","條");        
                set("material","silk");
                set("armor_prop/armor",12);
                set("value", 3000);
        }
        setup();
}
