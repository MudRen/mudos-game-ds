#include <armor.h>

inherit BOOTS;

void create()
{
set_name( "�𤧪��u",({"tower boots","boots"}) );
set("long","�@���I�����ɻs���u�C\n");
set_weight(5800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��");
set("value",5800);
set("limit_lv",58);
//set("armor_prop/armor",49);
}
setup();
}
