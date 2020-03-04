//�ⶳ�x�G�L�W��\(buddha-force)  

#include <ansi.h>
inherit SKILL;

void armor(object me,int effect);
void delay(object me);

int exert(object me,object target, string arg)
{
        int force,buddha,heal;

        force=me->query_skill("force",2);
        buddha=me->query_skill("buddha-force",2);
        heal=(force+buddha)/2;

        if(arg=="off") 
        {
                if(me->query_skill_mapped("force")=="buddha-force")
                {
                   message_vision("$N���_���ӡA����F�צ�L�W��\\�C\n",me);
                   me->delete_temp("is_busy/buddha");
                   me->map_skill("force");
                   return 1;
                } else return notify_fail("�A�èS���b�צ�L�W��\\�C\n");    
        }

        if(!arg)
        {
           if(me->is_busy() )
                return notify_fail("�A������A���䪺�Ʊ��a�C\n");
           if(me->is_ghost() )
                return notify_fail("�A�{�b�O�F��A�L�k�צ椺�\\�C\n");
           if( me->query_skill_mapped("force")=="buddha-force" ) 
                return notify_fail("�A�w���b�צ�L�W��\\�F�C\n");
           if(me->query("hp") < 10 || me->query("ap") < 10 ) 
                return notify_fail("�A�ثe�����骬�p���n�A�L�k�צ�L�W��\\�C\n");
           if(me->is_fighting() )
                return notify_fail("�A�����ۥ��[�A�S�ŭצ�L�W��\\�C\n");
           if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("�A�{�b���b���C\n");
           message_vision(HIB "$N�L���ӧ��A����X���A���ئR��A�}�l�צ�L�W��\\�C\n" NOR,me);
  
           me->receive_damage("hp",5);
           me->receive_damage("ap",5);
            
           me->set_temp("is_busy/buddha","�A���b�צ�L�W��\\�A�Ȯɤ��ಾ�ʡC");
           me->map_skill("force","buddha-force");
           me->start_busy(2);
           me->skill_active( "buddha-force",(: call_other, __FILE__, "delay", me:), 2);
           return 1;
        }

//��AP��HP

        if(arg=="heal" )
        {
        if(me->is_busy() )
                return notify_fail("�A������....\n");
        if( me->query_skill_mapped("force")=="buddha-force" ) 
                return notify_fail("�A���b�צ�L�W��\\�C\n");
        if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("�A�{�b���b���C\n");
        if(me->query("ap") < heal*10/25 ) 
                return notify_fail("�A�ثe�����骬�p�A����ϥ����˥\\��C\n");
        if(me->query("hp") == me->query("max_hp"))
                     return notify_fail("�A�{�b�èS�����ˮ@�C\n");
        message_vision(HIR "$N����X���A�B��R�ǡA���W���ˤf�C�C��_�F�C\n" NOR,me);
        me->receive_damage("ap",heal*10/25);
        
        if (me->is_fighting() ) me->receive_heal("hp",heal);

        else me->receive_heal("hp",heal+heal/2);

        me->start_busy(2);
        me->improve_skill("buddha-force",random(10)+1 );
        return 1;
        }

//�u�L�W������v

        if(arg=="armor")
        {
                if( me->query_skill_mapped("force")=="buddha-force" ) return notify_fail("�A���b�צ�L�W��\\�C\n");
                if (buddha< 20 ) return notify_fail("�A���L�W��\\�������m�A�L�k�I�i�u�L�W������v�C \n");
                if(me->query("ap") < heal*3/2 ) return notify_fail("�A�ثe�����A�L�k�I�i�u�L�W������v�C\n");
                if(me->query_temp("buddha/armor")==1) return notify_fail("�A�w�g�b�I�i�u�L�W������v�F�C\n");

                message_vision(HIG "$N����X���A�L�̰�ۦ򸹡A�|�g��y�g�ۡA�ϥX�u�L�W������v�C\n" NOR,me);

                me->add_temp("apply/armor", heal/2);
                me->improve_skill("buddha-force",me->query_int()/4 );
                me->receive_damage("ap",heal*3/2);
                me->set_temp("buddha/armor",1);
                me->start_busy(2);
                me->skill_active( "buddha_force",(: call_other, __FILE__, "armor", me,heal/3:), 600);
                return 1;
        }
        if(!me->is_fighting())
        {
           if(!target) 
                return notify_fail("�A�Q�������ˡH\n");
           if(target==me) 
                return notify_fail("�A�u�����O�H���ˡA�Y�n�ۦ����˽Х�heal�C\n");
           if(me->is_busy() )
                return notify_fail("�A������A���䪺�Ʊ��a�C\n");
           if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("�A�{�b���b���A�L�k�ϥ����˥\\��@�C\n");
           if(me->query_skill("buddha-force") < 20 )
                return notify_fail("�H�A�L�W��\\���y�ڡA�O�L�k���O�H���˪��C\n");
           if(me->query("ap") < heal*10/25 ) 
                return notify_fail("�A�ثe�����骬�p�A�L�k���O�H���ˡC\n");

           message_vision("$N�B������x�A�祴$n�ݤf�ƤU�A�u��$n�R�X�F�X�f�¦�C\n",me,target);
           message_vision(HIW"$N���W�ˤf�C�C��_�F�C\n" NOR,target);

           target->receive_heal("hp",heal);
           me->improve_skill("buddha-force",random(10)+1);
           me->start_busy(2);
           me->receive_damage("ap",heal*3/2);

           return 1;
        }
        return notify_fail("�L�W��\\��heal,armor,���\\��C\n");
}
void armor(object me,int effect)
{
        if(!me) return;
        if(!me->query_temp("buddha/armor") ) return;
        message_vision(HIG "$N�|�g��y����A�L�W����������F�C\n"NOR,me);
        me->add_temp("apply/armor",-effect);
        me->delete_temp("buddha/armor");
        return;
}

void delay(object me)
{
        if ( !me 
        ||   !me->query_temp("is_busy/buddha")
        ||    me->query_skill_mapped("force")!="buddha-force"
        ||    me->is_fighting() )
        {
                me->map_skill("buddha-force");
                return;
        }

        if(me->query("hp") < 10 || me->query("ap") < 10 )
        {
                message_vision("$N���_���ӡA����F�צ�L�W��\\�C\n",me);
                me->delete_temp("is_busy/buddha");
                me->map_skill("force");
                return;
        }       

        if (!me->query("linwin/forceok") && me->query_skill("buddha-force",1)==85)
        {
               tell_object(me,HIW "�g�L���~���צ�A�A���L�W��\\��W�@�h�F�I\n" NOR );
               tell_object(me,HIY "�A���O�q�B���B���z�M�ӱ������F�I\n" NOR );
               me->add("addition/str", 1);
               me->add("addition/con", 1);
               me->add("addition/int", 1);
               me->add("addition/dex", 1);
               me->set("linwin/forceok",1);
        }
        else {
               me->improve_skill("buddha-force",me->query_int()/5+random(me->query_dex()/5));
               me->improve_skill("force",me->query_int()/5+random(me->query_dex()/5));
        }

            me->receive_damage("hp",6);
            me->receive_damage("ap",6);

            me->skill_active( "buddha-force",(: call_other, __FILE__, "delay", me:), 3);

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
        b = me->query_skill("buddha-force",1);
        c = me->query("skill/buddha-force");
        
        if( b % 20==19 && b > c)
        {
                if(random(2))
                {
                        tell_object(me,HIY "�A�����z�����F�I\n" NOR );
                        me->add("addition/int", 1);
                }
                else
                {
                        tell_object(me,HIY "�A���ӱ������F�I\n" NOR );
                        me->add("addition/dex", 1);
                }
                
                me->set("skill/buddha-force",b);
        }
        me->save();
        return;
}
