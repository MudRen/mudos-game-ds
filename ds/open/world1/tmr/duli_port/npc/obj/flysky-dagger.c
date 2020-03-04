#include <weapon.h>

inherit F_DAGGER;

void create()
{
        set_name("飛天匕", ({ "fly-sky dagger", "dagger" }) );
        set_weight(3500);
        setup_dagger(3, 5, 40, 0);

        if( !clonep() ) {
                set("wield_as", ({"dagger","secondhand dagger"}));
                set("unit", "把");
                set("value", 1000);
                set("rigidity", 25);
                set("apply_weapon/dagger", ([
                        "attack":2,
                        "dex":2,
                ]));
                set("apply_weapon/secondhand dagger", ([
                        "attack":2,
                        "dex":2,
                ]));
                set("long",@long
這是一把雕刻十分精美的短匕，匕鋒上的刻畫隱隱然可以看出一種萬里晴空的感覺。
long
                );
        }
        setup();
}

