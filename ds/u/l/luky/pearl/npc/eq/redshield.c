#include <armor.h>

inherit SHIELD;

void create()
{
set_name("�����޵P",({"red shield","shield"}) );
set("long","�o�O�Ѽ��K�s����������, �Q����w�C\n");
set_weight(3600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","steel");
set("unit", "��");
set("value",4960);
//set("armor_prop/defense",1);
set("limit_lv",50);
//set("armor_prop/armor",72);
 }
setup();
}
