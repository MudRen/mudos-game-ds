#include <armor.h>

inherit SURCOAT;

void create()
{
set_name("�񴹥~�M",({"green surcoat","surcoat"}) );
set("long","�o�O�@���⪺�~�M, ��u�Q���륩�C\n");
set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "��");
set("value",1800);
//set("armor_prop/armor",12);
set("limit_lv",50);
        }
        setup();
}
