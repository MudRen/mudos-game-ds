
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name("邪氣長劍" ,({ "evil sword","sword" }) );
        set("long","這是一把普通的長劍，但是上面似乎沾染了不少邪氣。\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","iron");
        }
        set("unit", "把" );
         set("value",3250);
       set("weapon_prop/shield", 3);
        setup();
init_sword(20);
}
