#include <armor.h>

inherit HEAD;

void create()
{
set_name("���Y��",({"tower helm","helm"}) );
set("long","�o�O�ѻɻs�����Y��, �ݰ_�ӤQ����T�C\n");
set_weight(6600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","steel");
set("unit", "��");
set("value",6660);
set("limit_lv",60);
//set("armor_prop/armor",54);
//set("armor_prop/defense",2);
 }
setup();
}
