// �����v �]�\ - �]�H���� (sorcery-lock)
// Tmr 2007/10/11

#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int attack_b(object me, object target);

int cast(object me, object target)
{
      int sk,inn,cost;

    sk=me->query_spell("sorcery-lock");
    inn=me->query_int();

    if(sk < 10)
        return notify_fail("�A���u�]�H����v�٥������J�A�|�L��O�ϥΡC\n");
    if(me->query("ap") < 50 || me->query("mp") < 50 || me->query_temp("power_cast") )
        return notify_fail("�A�{�b�����骬�p�L�k�ϥΡu�]�H����v�C\n");
    if( !target )
          target = offensive_target(me);
    if( !target )
        return notify_fail("�S���o�ӤH�i�H�����C\n");
    if( !me->can_fight(target))
        return notify_fail("�A�L�k�P��貣�;԰��C\n");
    if( !me->is_fighting(target) )
        return notify_fail("�A�èS���P���o�;԰��C\n");
    
    message_vision( HBK"$N���$n"HBK"�I�i�]������" HBK "�u�]�H����v" HBK "�A�n�ɶ®��šA�K��@�D�I�I\n" NOR, me, target);
    cost = (sk*3 + inn)/5;
    me->start_busy(1);
    call_out("attack_b", 2,me,target);
    me->receive_damage("mp", cost);
    me->set_temp("power_cast", 1 + sk/20 );
    return 1;
}

int attack_b(object me,object target)
{
    int damage;
    int sk, inn, hp_limit;
        sk=me->query_spell("sorcery-lock");
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
        damage = me->query_damage() + (sk + inn*3);
        damage -= target->query_shield();
        damage = COMBAT_D->Merits_damage(me,target,damage, "sou");

                if(damage < 1) damage = 1 + random(10) ;
        message_vision(HBK"�]�H����"HIR"�S�p���y��ĤJ$n"HIR"�餺�g�ߥ|�B���p�A$n"HIR"�o�X�h�W�Y�F���s�n�I�I("+ damage + ")\n"NOR,me,target);
        target->receive_damage("hp", damage, me);
            
                // �l��
                hp_limit = sk*8 + me->query_sou() * 20;
                if( damage > hp_limit ) 
                       damage = hp_limit ;
                damage = damage/2 + random(damage/2);
                me->receive_heal("hp", damage );
                tell_object(me, sprintf(HIG"(�A�l��%3d�I�ͩR�I�ơC)\n"NOR, damage) );
                // ���]
                CLASS_D("ancestor")->addMagic(me, target, damage, 1);

        target->start_busy(1);
    }
    else {
          message_vision(HBK"�]�H����"NOR"�Q�n���J$n"NOR"�餺�A���Q$n"NOR"���F�}�h�C\n"NOR,me,target);
    }

    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    me->improve_spell("sorcery-lock", random(1+me->query_int()) );
}

int improve_limite(object ob)
{
    if(ob->query("int") < 60) return 90;
    
    return 100;
}


