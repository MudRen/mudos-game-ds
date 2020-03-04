/*      ���Z�u��(god-fire)
        Write  1999.10.3  Acme@DS
        update 1999.10.15 ��s��: Luky QCer: Luky
        update 2000/4/7 -By Tmr-
        update 2001/10/20 Acme@DS
*/

#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast_fire(object target,object me,int god_fire,int me_int);
int cast_fires(object target,object me,int damage,int probit,int i);

int cast(object me, object target)
{
        /* �ܼƻ���
                god_fire        �ϥΪ̯��Z�u��(god-fire)����
                me_int          �ϥΪ̴��z(Int)
                cost            �I�i�k�N�ӷl���]�O��(MP)
                probit          ���������R���v
                damage          ����������O
        */
        int god_fire,me_int,cost;

        god_fire = me->query_spell("god-fire");
        me_int = me->query_int();
        cost = god_fire/3;

        if( me==target )
                return notify_fail("�A�Q�n��ۤw�I�k�H\n");
        if ( !target )
                target = offensive_target(me);
        if ( !target ) 
                return notify_fail("�A�䤣��i�H�I�k���ﹳ�C\n");
        if( me->query("mp") < cost )
                return notify_fail("�k�O�����A�L�k�I�k�C\n");
        if( !me->is_fighting(target) )
                return notify_fail("�A�èS���M���b�԰����C\n");
        if( !me->can_fight(target))
                return me->can_fight(target);

        message_vision("$N����X�Q�A���ۻy�D�G"HIW"�u"HIG"�Ѧa�X�w�A���X���A�|�ɦX�ǡA�����X���H���ġC"HIW"�v\n"NOR,me);

        me->start_busy(1);
        me->set_temp("is_busy",1);
        me->receive_damage("mp",cost);
        call_out( (:cast_fire,target,me,god_fire,me_int,cost:) , 1);
        return 1;
}

int cast_fire(object target,object me,int god_fire,int me_int)
{
        int probit,damage;
        if( !me ) return 0;                                     
        me->delete_temp("is_busy");
        if( !target ) return notify_fail("�ؼЮ����F�C\n");      
        if( environment(me) != environment(target) )       
                return notify_fail("�ؼ����}�F�A���I�k�d��C\n");

        damage = god_fire+random(me_int);
        damage -= random(target->query_shield());
        // �W�[�����ˮ`���v�T
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");

        message_vision("\n��M$N��W�P�K�Ĥ�,���_�@�D"HIW"�y"HIR"���Z�u��"HIW"�z"NOR"���N�V$n�I�I\n"NOR,me,target);

        probit=me->query_temp("probit/god-fire");
        probit+=me->query_spell("god-fire")+me->query_int();
        probit-=random(target->query_skill("dodge")+target->query_dex());

        if( probit > random(100) )
        {
                target->receive_damage("hp", damage, me ); 

                message_vision(HIR"\t�u��$N"HIR"�{�������@�D"HIW"�y"HIR"���Z�u��"HIW"�z"HIR"����աA�Q�N�o�ֶ}�׺�I"NOR,target);

                if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        tell_object(me,HIY"( �ˮ`: "+damage+")"NOR);
                if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                        tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                if(wizardp(me) && me->query("env/debug")) 
                        tell_object(me,"(debug):  �y��"+damage+"�I�ˮ`!!\n"); 

                message_vision("\n",target);
                COMBAT_D->report_status(target);         //���target���A
                me->improve_spell("god-fire",me_int+random(me->query("level")) );

                if( probit > random(140)+1 && me->query("mp")>10 && god_fire > 59 )  //�l��
                {
                        me->set_temp("is_busy",1);
                        me->set_temp("probit/god-fire",0);
                        call_out( (:cast_fires,target,me,damage,probit,1:) , 1);
                        return 1;
                }
        }
        else
        {
                message_vision(GRN"\t�u��$N"GRN"�F�{����A�n���e�����}�@�D�u���Z�u���v���r�P��աC\n"NOR,target);
                me->improve_spell("god-fire",random(me_int));
                me->add_temp("probit/god-fire");        //�p��𥼯ॴ���A�h�֥[�R��
        }

        if( !target->is_fighting(me) ) target->kill_ob(me);
        if( !me->is_fighting(target) ) me->kill_ob(target);

        return 1;
}

int cast_fires(object target,object me,int damage,int probit,int i)
{
        if( !me ) return 1;
        me->delete_temp("is_busy");
        if( !target ) return 1;
        if( environment(me) != environment(target) ) return 1;
        if( !me->can_fight(target)) return 1;
        if( !me->is_fighting(target) ) return 1;

        message_vision(HIW"�b�����I�I$N"HIW"���I��X�{�ƹD"HIR"���s"HIW"�A���˦ӥX�A���ĦV$n"HIR"�I�I\n"NOR,me,target);

        if( probit > random(100) )
        {
                damage=damage*70/100;
                target->receive_damage("hp",damage,me);  
                message_vision(HIR"\t�u��$N�@�ɤ������L�ӡA�G�s�@�n�A�Q���s���]���F�I�I"NOR,target);

                if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        tell_object(me,HIY"( �ˮ`: "+damage+")"NOR);
                if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                        tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                if(wizardp(me) && me->query("env/debug")) 
                        tell_object(me,"(debug):  �y��"+damage+"�I�ˮ`!!\n"); 

                message_vision("\n",target);
                COMBAT_D->report_status(target);         //���target���A
                me->improve_spell("god-fire",me->query("int"));

                if( probit > random(180)+1 && i)
                {
                        me->set_temp("is_busy",1);
                        call_out( (:cast_fires,target,me,damage,probit,0:) , 1);
                        return 1;
                }
        }
        else
                message_vision(GRN"\t�u��$N"GRN"�W��{�L�F���s���l���C\n"NOR,target);
        return 1;
}
