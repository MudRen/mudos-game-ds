#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("���Y", ({ "axe" }) );
        set_weight(5500);
        setup_axe(3, 8, 80, 0);

        if( !clonep() ) {
                set("wield_as", ({"axe","twohanded axe"}));
                set("unit", "��");
                set("value", 800);
                set("rigidity", 80);
                set("long", 
"�o�O�@��򭱻�j�����Y�A��ꪺ���`��W�K�X��í���C\n"
                );
        }
        setup();
}

