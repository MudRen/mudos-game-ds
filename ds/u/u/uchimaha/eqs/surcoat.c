#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"NIKY"HIC"�ܭ�"NOR ,({ " niky surcoat","surcoat" }) );
        set("long","�o�O�Q���ܶ±M�Ϊ��@��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "surcoat");
        set("unit", "��" );
        set("value",400);
        
          set("armor_prop/armor", 20);
          set("armor_prop/shield", 20);
          set("armor_prop/hit",  100);
          set("armor_prop/dodge",  100);
          set("value", 1800);
        }
        setup();
}
