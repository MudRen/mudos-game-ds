#include <armor.h>
#include <ansi.h>
inherit ARMOR; 
void create()
{
        set_name("��m",({ "green dress","dress" }) );
        set("long","�k�l�Ҭ諸�s�����m�A�o��O��⪺�C\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","cotton");
        set("unit", "��" );
        set("value",1000);
        set("armor_prop/armor", 1); 
        } 
        setup();
}