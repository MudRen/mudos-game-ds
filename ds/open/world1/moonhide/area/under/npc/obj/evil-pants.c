#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(HIB"���ѿ�"NOR,({ "chaos pants","pants" }) );
        set("long","�Ѥ��]������w�ƦӦ����Ǥl�C\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",4000);
        }  
        set("armor_prop/str",1); 
        set("armor_prop/armor", 9);  
        setup();
}

