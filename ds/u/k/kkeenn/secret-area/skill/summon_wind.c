//�ꭷ�N-Futuer     edit by Kkeenn@DS
#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int delay(object target,object me);
int cast(object me, object target)
{
        int inn,sk,cost,mk,busy,i,damage,shield;
        if(!me) me=this_player();
        inn=me->query_int();
        mk=me->query_spell("summon_wind");
        sk=mk/10+1;
        if(mk <10 ) cost =10; 
        if(mk <15 ) cost =15; 
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


        message_vision("$N��ѼS�D:"HIW"�u"HIY"���F���ж��Щ�"NOR"�ڡI�п��u�ڸ�A���q���A�N�A�Ҿ֦����g�����F�ɵ��ڧa�A\n
�бz���Ӧۦ�誺"HIY"���F"NOR"���V�ڪ��ĤH�a�I�I"HIW"�v\n"NOR,me);

        me->start_busy(5); 
        me->receive_damage("mp",cost); 
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
        sp=me->query_spell("firecloud");
        inn=me->query_int();    
        lv=me->query("level");
        shield=target->query_shield();

        damage = (sp*4+inn*2)/2;  //Max damage=300
        damage -= shield -random(shield/2);

        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
        message_vision("\n�@�}��t�F�l��$N�����g�t�ӥX�A�H�U���b�ˤ��զV$n�����ӨӡI�I\n"NOR,me,target);

        if( damage > 0 )
        {
                if( random(sp*4)+sp/10 > random(100) )   
                {
                        target->receive_damage("hp", damage, me ); 
                        message_vision(HIW" �u��$N�{�פ��ΡA�����Q"HIY"���F"HIW"���A�b��y���o�X�Y�⪺�G�s�I"NOR,target);

                        if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                                tell_object(me,HIY"( �ˮ`: "+damage+")"NOR);
                        if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                                tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                        message_vision("\n",target);
                        if(wizardp(me) && me->query("env/debug")) 
                                tell_object(me,"(debug):  �y��"+damage+"�I�ˮ`!!\n"); 
                        COMBAT_D->report_status(target);         //���target���A
                        me->improve_spell("firecloud",random(inn)+1);
                }
                else
                {
                        target->improve_skill("dodge", 1);
                        me->improve_spell("summon_wind", 1);
                        message_vision(GRN"  $N�N�a�@�ӥ��u�A�T�V�U�����{�X�F�ꭷ�N���d��C\n"NOR,target);
                }
        }
        else {
                me->improve_spell("summon_wind", 1);
                message_vision(GRN"  $N�B�b�}�}�����F�����A�����G�s$N���@�ڤ򳣰ʤ���C\n"NOR,target);
        }

        if( !target->is_fighting(me) ) target->kill_ob(me);
        if( !me->is_fighting(target) ) me->kill_ob(target);

        return 1;
}
