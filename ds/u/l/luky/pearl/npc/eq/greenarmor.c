#include <armor.h>

inherit ARMOR;

void create()
{
set_name("�񴹲���",({"green armor","armor"}) );
set("long","�@���⪺���ҡC�W�����^�F�X�������@���˹��C\n");
set_weight(8300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "��");
set("value",8300);
//set("armor_prop/armor",140);
set("limit_lv",60);
        }
        setup();
}

