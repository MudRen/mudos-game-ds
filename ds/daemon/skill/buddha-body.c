#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target, string arg)
{
        int sk, bonus;

           if(me->query_condition("buddha-body-cd") || me->query_condition("buddha-body-clear"))
                    return notify_fail("�A���骬�p�٨S����_�A�ٵL�k�ϥΡu�ר�����v\n"); 
            if(me->query_temp("buddha-body") )
                      return notify_fail("�A���骬�p�٨S����_�A�ٵL�k�ϥΡu�ר�����v\n"); 

        if(me->query("hp") < 300 )
                return notify_fail("�A���ͩR�Ȥ����A�L�k�ϥΡu�ר�����v�C\n"); 
        if(me->query("mp") < 300 )
                return notify_fail("�A���]�k�Ȥ����A�L�k�ϥΡu�ר�����v�C\n"); 
        if(me->query("ap") < 300 )
                return notify_fail("�A�����l�Ȥ����A�L�k�ϥΡu�ר�����v�C\n"); 
        
        sk = me->query_skill("buddha-body");
        if( me->query_skill("buddha-skill") < 80 )
                return notify_fail("�A���u�p�ӤE���v�׬��٤������A�L�k�ϥΡC\n");
        if(sk<33)
                return notify_fail("�A���u�ר�����v�׬��٤������A�L�k�ϥΡC\n");

        bonus = sk/33;

        me->set_temp("buddha-body", bonus);
        me->add_temp("apply/sou",bonus);
        me->add_temp("apply/wit",bonus);

        me->set("hp",50);
        me->set("ap",50);
        me->set("mp",50);
        me->set_temp("fly",1);  // �|��

        message_vision(
                        HIY "�u��$N�C�պ��C��i���A�Ѧa���R���_���������I�I\n"
                        + HIC "$N�H�Z�J��A�ҤJ�۩ʡA�@���q�۩ʬy�S�ӥX...\n"
                        + HIM "$N���x�L���A�ר��ܪ��Y�����L�A�ݤ��M���]�N���ۡA�N�a�ר�����I�I\n" NOR, 
        me);
        
        if( me->query_tec()>10 ) {
                // ���Įɶ��A�̪�13����
                 me->apply_condition("buddha-body-clear", 4*13); 
                // �N�o�ɶ��A�̵u��5����
                 me->apply_condition("buddha-body-cd", 5); 
        } else {
                // 3 + sou
                 me->apply_condition("buddha-body-clear", 4*(me->query_tec()+3)); 
                // 15 - sou
                 me->apply_condition("buddha-body-cd", 4*(15-me->query_tec())); 
        }
        return 1;
}

int improve_limite(object ob)
{
        return ob->query_con() + 60;
}

// add by acme 2007.01.09
int receive_damage_buffer_effect(string type, int damage, object me, object who)
{
    if( !objectp(me) || !objectp(who) ) return damage;
    if(me == who) return damage;
      if( type == "hp" && damage > 10) {
        if( me->query_temp("buddha-body") ) {
            int damage_reflex = damage * (me->query_skill("buddha-body") * 20 / 100) / 100;
            int damage_cancel = damage * (me->query_skill("buddha-body") * 30 / 100) / 100;

            damage = damage - damage_cancel;
             if(damage_reflex<1) damage_reflex = 1;

            message_vision(HIW"$N�u�ר�����v����F�ˮ`�äϮg��$n�C\n"NOR, me, who);

            // npc �̫�~������
            if( damage_reflex > 0 )
                who->receive_damage(type, damage_reflex, me);
        }
    }
    return damage <= 0 ? 0: damage;
}

