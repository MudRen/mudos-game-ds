#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIR"���]�Z��"NOR,({ "evil armor","armor" }) );
        set("long","���]���W�Ҭ諸���ҡA���m�O�۵M���b�ܤU�C\n");
        set_weight(15000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",20000);
                set("armor_prop/armor", 46);
                set("armor_prop/parry", 10); 
                set("armor_prop/dodge",-10);   
 
    }
        setup();
}

