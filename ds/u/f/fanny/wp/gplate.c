#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(GRN "�C���Z��" NOR,({"guard plate","plate"}) );
        set("long","�@��x�L����ԥҡA�㦳�@�w�����m��O�C\n");
        set_weight(7500);
        set("unit","�M");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","�M");
        set("value",1000);           
        set("limit_con",18);
        set("limit_str",15);
        set("armor_prop/dex",-1);
        set("armor_prop/con",3);
                set("material","iron");
                set("armor_prop/armor",12);
        }
        setup();
}
