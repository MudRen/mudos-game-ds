#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("�U��ۥ�",({ "stone armor","armor" }) );
        set("long","���ҤD���]��s�A�Ĵ��ۥ��y�A���m�W���A�߯ʲ­��C\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",3500);
                set("armor_prop/armor", 40);
                set("armor_prop/dodge",-40);
        }
        setup();
}

