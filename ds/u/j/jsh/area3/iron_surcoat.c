#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(WHT"�K���ܭ�"NOR,({ "iron surcoat","surcoat" }) );
        set("long","�o�O�@�󧹥����K���s�����ܭ�[0;1;36m�[1mA[0m�~���୮[0;1;36m�[1mA[0m�����m�O��[0;1;36m�[1mC[0m\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",800);
                set("armor_prop/armor", 10);
                
        }
        setup();
}

