#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit AXE;
void create()
{
        set_name(HIY"������"NOR, ({ "light axe","axe" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�⥨��Q������, ��`�W�観�������Ȫ��O��,\n"
                            "�o��򴿳Q�t�̯��ֹL, �ϱo���򦳵ۯ��_���O�q�C\n");
                set("material", "gold");
                set("limit_str",30);
                set("limit_lv",20);
        }
    set("wield_msg","$N���_$n�A�y�ɤ@�}ģ�������~�q$N���W�g�X�I\n");
    set("unwield_msg","$N��U�⤤��$n�A�ç�$n�p�ߪ����n�E\n");
    set("weapon_prop/str",2);
    set("weapon_prop/bar",2);
    set("weapon_prop/sou",-1);
    set("weapon_prop/tec",-1);
    init_axe(84,TWO_HANDED);
    set("replica_ob", __DIR__"bigaxe.c");
    setup();
}
void attack(object me,object victim)
{
        int damage,str,con,random1;
        if( random(250)>200)
        {
        str = me->query("con")-random(10);
        con = me->query("con")-random(10);
        random1 = 1+random(2);
        damage = random1*(str+con);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIW"�����򴲵o�X�j�P���{���C\n"NOR
        +HIY"�@�����⪺�����q������g�X�A�g��$N�C\n"NOR
        +HIY"�٨����A���L�Ʊ������q$N���W���|���K��g�X�I�I�I$N�R�X�F�X�j�f���A��C\n"NOR
        +HIC"���G�y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR
        ,victim);
        return;
        }
}



