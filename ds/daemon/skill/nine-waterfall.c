/* �E�r�s���� (nine-waterfall) Advanced Thief �Χޯ� 
 - by tmr 2002/04/05
 �令�¯S���
 Update by tmr 2006/11/22
 */


#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target, string arg)
{
    int sk, times, i, damage, target_d;
    if(me->query_skill("free_action")< 70)
        return notify_fail("�A�����P�ץ��Ť���80�šA�L�k�ϥΡu�E�r�s���v�C\n");
    if(me->query_skill("perception")< 70)
        return notify_fail("�A���[��O����80�šA�L�k�ϥΡu�E�r�s���v�C\n");
    if(me->query_skill("nine-waterfall")< 20)
        return notify_fail("�A���u�E�r�s���v����20�šA�L�k�ϥΡC\n");
    if(me->query("ap")<200 || me->query("hp")<200)
        return notify_fail("�A�����骬�p���ΡA�L�k�ϥΡu�E�r�s���v�C\n");
     if( !target )
          target = offensive_target(me);
     if(!target)
           return notify_fail("�A�S���i�H�������ﹳ�C\n");

     //�����ʪ��n�S�O�`�N�n�[�U�����.
      if(!me->can_fight(target))
          return notify_fail("�A�L�k����o�;԰��C\n");
      if( !me->is_fighting(target) )
          return notify_fail("�A�èS������԰��C\n");
      if(target->is_corpse())
          return notify_fail("�A�������u�O�@�����....\n");

        if( userp(me) && me->query_temp("nine-waterfall") )
            return notify_fail("�A�u�ɶ����L�k�A�I�i�u�E�r�s���v�F�C\n");

        sk = me->query_skill("nine-waterfall");
        // ����
        times = sk/10;
        if( times < 2) times = 2;
        times = times/2 + random(times);
        if( times > 9 || !userp(me) ) times = 9;

        message_vision(HIC"\n$N"HIC"����ŪűǥX�F�j��ɿ��A���$n"HIC"�Y�X���ۡy�E�r�s���z�I�I\n"NOR,me, target);
        for(i=0;i<times;i++) {
                damage = me->query_damage() - target->query_armor()/2 - random(target->query_armor()/3);
                damage = COMBAT_D->Merits_damage(me, target, damage, "bio");

        /*
            if( damage > 70 ) {
                damage = 120 + random(30);
             } */
            if( damage < 1 ) damage = 1;

                switch(i) {
                case 0: message_vision(HIY"$N��������ɮg�A�Y�X�E�r�s����"HIM"�y�������z"HIY"�A�ƤQ�T�ɿ���ոU�d�A��p�y�P�I�I\n"NOR,me);
                    break;
                case 1:message_vision(HIY"$N��������ɮg�A�Y�X�E�r�s����"NOR YEL"�y�g�X�[�z"HIY"�A�ƤQ�T�ɿ���ոU�d�A��p�y�P�I�I\n"NOR,me);
                    break;
                case 2:message_vision(HIY"$N��������ɮg�A�Y�X�E�r�s����"HIC"�y�ѳ��B�z"HIY"�A�ƤQ�T�ɿ���ոU�d�A��p�y�P�I�I\n"NOR,me);
                    break;
                case 3:message_vision(HIY"$N��������ɮg�A�Y�X�E�r�s����"NOR MAG"�y���P�e�z"HIY"�A�ƤQ�T�ɿ���ոU�d�A��p�y�P�I�I\n"NOR,me);
                    break;
                case 4:message_vision(HIY"$N��������ɮg�A�Y�X�E�r�s����"HBK"�y�ȲV�P�z"HIY"�A�ƤQ�T�ɿ���ոU�d�A��p�y�P�I�I\n"NOR,me);
                    break;
                case 5:message_vision(HIY"$N��������ɮg�A�Y�X�E�r�s����"HIB"�y�Q�ɮ��z"HIY"�A�ƤQ�T�ɿ���ոU�d�A��p�y�P�I�I\n"NOR,me);
                    break;
                case 6:message_vision(HIY"$N��������ɮg�A�Y�X�E�r�s����"HIY"�y�����f�z"HIY"�A�ƤQ�T�ɿ���ոU�d�A��p�y�P�I�I\n"NOR,me);
                    break;
                case 7:message_vision(HIY"$N��������ɮg�A�Y�X�E�r�s����"HIR"�y��ƻa�z"HIY"�A�ƤQ�T�ɿ���ոU�d�A��p�y�P�I�I\n"NOR,me);
                    break;
                case 8:message_vision(HIY"$N��������ɮg�A�Y�X�E�r�s����"HBK"�y�Ȧt�z�z"HIY"�A�ƤQ�T�ɿ���ոU�d�A��p�y�P�I�I\n"NOR,me);
                        break;
                }

            target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
            if( random(sk) > random(target_d) ) {
                message_vision("$N�Y�X���t���S�p�d����šA$n�����L�k�Ĩ����󦳮Ī����m�A�y��"+damage+"���ˮ`�C\n" NOR, me, target);
                target->receive_damage("hp",damage, me);
                COMBAT_D->report_status(target);
            } else {
                message_vision(CYN"$n"CYN"�Ө���o���������S���������ˮ`...\n"NOR, me, target);
            }
        }
        target->start_busy(1);
                if( !userp(me) )  return 1;
         me->improve_skill("nine-waterfall", random(me->query_dex()) );

        me->set_temp("nine-waterfall",1);
        if(12-me->query_bar() <= 4)
            call_out("clear", 4, me);
        else
            call_out("clear", 12-me->query_bar(), me);
        me->start_busy(1);
        me->receive_damage("ap", 100 );
        return 1;
}

int valid_learn(object me) {    return 1;   }

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    return 30 + ob->query_dex();
}

void clear(object me)
{
    if( !me ) return;
    me->delete_temp("nine-waterfall");
    tell_object(me,"�A���e�I�i�u�E�r�s���v�ҿ�d�����ˤw�g��_�����F�C\n");
}

