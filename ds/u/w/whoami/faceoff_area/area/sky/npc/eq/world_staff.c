#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit STAFF;
void create()
{
        set_name(HIW"�إ@��"NOR,({"world staff","staff"}));
        set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIW"�o�O�ǻ��������t�D�ҨϥΪ��t�M, �����ηN���O�����@�����c....\n"
                      "�������t�D�b�T�Q�T�����~���X�E���ѩG, �q���԰����A�ϥΦ��M, �]���N\n"
                 "���M�ػP�L�H...�C\n"NOR);
               set("volume",2);
                set("unit", "��");
                set("value",12500);
              set("material","steel");
                set("limit_lv",25);
        }
        init_staff(71);
        set("wield_msg",HIW"$N����򴤩إ@��, �K�ɤ@�ѥ��~�g�X�I\n"NOR);
        set("unwield_msg", "$N�N�⤤��$n��F�^�h, �P�ɥ��~�f�H�F���֡C\n");
        setup();
}

void attack(object me,object victim)
{
        int damage,str,dex,random1;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(200)>150)
        {
        str = me->query("int")-random(20);
        dex = me->query("dex")-random(18);
        random1 = 1+random(2);
        damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIW"�إ@�����Y�_�X�@�ѫC��, �@�D����۫C�Ϥ��g�V$N !\n"NOR
        +HIW"���G�y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR
        ,victim);
        return;
        }
}
