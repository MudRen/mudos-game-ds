#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(CYN"��"HIW"��"CYN"�Z"HIW"��"NOR,({ "shang-woo armor","armor" }) );
        set("long","�ѥȪZ���t���ߩҦ������ҡA�Q���­��A�����m�O�Q���C\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("material","steel");
                set("unit", "��" );
                set("value",6000+random(1030));
                set("armor_prop/armor", 42);
        }
        setup();
}


