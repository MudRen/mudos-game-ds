#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("���׵u�C", ({ "short sword", "sword" }) );
        set_weight(2000);
        setup_sword(1, 12, 75, 0);

        if( !clonep() ) {
                set("wield_as", ({"sword","secondhand sword"}));
                set("unit", "��");
                set("value", 150);
                set("rigidity", 5 );
                set("long", "�@���K�s���u�C�A�O�@��`�����򥻨����Z���A���w�g���ר��H�ɳ��|�_�����Pı�C\n");
        }
        setup();
        // �S�� sword
        set("name",
            ENHANCE_D->enhance_weapon(this_object(),0,"�u�C") );
}

