#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIG"�C��ô��"NOR ,({ "green surcoat","surcoat" }) );
        set("long","�o�O�@����K��j�����ܪӡA�۷��𭫡C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "silk");
        set("unit", "��" );
        set("value",400);
set("volume",3);
        }
          set("armor_prop/armor", 25);
          set("armor_prop/int", 2);
          set("armor_prop/sword", 20);
          set("armor_prop/dex", -2);
        setup();
}


