#include <armor.h>
#include <ansi.h>
inherit ARMOR;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"�۲�"NOR,({"stone-armor","armor"}) );
        set("long","�o�O�@��۰�������A�O�j�N��d�U�Ӫ��䤤�@�󯫾��C\n");
        set_weight(12500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
set("value",5000);
set("material","rock");
set("armor_prop/armor", 30);
        }
        setup();
}
