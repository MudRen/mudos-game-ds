#include <ansi.h> 
#include <armor.h>
inherit ARMOR;

void create() 
{
        set_name(HIY"�s��"HIC"�n"HIW"��"NOR,({ "dragon-soft armor","armor" }) );
        set("long","�����l���Ǫ��_�ҡA�ڻ��O�j�C�����s���骺�Y�����n�֩һs�����C\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","steel");
                set("unit", "��" );
       set("value",5000);
                set("armor_prop/armor", 46);
                set("armor_prop/shield",5);
        }
        setup();
}

