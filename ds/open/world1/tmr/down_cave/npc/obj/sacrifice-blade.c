#include <weapon.h>
#include <ansi.h>

inherit F_BLADE;
inherit F_UNIQUE; // only one

void create()
{
        set_name(HIR "����" NOR, ({ "sacrifice blade","blade" }) );
        set_weight(10000);
        setup_blade(4, 11, 120, 10);

        if( !clonep() ) {
                set("wield_as", ({"twohanded blade"}));
                set("unit", "��");
                set("value",50000);
                set("rigidity", 120);
                set("long",@long
�o�O�@��G����񪺪��M�A�f�K�L�����M�W�W���ɬy�U�@���A�v����
�y�A�ӫp�����M�`�A��O�Q�g���Ť�G�N���������]�q�ۡC�������b�H
����^���q��`���M���|�P�X���}�ӡC
long
        );
         set("replica_ob",__DIR__"long-blade");
         set("apply_weapon/twohanded blade", ([
                        "cps":2,
                        "cor":2,
                        "twohanded blade":10,
                        ]));

        }
        setup();
}

