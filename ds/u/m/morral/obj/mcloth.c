#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
set_name("同盟軍軍服",({"morral's cloth"}) );
set("long","哇•••••這是同盟軍的軍服耶，而且還是
楊威利的ㄡ！！！！！\n");
set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "件");
                set("value", 10000);
set("armor_prop/armor",9999);
}
setup();
}          
