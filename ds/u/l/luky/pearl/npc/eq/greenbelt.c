#include <armor.h>

inherit BELT;

void create()
{
set_name("�񴹸y�a",({"green belt","belt"}) );
set_weight(3200)
;
set("long","�@���G��⪺�y�a�C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "gem");
set("unit","��");
set("value",3200);
//set("armor_prop/armor",30);
set("limit_lv",49);
}
setup();
}
