#include <armor.h>

inherit HEAD;

void create()
{
set_name("���Y��",({"green helm","helm"}) );
set("long","�o�O�Ѻ�����s�����Y��, �Q����T�@�ΡC\n");
set_weight(3600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","steel");
set("unit", "��");
set("value",3960);
set("limit_lv",53);
//set("armor_prop/dodge",1);
//set("armor_prop/defense",1);
 }
setup();
}
