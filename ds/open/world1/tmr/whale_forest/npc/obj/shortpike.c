#include <weapon.h>

inherit F_PIKE;

void create()
{
        set_name("�u�j", ({ "short pike", "pike" }) );
        set_weight(3500);
        setup_pike(1, 9, 60, 3);

        if( !clonep() ) {
                set("wield_as", ({"pike","secondhand pike"}));
                set("unit", "��");
                set("value", 250);
                set("rigidity", 30);
                set("long", "�o�O�@�K���K�����u�j�A�j�����K���\�O�����A�j�Y���I�w�w���C\n");
        }
        setup();
}


