#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(HIC"�C�P�j����"NOR,({"mild seven sword","sword","mile"}));

        set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIB"�o���Ҭݰ_�Өä��㲴�A�i�O�b�A��X�o���ҮɡA�o�o�{�o�Ҳʤj��w\n"
                      "���B�A�b���Y�W�������ǳ\\�������ƴ��X�ӡC�ǻ��o���ҬO�j�N�ɲ��H\n"
            "�εҵ��M���K�ȥ]���Ӧ��A�ҥH�o�@���ҷ�M�O�L�P�ۤ񪺳��ųf(�ըӫ~��)�C\n"NOR);
                set("volume",2);
                set("unit", "��");
                set("value",12500);
        set("limit_skill",60);
        set("material","silver");
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_dex",35);
        }
        init_sword(70);
        set("wield_msg","$N�q�I�᪺�Ҳ�����X�@��$n�A�n�ɤ@�������q$N�����W���o�X�ӡI\n");
        set("unwield_msg", "$N�N�⤤��$n�p�ߦ��n�C\n");
        set("replica_ob", __DIR__"longsword.c");
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
        str = me->query("str")-random(20);
        dex = me->query("dex")-random(18);
        random1 = 1+random(2);
        damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIY"�C�P�j���Ҧb���Y�@���@�����������������F�X�ӡC\n"NOR
        +HIG"�@�Ѽ���q���Y�E�g�ӥX����D�D�D�D�D�D\n"NOR
        +HIR"���a���A�b$N���e�@�����������I�I�I�q���Y���X�@�D�·ϩ�$N�ӥh�C\n"NOR
        +HIB"���G�y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR
        ,victim);
        return;
        }
}
  
