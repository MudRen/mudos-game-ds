//Edit By Moon From -Firecloud-
//Shiro-spell
#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int delay(object target,object me);
int cast(object me, object target)
{
        int inn,sk,cost,mk,busy,i,damage,shield;
        if(!me) me=this_player();
        inn=me->query_int();
        mk=me->query_spell("shiro-spell");
        sk=mk/10+1;
        if(mk <10 ) cost =10; //�O�ٷs��
        if(mk <15 ) cost =15; //�O�ٷs��
        else cost=(mk*5+inn*3)/12;

        if(environment(me)->query("no_cast")) 
                return notify_fail("�o�̤���I�k�C\n");
        if( (int)me->query("mp") < cost ) 
                return notify_fail("�A���k�O�����C\n");
        if ( !me->is_fighting() )
                return notify_fail("�A�èS���b�԰����C\n");
        if ( !target )
                target = offensive_target(me);
        if ( !target ) 
                return notify_fail("�A�䤣��i�H�I�k���ﹳ�C\n");
        if ( target == me ) 
              return notify_fail("�Q��...��suicide�N�n�F...�A��ı�o�ۤv���ۤv�ܳ·жܡH\n");
        if( !me->can_fight(target)) return me->can_fight(target);
        if( !me->is_fighting(target) ) return notify_fail("�A�èS���M���b�԰����C\n");


        message_vision(HIW" $N�B���x�B����L�A�C�X"HIY"��ù�L"HIW"�G�y"HIG"�{"HIR"�E"HIG"�L"HIR"�E"HIG"��"HIR"�E"HIG"��"HIR"�E"HIG"��"HIR"�E"HIG"�}"HIR"�E"HIG"�C"HIR"�E"HIG"�b"HIR"�E"HIG"�e"HIW"�z\n"NOR,me);

        me->start_busy(2); //�I�k�ʧ@�ɶ�
        me->receive_damage("mp",cost); //�I�k��MP
        me->set_temp("power_cast",1+mk/25);
        call_out( (:delay,target,me:) , 2);
        return 1;
}
int delay(object target,object me)
{
        int inn,sp,damage,shield,lv;
                                                      
        if(!me) return 0;                                     
        if(!target) return notify_fail("�ؼЮ����F�C\n");      
        if( environment(me) != environment(target) )       
                return notify_fail("�ؼ����}�F�A���I�k�d��C\n");

        me->delete_temp("power_cast");
        sp=me->query_spell("shiro-spell");
        inn=me->query_int();    
        lv=me->query("level");
        shield=target->query_shield();

        damage = (sp*4+inn*2)/2;  //Max damage=300
        damage -= shield -random(shield/2);

        // �W�[�����ˮ`���v�T
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
        message_vision(HIW"\t\t\n$N��D�G�y�աE���E���E���@�ķ��ġz�I�I\n"
                       HIW"\t\t\n�j�����~��$N���I����A���ժ���}�����šE�E�E\n"
                       HIW"\t\t\n�E�D"HIY"����"HIW"�e�X�I�I\n"
                       HIR"\t\t\n����$n���⤣��\n"NOR,me,target);

        if( damage > 0 )
        {
//              if( random(sp*3) > random(100) )   //Max �E���R���v
                if( random(sp*4)+sp/10 > random(100) )   
                {
                        target->receive_damage("hp", damage, me ); 

        message_vision(HIR"�u��$N�{�פ��ΡA�����Q�E�D"HIW"���~"HIR"Ţ�n�A�o�X�Y�⪺�s�z�I"NOR,target);

                        if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                                tell_object(me,HIY"( �ˮ`: "+damage+")"NOR);
                        if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                                tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                        message_vision("\n",target);
                        if(wizardp(me) && me->query("env/debug")) 
                                tell_object(me,"(debug):  �y��"+damage+"�I�ˮ`!!\n"); 
                        COMBAT_D->report_status(target);         //���target���A
                        me->improve_spell("shiro-spell",random(inn)+1);
                }
                else
                {
                        target->improve_skill("dodge", 1);
                        me->improve_spell("shiro-spell", 1);
                        message_vision(HIM"$N���{�k�{�A�{�L�F���E�D���~\n"NOR,target);
                }
        }
        else {
                me->improve_spell("shiro-spell", 1);
                message_vision(HIM"$N�����ҰʡA�������ƸѼƹD����C\n"NOR,target);
        }

        if( !target->is_fighting(me) ) target->kill_ob(me);
        if( !me->is_fighting(target) ) me->kill_ob(target);

        return 1;
}


