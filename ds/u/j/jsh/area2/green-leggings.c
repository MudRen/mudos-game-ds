#include <armor.h>
#include <ansi.h>
inherit LEGGING;
void create()
{
        set_name(CYN"�M�C�@��"NOR,({ "green leggings","leggings" }) );
        set("long","�o�O�@���⪺�@��[0;1;36m�[1mA[0m���@�y�M�h�����Ƹ˳�[0;1;36m�[1mC[0m\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",10);
         set("material","steel");
                set("unit", "��" );
       set("value",2000);
                set("armor_prop/armor", 7);
                set("armor_prop/dodge",10); 
                set("armor_prop/dex",1);        }
        setup();
}

