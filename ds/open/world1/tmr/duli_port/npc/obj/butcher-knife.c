#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("�O�M", ({ "butcher knife", "knife" }) );
        set_weight(2500);
        setup_blade( 1, 10, 10,0);

        if( !clonep() ) {
                set("wield_as", ({"blade","secondhand blade"}));
                set("unit", "��");
                set("value", 1200);
                set("rigidity", 50);
                set("long",@LONG
�o�O�@��p�v�`�Ϊ��O�M�A�j���u�O�s�M�u�t�������i�X�Ӫ��C
LONG
                );
        }
        setup();
}
