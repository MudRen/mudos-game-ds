#include <armor.h>

inherit SHIELD;

void create()
{
set_name("�񴹬޵P",({"green shield","shield"}) );
set("long","�o�O�Ѧʦ~���s�������޵P, ��w�L��C\n");
set_weight(3600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","steel");
set("unit", "��");
set("value",3960);
//set("armor_prop/defense",1);
set("limit_lv",55);
//set("armor_prop/armor",109);
 }
setup();
}
