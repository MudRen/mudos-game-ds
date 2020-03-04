//Adv_�K�����G�K�����\(bagi_force)  
//�K��������G
//        ����    ���m    ���U    ����    �o��
//        10       2       3       1       4
//by tmr AM 02:03 1999/12/4
//update By tmr PM 2000/3/4

#include <ansi.h>
inherit SKILL;

void delay(object me);
void armor(object me,int effect);
void power_up(object me,int effect);

int exert(object me,object target, string arg)
{
        int force,bagi_force,heal;

        force=me->query_skill("force",2);
        bagi_force=me->query_skill("bagi_force",2);
        heal=(force+bagi_force)/2;

//���˥\��A��ap �� hp �A�ޥε��� ���� 1
        if(arg =="heal" )
        {
                if( me->query_skill_mapped("force")=="bagi_force" ) return notify_fail("�A���b�׷ҤK�����\\�C\n");
            	if(me->query("hp") >= me->query("max_hp") ) return notify_fail("�A�����d���p�w�F�A�p�C\n"); // tmr �A�ѤF�o�� add by Luky
            	if(me->query("ap") < heal/2 ) return notify_fail("�A�ثe�����骬�p�A����ϥ����˥\\��C\n");
                
                message_vision( "$N�N���x����y���A����P�ѡA�B�����ˡC\n" ,me); //��@�U���C��M�n�@�I, �@���R��ܴc.luky
                me->receive_damage("ap",heal/2);

// fighting �� {heal*(2/3) } 
// �ޥε��� ���U 4
            if (me->is_fighting() ) me->receive_heal("hp",heal*2/3 );
                        else me->receive_heal("hp",heal*4/5);

                me->start_busy(1);
                me->improve_skill("bagi_force",1+random(force/4)+me->query_int()/5 );
                me->improve_skill("force",1+random(me->query("level"))+me->query_int()/5 );
                return 1;
        }

//�u�K���l�סv �ޥε��� ���m 2
        if(arg=="armor")
        {
                if( me->query_skill_mapped("force")=="bagi_force" ) return notify_fail("�A���b�׷ҤK�����\\�C\n");
                if (bagi_force< 30 ) return notify_fail("�A���K���ߪk�����A�L�k�I�i�u�K���l�סv�C \n");
                if(me->query("ap") < 120 ) return notify_fail("�A�ثe�����A�L�k�I�i�u�K���l�סv�C\n");
                if(me->query_temp("bagi_force/armor")==1) return notify_fail("�A�w�g�b�I�i�u�K���l�סv�C\n");
                if(me->query_temp("bagi_force/power_up")==1) return notify_fail("�A�w�g�b�I�i�u�K�_�Z�v�C\n");

                message_vision(HIG "$N���B�@���A�B���餺���񵷫l�E¶�ۨ���Φ��@�D��l�C \n" NOR,me);
                me->add_temp("apply/armor", heal/3); //�̦h�W�[33 Luky
              me->improve_skill("bagi_force",1+random(force/3)+me->query_int()/4 );
              me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
                me->receive_damage("ap",100);
                me->set_temp("bagi_force/armor",1);
                me->start_busy(2);
                me->skill_active( "bagi_force",(: call_other, __FILE__, "armor", me,heal/3:), 300);
                return 1;
        }
        
//�K�_�Z �ޥε��� �����O 10 ���U 3
        if(arg=="power_up")
        {
                if( me->query_skill_mapped("force")=="bagi_force" ) return notify_fail("�A���b�׷ҤK�����\\�C\n");
                if (bagi_force< 50 ) return notify_fail("�A���K���ߪk�����A�L�k�I�i�u�K�_�Z�v�C \n");
                if(me->query("ap") < 70  || me->query("hp")<120 ) return notify_fail("�A�ثe�����A�L�k�I�i�u�K�_�Z�v�C\n");
                if(me->query_temp("bagi_force/power_up")==1) return notify_fail("�A�w�g�b�I�i�u�K�_�Z�v�C\n");
                if(me->query_temp("bagi_force/armor")==1) return notify_fail("�A�w�g�I�i�F�u�K���l�סv�C\n");

             message_vision(HIY "$N�I�i�K�����Ǥ����u�K�_�Z�v�A�n�ɥ����٦׼ɰ_�I�I \n" NOR,me);
                me->add_temp("apply/damage", heal/2 ); //�̦h�W�[50 Luky
              me->improve_skill("bagi_force",1+random(force/3)+me->query_int()/4 );
              me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
                me->receive_damage("hp",100);
                me->receive_damage("ap",50);
                me->set_temp("bagi_force/power_up",1);
                me->start_busy(2);
                me->skill_active( "bagi_force",(: call_other, __FILE__, "power_up", me,heal/2:), 300);
                return 1;
        }
        return notify_fail("�K�����\\��heal,armor,power_up ���\\��C\n");

}

void armor(object me,int effect)
{
        if(!me) return;
        if(!me->query_temp("bagi_force/armor") ) return;
        message_vision(HIG "$N���l�@�ݡA���h�F�K���@����l�C\n"NOR,me);
        me->add_temp("apply/armor",-effect);
        me->delete_temp("bagi_force/armor");
        return;
}

void power_up(object me,int effect)
{
        if(!me) return;
        if(!me->query_temp("bagi_force/power_up") ) return;
        message_vision(HIG "$N�@�n�C�S�A�����ɰ_���٦׫�_�F���`�����A�C\n"NOR,me);
        me->add_temp("apply/damage",-effect);
        me->delete_temp("bagi_force/power_up");
        return;
}

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        return 1;
}

void skill_improved(object me)
{
        int b,c;
        b = me->query_skill("bagi_force",1);
        c = me->query("skill/bagi_force");//luky
        //bagi_force 80 �j�� (�Q�Uexp)
        if( b > 79 && !me->query("bagi/forceok") )
        {
               	tell_object(me,HIW "�g�L�������׷ҡA�A���K�����\\��W�@�h�F�I\n" NOR );
               	tell_object(me,HIY "�A�����M�O�q�����F�I\n" NOR );
               	me->add("addition/str", 1);
               	me->add("addition/con", 1);
		me->set("bagi/forceok",1); //�аO
               	me->delete("bagi/bagi_force");
		me->save();
        }

        if( b % 20==19 && b > c)
        {
                if(random(2))
                {
                        tell_object(me,HIY "�A���O�q�����F�I\n" NOR );
                        me->add("addition/str", 1);
                }
                else
                {
                        tell_object(me,HIY "�A����责���F�I\n" NOR );
                        me->add("addition/con", 1);
                }
                
                me->set("skill/bagi_force",b);
        }
        me->save();
        return;
}

