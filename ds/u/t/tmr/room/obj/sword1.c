// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name( HIW "倚天劍" NOR , ({ "eten-sword","sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把揚名江湖百來年的十奇劍之一。\n");
                set("value", 20000);
                set("material", "steel");
        }
        init_sword(25);
        set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	set("weapon_prop/str",20);
        setup();
}
