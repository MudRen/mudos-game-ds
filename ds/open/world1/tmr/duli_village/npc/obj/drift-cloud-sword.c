#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("�B���C", ({ "drift-cloud sword", "sword" }) );
        set_weight(2500);
        setup_sword(3, 10, 100, 0);

        if( !clonep() ) {
                set("wield_as", ({"secondhand sword"}));
                set("unit", "��");
                set("value", 1200);
                set("rigidity", 50);
                set("apply_weapon/secondhand sword", ([
                        "damage":3,
                        "attack":5,
                ]));
                set("long",@long
�o�O�@��b�Z���ɻᦳ�W���u�C�A���M�����L�ءA����u�����U�Q�C
�W�A�o�����ϼC���⪺�R�ΡC�B���C���C�`�W��e�ۤ@�ӡu���v�r�C
long
                );
        }
        setup();
}

