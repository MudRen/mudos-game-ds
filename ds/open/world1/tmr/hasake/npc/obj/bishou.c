#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("���K�P��", ({ "steel dagger", "dagger" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "�`");
                set("long", "�o�O�@�`�G�̮̪��P��\n");
                set("value", 500);
                set("material", "steel");                
               set("backstab_bonus",15); //�ʤ���
        }
        init_dagger(15);
        setup();
}

