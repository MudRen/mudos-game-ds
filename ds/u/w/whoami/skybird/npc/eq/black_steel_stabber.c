#include <weapon.h> 
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name("�¿��u��", ({ "black steal stabber" }) );
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@��ί¿�����y�X���P���A���ˤO���e�p��E\n");
                set("value", 1570);
                set("material", "steel");
        }
        init_dagger(35, SECONDARY);

        set("wield_msg", "$N�q�h���N�X�@��$n���b�⤤�C\n");
        set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");

        setup();
}

