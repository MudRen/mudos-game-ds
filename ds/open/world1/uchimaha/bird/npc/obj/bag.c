#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"神"HIW"風"HIR"袋"NOR, ({ "godwind bag","bag" }) );
        set_weight(500);
        set_max_capacity(200);
        set_max_encumbrance(90000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "這是一口大袋子，紅白相間，似乎有奇妙的魔力。\n");
                set("value",0);
                set("no_sac",1);
               }
        setup();
}
