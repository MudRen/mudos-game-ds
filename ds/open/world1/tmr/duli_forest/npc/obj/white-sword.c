#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("�զ���C", ({ "white long sword", "sword" }) );
        set_weight(7000);
        setup_sword(2, 11, 60, 4);

        if( !clonep() ) {
                set("wield_as", "sword");
                set("unit", "��");
                set("value", 1500);
                set("rigidity", 60);
                set("apply_weapon/sword", ([
                        "damage":5,
                        "str":1,
                ]));
                                set("long", @LONG
�o�O�@��ᬰ�I�l���զ���C�A�U�Q���C�W�t�ۥզ⪺�C�`�A��W
�K�X���˴H�C
LONG
);
        }
        setup();
}

