//u/c/chiaa/obj/eq/snow silk_belt.c
#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
    set_name(HIW"��"HIB"��"MAG"�y�a"NOR,({"snow silk belt","belt"}) );
    set("long","�άöQ���������s�s���y�a�C\n");

        if (clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(300);
                set("unit","��");        
                set("material","silk");
                set("armor_prop/armor",12);
                set("value", 3000);
        }
        setup();
}
