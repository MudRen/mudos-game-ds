#include <ansi.h> 
#include <armor.h>
inherit BOOTS;

void create() 
{
        set_name("�����c",({ "rong boots","boots" }) );
        set("long","�A�X��~���ʩҬ諸�c�l�C\n");
        set_weight(8000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","skin");
                set("unit", "��" );
       set("value",1000);
                set("armor_prop/armor", 4);
                set("armor_prop/dodge",2);
        }
        setup();
}

