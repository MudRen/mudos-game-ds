#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("�p���", ({ "small wood axe", "axe" }) );
        set_weight(4000);
        setup_axe(1, 9, 120, 5);

        if( !clonep() ) {
                set("wield_as", ({"axe","secondhand axe"}));
                set("unit", "��");
                set("value", 250);
                set("rigidity", 30);
                set("long", "�@���W���ʤf���p���A���`�]���I�G�a�F�C\n");
        }
        setup();
}


