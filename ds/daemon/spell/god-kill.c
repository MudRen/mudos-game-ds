/* �����Z god-kill edit -By Tmr-  2000/4/8

   �N�����Z�令�¯��Z�u���j�סBdelay�{�שMcost need.
   �ӱN���Z�u����delay�u�A�¤O�z�A�����Z�Ф��|�L�j�ιL�z�A
   �Ӧ��G��spells��ܨϥΡC
                                   Update by -Acme-
*/

#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int attack(object target,object me);

int cast(object me, object target)
{
    int inn,sk,cost;
    if (!me) me=this_player();
    inn=me->query_int();
    sk =me->query_spell("god-kill");

    cost = sk/4;

    if ( environment(me)->query("no_cast"))
        return notify_fail("�o�̤���I�k�C\n");
    if ( (int)me->query("mp") < cost )
        return notify_fail("�A���k�O�����C\n");
    if ( inn < 40)
        return notify_fail("�A���G�O���_�u�����Z�v���G��C\n");
    if ( !me->is_fighting() )
        return notify_fail("�A�èS���b�԰����C\n");
    if ( !target )          target = offensive_target(me);
    if ( !target )          return notify_fail("�A�䤣��i�H�I�k���ﹳ�C\n");
    if ( target == me )     return notify_fail("�ոե�suicide ����֡C\n");
    if (!me->is_fighting(target) )
        return notify_fail("�A�èS���M���b�԰����C\n");

    message_vision(
        "$N�q��"HIW"�u"GRN"����ë�g"HIW"�v"NOR"��"HIW"�u"RED"����"NOR"�v�Z�G\n\n" NOR
        +"      �u��b�B�I���W�C�A���Y�����b���D�C�v\n"
        +"      �u�ѭ��f�ư_��ȡA�Z�e���Ұʷ��Y�C�v\n",me);

    me->receive_damage("mp",cost); //�I�k��MP
    me->set_temp("power_cast",1+sk/33);

    // ���ӳ�����A�i�H���o
    if( SPELL_D("moon-essence")->checkUse(me)) {
      me->start_busy(1); 
                attack(target, me);
    } else {
      me->start_busy(2); 
                call_out( (:attack,target,me:),2);
        }
    return 1;
}

int attack(object target,object me)
{
    int sk, hit, damage, cost;
    string msg;

    if ( !me ) return 1;
    if ( !target ) return notify_fail("�A�䤣��I�k�ؼСC\n");
    if ( environment(me) != environment(target) )
        return notify_fail("�I�k�ؼ����}�F�A���I�k�d��C\n");
    if ( !me->query_temp("power_cast") || me->query_temp("power_cast") <0 ) {
        message_vision(HIW"$N"HIW"�]������ж˶äF����A�L�k���Q�I�i�k�N�C\n"NOR,me);
        return 1;
    }

    me->delete_temp("power_cast");
    sk = me->query_spell("god-kill");
    cost = (sk+me->query("int"))/13;

    msg = "$N���⵲�L�A�C�����n�A�X��"HIW"�u"RED"��b"HIW"�v"NOR;
    if ( sk > 50 && me->query("mp") > cost ) msg += "�A"HIW"�u"GRN"���Y"HIW"�v"NOR;
    if ( sk > 70 && me->query("mp") > cost*2 ) msg += "�A"HIW"�u"CYN"�ѭ�"HIW"�v"NOR;
    msg += "���V$n�I�I\n\n";
    message_vision(msg, me, target);

    hit = random(me->query_int() + sk);
    hit += random(COMBAT_D->dodge_factor(target, "dodge"));

    if ( hit > 95 ) hit = 95;
    if ( hit < 33 ) hit = 33;

    damage = me->query_int()*3/2 + sk + random(sk/4) + 1;
    if ( !userp(target) ) damage += damage/2;
    damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
    damage -= random(target->query_shield());

    message_vision(HIW"�u"RED"��b"HIW"�v"NOR"���⤤���b�����A�Q�T�M�A��V$n�n�`�I�I", me, target);
    if ( hit > random(100) || target->is_busy() ) {

        if ( damage > 0 ) {

            target->receive_damage("hp", damage, me );
            me->improve_spell("god-kill", 1+random(me->query_int()/7) );


            /* ��ܨ��˦h�� */
            if (me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if (target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");


            /* ���target���A */
            COMBAT_D->report_status(target);

            hit += random(10);              //�R����W
            damage += damage*20/100;        //������W

        } else message_vision("\t���O���G�S���y��$n����ˮ`�C\n", me, target);
    } else message_vision("\t$n���I�a�׶}�F�o�@���C\n", me, target);

    if ( sk > 50 && me->query("mp") > cost ) {
        message_vision(HIW"�u"GRN"���Y"HIW"�v"NOR"�����R��W�G��ܻ�P�A�C�C�|�Q�E���s��$n�U�L�U�n�`�۩I�I�I", me, target);
        if ( hit > random(100) || target->is_busy() ) {
            if ( damage > 0 ) {

                target->receive_damage("hp", damage, me );
                me->improve_spell("god-kill", 1+random(me->query_int()/7) );
                me->start_busy(1);
                me->receive_damage("mp",cost);

                /* ��ܨ��˦h�� */
                if (me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                    tell_object(me,HIY"("+damage+")"NOR);
                if (target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                    tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");


                /* ���target���A */
                COMBAT_D->report_status(target);

                hit += random(10);          //�R����W
                damage += damage*20/100;    //������W

            } else message_vision("\t���O���G�S���y��$n����ˮ`�C\n", me, target);
        } else message_vision("\t$n���I�a�׶}�F�o�@���C\n", me, target);
    }

    if ( sk > 70 && me->query("mp") > cost ) {
        message_vision(HIW"�u"CYN"�ѭ�"HIW"�v"NOR"����B��W�ﰩ�j�A�Q���O�D��V$n�ݤf�n�ޡI�I",me,target);
        if ( hit > random(100) || target->is_busy() ) {
            if ( damage > 0 ) {

                target->receive_damage("hp", damage, me );
                me->improve_spell("god-kill", 1+random(me->query_int()/7) );
                me->start_busy(1);
                me->receive_damage("mp",cost);

                /* ��ܨ��˦h�� */
                if (me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                    tell_object(me,HIY"("+damage+")"NOR);
                if (target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                    tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

                /* ���target���A */
                COMBAT_D->report_status(target);

            } else message_vision("\t���O���G�S���y��$n����ˮ`�C\n", me, target);
        } else message_vision("\t$n���I�a�׶}�F�o�@���C\n", me, target);
    }
    message_vision("\n", me);
    return 1;
}
