#include <armor.h>

inherit FINGER;

void create()
{
set_name("�񴹧٫�",({"green ring","ring"}) );
set("long","�o�T�٫��W���^�F�@�����R���������C\n");
set_weight(2800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "gem");
set("unit", "�T");
set("value",3980);
set("armor_prop/wis",1);
//set("armor_prop/armor",23);
set("limit_lv",50);
}
setup();
}
