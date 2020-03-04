//���Z�СG��a��(bloodsky-force)  
//�ק��tmr��bagi-force...:P

#include <ansi.h>
inherit SKILL;

void delay(object me);

int exert(object me,object target, string arg)
{
        int force,bloodsky,heal;

        force=me->query_skill("force",2);
        bloodsky=me->query_skill("bloodsky-force",2);
        heal=(force+bloodsky)/2;

        if(arg=="off") 
        {
                if(me->query_skill_mapped("force")=="bloodsky-force")
                {
                   message_vision("$N�\\�E���СA���k�����A����@���A½���Ӱ_�A�����ή��L��C\n",me);
                   me->delete_temp("is_busy/bloodsky");
                   me->map_skill("force");
                   return 1;
                } else return notify_fail("�A�èS���b�צ�u��a�ơv���\\�C\n");    
        }

        if(!arg)
        {
           if(me->is_busy() )
                return notify_fail("�A������A���䪺�Ʊ��a�C\n");
           if(me->is_ghost() )
                return notify_fail("�A�{�b�O�F��A�L�k�צ椺�\\�C\n");
           if( me->query_skill_mapped("force")=="bloodsky-force" ) 
                return notify_fail("�A�w���b�צ�y��a�ơz���\\�F�C\n");
           if(me->query("hp") < 10 || me->query("mp") < 10 || me->query("ap") < 10 ) 
                return notify_fail("�A�ثe�����骬�p���n�A�L�k�צ�y��a�ơz���\\�C\n");
           if(me->is_fighting() )
                return notify_fail("�A�����ۥ��[�A�S�ŭצ�y��a�ơz���\\�C\n");
           if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("�A�{�b���b���C\n");
           message_vision(HIB "$N�����R��A��B���\\�A�@�s�R�ǽծ��A�}�l�׽m�y��a�ơz���\\�C\n" NOR,me);
  
           me->receive_damage("hp",3);
           me->receive_damage("mp",3);
           me->receive_damage("ap",3);
            
           me->set_temp("is_busy/bloodsky","�A���b�צ�y��a�ơz���\\�A�Ȯɤ��ಾ�ʡC");
           me->map_skill("force","bloodsky-force");
           me->start_busy(2);
           me->skill_active( "bloodsky-force",(: call_other, __FILE__, "delay", me:), 2);
           return 1;
        }

//��AP��HP

        if(arg=="heal" )
        {
        if(me->is_busy() )
                return notify_fail("�A������....\n");
        if( me->query_skill_mapped("force")=="bloodsky-force" ) 
                return notify_fail("�A���b�צ�y��a�ơz���\\�C\n");
        if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("�A�{�b���b���C\n");
        if(me->query("ap") < heal/3 ) 
                return notify_fail("�A�ثe�����骬�p�A����ϥ����˥\\��C\n");
        message_vision(HIR "$N��߹B��A�餺�@�Ѽ��y�b�u�ʡA���W���ˤf���G��_�F�C\n" NOR,me);
        me->receive_damage("ap",heal/3);
        
        if (me->is_fighting() ) me->receive_heal("hp",heal*(2/3) );
        else me->receive_heal("hp",heal);

        me->start_busy(2);
        me->improve_skill("bloodsky-force",random(10)+1 );
        return 1;
        }

//��MP��AP

        if(arg=="fresh")
        {
        if(me->is_busy() )
                return notify_fail("�A������...\n");
        if( me->query_skill_mapped("force")=="bloodsky-force" ) 
                return notify_fail("�A���b�צ�y��a�ơz���\\�C\n");
        if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("�A�{�b���b���C\n");
        if(me->query("mp") < heal/2 ) 
                return notify_fail("�A�ثe�����骬�p�A�L�k��_���l�C\n");
        message_vision(HIG "$N�B�_���\\�A�餺�u��y�g�|�Ϧ��e�A�_�g�K�ߨ��E�c�p���A�B��@�j�g�ѡC\n" NOR,me);
        me->receive_damage("mp",heal/2);

        if (me->is_fighting() ) me->receive_heal("ap",heal*(2/3) );
        else me->receive_heal("ap",heal);

        me->start_busy(2);
        me->improve_skill("bloodsky-force",random(10)+1);
        return 1;
        }
        return notify_fail("���Z���\\��heal,fresh,���\\��C\n");
}

void delay(object me)
{
        if ( !me 
        ||   !me->query_temp("is_busy/bloodsky")
        ||   me->query_skill_mapped("force")!="bloodsky-force"
        ||    me->is_fighting() )
        {
                me->map_skill("bloodsky-force");
                return;
        }

        if(me->query("hp") < 10 || me->query("mp") < 10 || me->query("ap") < 10 )
        {
                message_vision("$N�\\�E���СA���k�����A����@���A½���K�_�A�����ή��L��C\n",me);
                me->delete_temp("is_busy/bloodsky");
                me->map_skill("force");
                return;
        }       

        //bloodsky-force 70 �j�� (�G�Q�Uexp)

        if (!me->query("senwu/forceok") && me->query_skill("bloodsky-force",1)==70)
        {
                me->add("senwu/bloodsky-force",me->query_int()/3+random(me->query_con()/4)  );
                if (me->query("senwu/bloodsky-force")>200000 )
                {
                        tell_object(me,HIW "�g�L���~���צ�A�A���y��a�ơz���\\��W�@�h�F�I\n" NOR );
                        tell_object(me,HIY "�A�����M�O�q�����F�I\n" NOR );
                        me->add("addition/str", 1);
                        me->add("addition/con", 1);
                        me->set("senwu/forceok",1);
                        me->set_skill("bloodsky-force",75);
                        me->delete("senwu/bloodsky-force");
                }
        }
        else {
                me->improve_skill("bloodsky-force",me->query_int()/3+random(me->query_con()/4)  );
                me->improve_skill("force",me->query_int()/3+random(me->query_con()/4)  );
        }

            me->receive_damage("hp",5);
            me->receive_damage("mp",6);
            me->receive_damage("ap",7);

            me->skill_active( "bloodsky-force",(: call_other, __FILE__, "delay", me:), 3);

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
        b = me->query_skill("bloodsky-force",1);
        c = me->query("skill/bloodsky-force");
        
        if( b % 20==19 && b > c)
        {
                if(random(2))
                {
                        tell_object(me,HIY "�A�����z�����F�I\n" NOR );
                        me->add("addition/int", 1);
                }
                else
                {
                        tell_object(me,HIY "�A����责���F�I\n" NOR );
                        me->add("addition/con", 1);
                }
                
                me->set("skill/bloodsky-force",b);
        }
        me->save();
        return;
}