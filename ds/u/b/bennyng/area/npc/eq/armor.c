#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIW"�u���Z��"NOR, ({ "Saint armor","armor" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o��O�t��u�éҬ諸�Z�ҡA�㦳�ܦn�����m�O\n");
                set("unit", "��");
                set("material", "steel");
                set("value",5000);
                set("armor_prop/dex",-3);
                set("armor_prop/shield",3);
                set("armor_prop/armor", 20);
                set("armor_prop/dodge",-10);
        }
        setup();
}
