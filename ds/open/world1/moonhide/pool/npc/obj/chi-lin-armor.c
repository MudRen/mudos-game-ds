#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIW"�l�z"HIY"�������"NOR,({ "bomb-golden armor","armor" }) );
        set("long","�Q�ﳽ����ҡC\n");
        set_weight(7000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("material","steel");
                set("unit", "��" );
                set("value",7000);
        }
        set("armor_prop/armor", 40); 
        set("beast_armor_prop/armor", 40); 
        set("armor_prop/con",4);
        set("armor_prop/str",-1);
        set("armor_prop/dex",-1);
        set("armor_prop/int",-1);
        setup();
}
