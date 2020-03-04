// �����v �]�\ - �]���a�� (freely-vigor)
// Tmr 2007/10/11

#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int attack_b(object me, object target);

int cast(object me, object target)
{
     int sk,inn,cost;

    sk=me->query_spell("freely-vigor");
    inn=me->query_int();

    if(sk < 10)
        return notify_fail("�A���u�]���a��v�٥������J�A�|�L��O�ϥΡC\n");
    if(me->query("ap") < 50 || me->query("mp") < 50 || me->query_temp("power_cast") )
        return notify_fail("�A�{�b�����骬�p�L�k�ϥΡu�]���a��v�C\n");
    if( !target )
          target = offensive_target(me);
    if( !target )
        return notify_fail("�S���o�ӤH�i�H�����C\n");
    if( !me->can_fight(target))
        return notify_fail("�A�L�k�P��貣�;԰��C\n");
    if( !me->is_fighting(target) )
        return notify_fail("�A�èS���P���o�;԰��C\n");
    
    message_vision( HBK"$N���$n"HBK"�I�i�]������" HIG "�u�]���a��v" HBK "�A�|�g����v�����E�A���o�X�G�����~�I�I\n" NOR, me, target);
    cost = (sk*3 + inn)/6;
    me->start_busy(1);
    call_out("attack_b", 2,me,target);
    me->receive_damage("mp", cost);
    me->set_temp("power_cast", 1 + sk/20 );
    return 1;
}

int attack_b(object me,object target)
{
    int damage;
      int sk, inn;
        sk=me->query_spell("freely-vigor");
    inn=me->query_int();

    if(!me) {
         me->delete_temp("power_cast");
        return 0;
        }

    if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1)
    {
        message_vision(HIW"$N"HIW"�]������ж˦ӶäF���, �L�k���Q�I�i�U�h�C\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");

    if(!target)
        return notify_fail("�ؼЮ����F�C\n");
    if( environment(me) != environment(target) )
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");

    if(random(target->query_skill("dodge")*2)/3+random(target->query_shield())+1 < random( sk*2 )/3+inn )
    {
        damage = me->query_damage()*2 + (sk + inn*2);
        damage -= target->query_shield();
        damage = COMBAT_D->Merits_damage(me,target,damage, "sou");

                if(damage < 1) damage = 1 + random(10) ;
        message_vision(HIG"�]���a��"HIR"�S�p�j�Ħ��G�k$n"HIR"��ߡA$n"HIR"�o�X�h�W�Y�F���s�n�I�I("+ damage + ")\n"NOR,me,target);
        target->receive_damage("hp", damage, me);
            
                // ���]
                CLASS_D("ancestor")->addMagic(me, target, damage, 2);

        target->start_busy(1);
    }
    else {
          message_vision(HIG"�]���a��"NOR"���E���_�ӡA�L�k��$n"NOR"�y������ˮ`�C\n"NOR,me,target);
    }

    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    me->improve_spell("freely-vigor", random(1+me->query_int()) );
}

int improve_limite(object ob)
{
    if(ob->query("int") < 60) return 90;
    
    return 100;
}

