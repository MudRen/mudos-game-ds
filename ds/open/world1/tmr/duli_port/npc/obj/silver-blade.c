#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("�ջȵu�M", ({ "silver blade", "blade" }) );
        set_weight(3500);
        setup_blade(2, 10, 60, 3);

        if( !clonep() ) {
                set("wield_as", ({"blade","secondhand blade"}));
                set("unit", "��");
                set("value", 1000);
                set("rigidity", 25);
                set("apply_weapon/blade", ([
                        "attack":5,
                ]));
                set("apply_weapon/secondhand blade", ([
                        "attack":5,
                ]));
                set("long", 
        "�o�O�@��»ȥ��y���u�M�A�N�_�ӫD�`��T�A�M�W�]�O�D�`�U�Q�C\n"
                );
        }
        setup();
}

