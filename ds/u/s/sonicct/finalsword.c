#include <weapon.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
inherit SWORD;
void create()
{      
        set_name(HIB"終結之劍"NOR,({"final sword","sword"}) );
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",HIG"這是一把終結聖劍。\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("limit_str",10);
        set("limit_con",10);
        set("limit_dex",10);
        set("limit_int",10);
        set("no_drop",1);
        set("weapon_prop/hit",100);
        set("material", "blacksteel");
        set("wield_msg",HIR"$N臨空一指，天上飛來一把聖劍，$N手握$n。\n"NOR);
        set("unwield_msg", RED"$N將手中的$n往天上一拋，$n無影無蹤了。\n");
        init_sword(1000);
        setup();
        }
}
