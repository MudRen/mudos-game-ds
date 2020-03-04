#include <weapon.h>
#include <ansi.h>

inherit F_SWORD;
inherit F_UNIQUE; // only one

void create()
{
        set_name(HIW "�s����C" NOR, ({ "dominate long sword", "sword" }) );
        set_weight(1000);
        setup_sword(3, 13, 80, 6);

        if( !clonep() ) {
                set("wield_as", "sword");
                set("unit", "��");
                set("value", 12000);
                set("rigidity", 60);
                set("apply_weapon/sword", ([
                        "con":2,
                        "str":-1,
                ]));
                set("long", @LONG
�o�O�@��C�������צp�@�i�Ȫ����C�A���G�S���򭫶q�A���@�j�N��
�j�����ˤl�C�����몺�զ���u���q�C���i�{�}�ӡA�ϱo�|�P���G���G�\
�h�A�o����G�N�O�ǻ������٧��_�C�F�C
LONG
);
        }
        setup();
}

/*
int inflict_damage(string strength, object victim)
{
        int dam = ::inflict_damage(strength, victim);
        if( dam && random(100) < 40 ) {
                environment()->add_temp("fight_msg", HIW "�����C�g�X�@�D�벴�����~�A" NOR);
        }
        return dam;
}
*/

