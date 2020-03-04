#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( WHT"磐龍劍"NOR, ({ "dragon sword","sword" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","劍身隱隱浮現出一條龍的影像，還籠罩著一層薄薄的霧氣...。");
                set("unit", "把");
                set("value",1);
        }
        set("weaopn_prop/hit", 10 );
        set("wield_msg","$N蹲低身子，腰祇一趁，拔出劍鞘中的$n。\n");
        set("weaopn_prop/dex", 1 );
        init_sword(60);
        setup();
}
int query_autoload() { return 1; }


