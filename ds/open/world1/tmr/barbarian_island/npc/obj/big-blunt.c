#include <weapon.h>

inherit F_BLUNT;

void create()
{
        set_name("�j���", ({ "big wood blunt", "blunt" }) );
        set_weight(7000);
        setup_blunt(6, 5, 100, 0);

        if( !clonep() ) {
                set("wield_as", ({"twohanded blunt" }));
                set("unit", "��");
                set("value", 100);
                set("rigidity", 80);
                set("long",@long
�o�O�ӥεw���찵�����j��ΡA�O�q�y���������H��b�����_�o�򭫪��Z���C
long
);
        }
        setup();
}


