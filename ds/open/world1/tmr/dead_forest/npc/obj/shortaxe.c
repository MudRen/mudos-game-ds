#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("���׵u��", ({ "short axe", "axe" }) );
        set_weight(3500);
        setup_axe( 4 , 4 , 80, 0);
        if( !clonep() ) {
                set("wield_as", ({"axe","secondhand axe"}));
                set("unit", "��");
                set("value", 300 );
                set("rigidity", 30);
                set("long",@LONG
�o�O�@����פw�[���u��A�򭱤W�ɬO�K�áA�Pı�w�g�����U�Q�F�C
LONG
                );
        }
        setup();
        // �S�� sword
        set("name",
            ENHANCE_D->enhance_weapon(this_object(),0,"�u��") );
}

