#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�u�@�A", ({ "work suit","suit" }) );
        set_weight(5500);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@�󺮤ҭ̤u�@�ɩҬ諸��A\n");
                set("unit","��");
                set("value",5000);
                set("material", "cloth");
                set("armor_prop/armor", 15);
        }
        setup();
}

