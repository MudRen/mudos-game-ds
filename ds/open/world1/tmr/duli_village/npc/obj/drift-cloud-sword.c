#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("浮雲劍", ({ "drift-cloud sword", "sword" }) );
        set_weight(2500);
        setup_sword(3, 10, 100, 0);

        if( !clonep() ) {
                set("wield_as", ({"secondhand sword"}));
                set("unit", "把");
                set("value", 1200);
                set("rigidity", 50);
                set("apply_weapon/secondhand sword", ([
                        "damage":3,
                        "attack":5,
                ]));
                set("long",@long
這是一把在武器界頗有名的短劍，雖然長不過尺，但其罕見的銳利劍
鋒，卻極受使劍高手的愛用。浮雲劍的劍柄上刻畫著一個「江」字。
long
                );
        }
        setup();
}

