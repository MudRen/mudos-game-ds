#include <weapon.h>
inherit F_BLADE;

void create()
{
        set_name("�Ѥ����M", ({ "tian-wang long blade","blade" }) );
        set_weight(5000);
          setup_blade(4, 10, 80, 0);

        if( !clonep() ) {
                set("wield_as", ({"twohanded blade"}));
                set("unit", "��");
                set("value",12000);
                set("rigidity", 80);
                set("long",@long
�@�@�o�O�@��y���Q���S�����M�A�M�W�W���۬y���몺�Ÿ��A�b��
���M�g�U�A�����M�z�S�X����������C���M������W���W���w������
��Ч��Ѥ����R�ΤM���@�C
long
        );
        }
         set("apply_weapon/twohanded blade", ([
                        "cps":2,
                        ]));

        setup();
}


