
#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"�����H��"NOR,({ "joh ji armor","armor" }) );
        set("long","�o�O�@��x�L�Ҭ�۪��ԥҡA�Q���@��C\n");
        set_weight(12000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","steel");
        set("unit", "��" );
        set("value",4500);
        set("armor_prop/armor", 22);
        set("armor_prop/shield",10);
        }
        setup();
}

