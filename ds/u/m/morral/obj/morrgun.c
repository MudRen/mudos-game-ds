#include <weapon.h>
#include <ansi.h>

inherit GUN;
void create()
{set_name(HIY"楊威利專用槍"NOR,({"morral gun","morral","gun"}) );
set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long",HIG"槍如其名。\n"NOR);
set("value",200000);
set("rigidity",50000);
set("bullet_type","super-big");
set("max_load",500);
init_gun(3000);
                set("material", "blacksteel");
set("wield_msg","$N拔出$n！\n");
set("unwield_msg", "$N將手中的$n小心收好。\n");
}
setup();
}  
