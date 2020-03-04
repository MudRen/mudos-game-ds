#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit FORK;
inherit F_UNIQUE;
void create()
{      
        set_name(HIR"朗基努斯之槍"NOR,({"longinus lance","lance","longinus"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",HIG"這是一把能夠驅散神聖的武器。\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("limit_str",100);
        set("material", "blacksteel");
        set("wield_msg",HIR"$N臨空一指，從天上飛下一把鮮紅色巨大的長槍，$N手握$n。\n"NOR);
        set("unwield_msg", RED"$N將手中的$n往天上一拋，$n消失的無影無蹤了。\n");
set("replica_ob","/u/s/sonicct/test/Angel/longinuslance2.c");
        init_fork(1000);
        setup();
        }
}
