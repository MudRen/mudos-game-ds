#include <ansi.h> 
#include <armor.h>
inherit BOOTS;

void create() 
{
        set_name(HIW"�u®�c"NOR,({ "up boots","boots" }) );
        set("long","�����l���Ǫ��c�l�A�c�����u�ʯS�O�n�A�N���u®������A�ܦ��u�O�C\n");
        set_weight(8000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","skin");
                set("unit", "��" );
       set("value",3500);
                set("armor_prop/armor", 8);
                set("armor_prop/dodge",10);
        }
        setup();
}

