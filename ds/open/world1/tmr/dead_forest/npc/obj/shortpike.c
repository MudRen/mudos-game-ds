#include <weapon.h>

inherit F_PIKE;

void create()
{
        set_name("���׵u�j", ({ "short pike", "pike" }) );
        set_weight(3500);
        setup_pike( 1 , 8 , 60, 0);

        if( !clonep() ) {
                set("wield_as", ({"pike","secondhand pike"}));
                set("unit", "��");
                set("value", 400 );
                set("rigidity", 30);
                set("long" ,@LONG
�@�@�o�O�@�K���K�����u�j�A�j�����K���\�O�����A�j�Y���I�w�w���A�p��
��]�����צӧ���o�S������ˤO�C
LONG
			);
        }
        setup();
        // �S�� sword
        set("name",
            ENHANCE_D->enhance_weapon(this_object(),0,"�u�j") );
}

