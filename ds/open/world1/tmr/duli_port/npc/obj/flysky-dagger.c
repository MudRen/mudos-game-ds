#include <weapon.h>

inherit F_DAGGER;

void create()
{
        set_name("���ѤP", ({ "fly-sky dagger", "dagger" }) );
        set_weight(3500);
        setup_dagger(3, 5, 40, 0);

        if( !clonep() ) {
                set("wield_as", ({"dagger","secondhand dagger"}));
                set("unit", "��");
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
�o�O�@���J��Q��������u�P�A�P�W�W����e�����M�i�H�ݥX�@�ظU�����Ū��Pı�C
long
                );
        }
        setup();
}

