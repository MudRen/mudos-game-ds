#include <ansi2.h>
inherit SSERVER;
inherit SKILL;

int delay(object target,object me);
int delay2(object target,object me,int damage);

int cast(object me, object target)
{
        int inn,sk,cost,mk,busy,i,damage,shield;
        if(!me) me=this_player();
        inn=me->query_int();
        mk=me->query_spell("elemental-firecloud");
        sk=mk/10+1;
        if(mk <25 ) cost =3; //�O�ٷs��
        if(mk <40 && mk >= 25) cost =6; //�O�ٷs��
        else{
        cost=(mk+inn)/5;}
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
              return notify_fail("�Q��...��suicide�N�n�F...�A��ı�o�ۤv���ۤv�ܳ·ж�?\n");
        if( !me->can_fight(target)) return me->can_fight(target);
        if( !me->is_fighting(target) ) return notify_fail("�A�èS���M���b�԰����C\n");


        message_vision(
        HIY"$N"HIY"�f������D�G�u"HIR"���K���F�Fù�ҳD"HIY"�ڡA�i�滷�j�������ɭԨ�F�I\n"
        HIY"���Ӧۦa����"HIR"����"HIY"�]�������ڪ��ĤH�a!!"HIY"�v\n"NOR,me);

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
        if(!target) return notify_fail("�A�n�����H�Ҷ]�F...\n");      
        if( environment(me) != environment(target) )       
                return notify_fail("�ؼ����}�F�A���I�k�d��C\n");

        me->delete_temp("power_cast");
        sp=me->query_spell("elemental-firecloud");
        inn=me->query_int();    
        lv=me->query("level");
        shield=target->query_shield();

        damage = (sp*4+inn*1)/2;  //Max damage=120
        damage -= shield -random(shield/2);

        // �W�[�����ˮ`���v�T
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
        message_vision("\n�@�D�j�j���V��$N�F�ⶡ�֮g�ӥX, �����]�S�F$n�I�I"NOR,me,target);

        if( damage > 0 )
        {
//              if( random(sp*3) > random(100) )   //Max �E���R���v
                if( random(sp*4)+sp/10 > random(100) )   
                {
                        target->receive_damage("hp", damage, me ); 

                        message_vision("  "HIW"�u��$N�{�פ���, �����Q���J"HIR"����"HIW"����, �b�����j�����o�X�Y�⪺�s�z�I"NOR,target);
                        if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                                tell_object(me,HIY"( �ˮ`: "+damage+")"NOR);
                        if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                                tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                        message_vision("\n",target);
                        if(wizardp(me) && me->query("env/debug")) 
                                tell_object(me,"(debug):  �y��"+damage+"�I�������`��!!\n"); 
                        COMBAT_D->report_status(target);         //���target���A
                        me->improve_spell("god-fire",random(inn)+1);
                }
                else
                {
                        target->improve_skill("dodge", 1);
                        me->improve_spell("elemental-firecloud", 1);
                        message_vision(GRN"  $N�N�a�@�ӥ��u�A�T�V�U�������}�F�����N��ŧ���C\n"NOR,target);
                }
        }
        else {
                me->improve_spell("elemental-firecloud", 1);
                message_vision(GRN"  $N���b��������������, ���O�L�g�����]�k�O�q�N���K�j���b�~�C\n"NOR,target);
        }
        if( !target->is_fighting(me) ) target->kill_ob(me);
        if( !me->is_fighting(target) ) me->kill_ob(target);

        // ���
        if( me->query_spell("elemental-firecloud") > 79 && inn > random(120) )
        {
                call_out((:delay2,target,me,damage:),2+random(3) );
                me->start_busy(1);
        }
        return 1;
}

int delay2(object target,object me,int damage)
{
        int sp;
        if(!me) return 1;
        sp=me->query_spell("elemental-firecloud");
        if( !me || !target) return 1;
        if( environment(me) != environment(target) ) return 1;

        message_vision(HIR"���M$N"HIR"���]�O���o�F�֭n�����������A���������M�A�צb$n"HIR"���䬵���}�ӡI"NOR,me,target);

        if(me->query_int() > target->query_int() )
                damage-=target->query_shield()/4; //��z���¤O
        else    
                damage-=target->query_shield()/3;   //��z���¤O


        if( damage<0 )
        {
                message_vision(GRN"  $N"GRN"���䬵���}�Ӫ������A���G�S����$N"GRN"�y�����@���ˮ`�C\n"NOR,target);
                return 1;
        }

        if( random(sp*2) > random(100) ) {
                message_vision(HIC"  $N"HIC"�Q�j�j���O�q����A�ѤF�{�סA�Q�����N�ˤF�I"NOR,target);
                target->receive_damage("hp",damage,me);  
                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        tell_object(me,HIY"("+damage+")"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                message_vision("\n",target);
                if(wizardp(me) && me->query("env/debug")) 
                        tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
                COMBAT_D->report_status(target);         //���target���A
        }
        else message_vision(GRN"\n  �u��$N"GRN"�@�Ӱ{���A���}�F�������U�N�d��C\n"NOR,target);

        me->improve_spell("elemental-firecloud",random( me->query_int()/2 ));
        return 1;
}
