#include <armor.h>

inherit NECK;

void create()
{
set_name("�񴹶���",({"green necklace","necklace"}));
set_weight(1800);
set("long","�o�O�@����R������C/n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "gem");
set("unit", "��");
set("value",1800);
//set("armor_prop/armor",1);          
set("limit_lv",45);
}
setup();
}
