#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("�çL��A��",({ "pant of guard","pant" }) );
        set("long","�@��վB�����u�éҬ諸��A�ǡC\n");
        set_weight(150);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",1);
         set("material","cloth");
                set("unit", "��" );
       set("value",30);
                set("armor_prop/armor", 3);
        }
        setup();
}

