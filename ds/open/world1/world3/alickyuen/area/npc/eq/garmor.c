#include <armor.h>
#include <ansi.h>
inherit ARMOR;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"�۲�"NOR,({"stone-armor","armor"}) );
        set("long","�o�O�@��۰�������A�O�j�N��d�U�Ӫ��䤤�@�󯫾��C\n");
        set_weight(1000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
  set("value",3000);
  set("material","iron");
  set("armor_prop/armor", 10);
        }
        setup();
}
