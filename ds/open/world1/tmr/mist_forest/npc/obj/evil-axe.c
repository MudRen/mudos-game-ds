#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("巨魔斧", ({ "huge-evil axe","axe"}) );
        set_weight(10000);
          setup_axe(4, 6,120, 0);

        if( !clonep() ) {
                set("wield_as", ({"twohanded axe"}));
                set("unit", "把");
                set("value", 3500);
                set("rigidity", 80);
                set("long",@long
　　這是一把造型奇特的巨大斧頭，薄而大的斧鋒上有著一個個的小洞，
在揮舞時想必會帶起陣陣刺耳的風聲。
long
                );
        }
        set("apply_weapon/twohanded axe", ([
                "str":2,
                "cps":-2,
        ]));
        setup();
}


