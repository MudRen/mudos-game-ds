#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIR"�� "HIG"�H��"NOR,({ "mi armor","armor" }) );
        set("long","�@�󯫯����`�ҡC\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",3000);
                set("armor_prop/armor", 30);
                set("armor_prop/parry", 6);
        }
        setup();
}

