#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
set_name( YEL "雷光劍" NOR ,({"light sword","sword"}));
set("long","這是一把由天行者所佩帶之劍.\n");
set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",100000);
set("limit_str",5);
set("limit_dex",6);
        }
set("wield_msg","$N雙手握住$n劍柄部分，只看見$n發出了驚人的閃光\n");
set("unequip_msg", "$N閉上雙眼,$n的閃光就漸漸消失了. \n");

init_sword(999);
set("combat_msg", ({
   "$N手握$w,閉上雙眼只用心去感覺$n的存在,往$n削了一刀. \n",
}) );
setup();
}
