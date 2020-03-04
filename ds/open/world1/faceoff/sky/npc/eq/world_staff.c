#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit STAFF;
void create()
{
        set_name(HIW"�إ@��"NOR,({"whisk-world staff","staff"}));
        set_weight( 6000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
�o�O�����t�D�ҨϥΪ��t�M�A�Ψӱ����H�@�����Ѩ��U�c�C
�����t�D�b���Q�������~�o�D�A�ӳХX�u�E���ѩG�v, �q���԰�
���A�ϥΦ��M�A�ӱN�������ػP�L�H�C
LONG
                                );
                set("volume",2);
                set("unit", "��");
                set("value",12500);
                set("material","steel");
                set("limit_lv", 25);
        }
        set("weapon_prop/bio", -1);
        set("weapon_prop/sou", 1);
        set("weapon_prop/str", 2);

        set("replica_ob",__DIR__"world_staff2");
        set("wield_msg", HIW "$N����򴤩إ@��, ���������������ѷũM�O�R�����~�C\n"NOR);
        set("unwield_msg", "$N�N�⤤��$n��F�^�h�A�S��_�������骺���A�F\n");
        init_staff(71);
        setup();
}

void attack(object me,object victim)
{
        int damage;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(100)<70) return;
        if( me->query_skill("staff") < 50 ) return;
        
        damage = (me->query("int") + me->query("dex") - random(50));
        if( damage < 1 ) return;
        message_vision(
                HIW"�q�إ@�����Y�_�X�@�}�G�C�⪺�շϡA���M���J�F$N"+ HIW "���餺�A���G�y���F" + damage+"�I�ˮ`�I�I\n"NOR
        ,victim, me);
        victim->receive_damage("hp", damage, me );
}
