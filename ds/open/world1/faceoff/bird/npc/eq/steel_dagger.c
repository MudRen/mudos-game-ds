#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("�Q���P��", ({ "black steel dagger","dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@��H�Q�����y���P��, �ݨӬ۷�U�Q�C\n");
                set("material", "blacksteel");
        }
        init_dagger(22);
        set("wield_msg", "$N�q�h���N�X�@��$n���b�⤤�C\n");

        set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");

        setup();
}
