#include <armor.h>

inherit SURCOAT;

void create()
{
set_name("���",({"sweater"}) );
set("long"," �o�O�@��ܫO�x�����C\n");
set_weight(750);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "fur");
set("unit", "��");
                set("value", 1130);
set("armor_prop/armor",15);
set("armor_prop/defense",1);
set("level",15);
}
setup();
}
