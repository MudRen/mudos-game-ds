#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name("雙刃鬥劍", ({ "schiavona sword","sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");
                set("long", "改良式雙刃長劍，擁有極長的刀刃和十分周全的護手保護，可同
  時進行刺擊或砍擊的攻擊，重騎兵相當愛用。\n");
                set("value", 2500);
        }
        init_sword(48);
        setup();
}

