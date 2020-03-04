//�w�g  recite-sutra By Tmr PM 02:26 1999/10/16

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost,int times);

int cast(object me, object target, string arg)
{
        int rs_sk,inn,tt;
        inn=me->query_int();
        rs_sk=me->query_spell("recite-sutra");

        if(me->is_ghost() ) 
                return notify_fail("�A�n��g�ӶW��ۤw���`��??\n");
        if(me->is_busy() ) 
                return notify_fail("�A�����ۡA�S���Ű���L�ơC\n");
        tt=(rs_sk/10);
        if( tt <0 )  tt=1;
        if( tt >6 )  tt=6;
        if(arg && !me->is_fighting() )
                return notify_fail("�A�èS���b�԰�...\n");
        if(me->is_fighting() )
        {
        if(rs_sk < 30)
                return notify_fail("�A�|�L�k���g�i�����l�p �j�C\n");
        if( me->query("ap") < tt*30 && me->query("mp") < tt*30 )
                return notify_fail("�̧A�ثe�����A�A�L�k���g�i�����l�p �j�C\n");
        if( !target ) 
                target = offensive_target(me);
        if( !target ) 
                return notify_fail("�A�n��֤��g�i�����l�p �j�H�H\n");  

        message_vision(HIB "\n$N"+ HIB "�~�a�h�F�ƨB�A����X�Q�@�ۦa���F�q�g��C\n" NOR,me);
        me->receive_damage("ap",tt*15);
        me->receive_damage("mp",tt*15);
        me->start_busy(2);

        if( random(150) < rs_sk  )
        {
        message_vision(HIC "\n���M�Ѫ���_�@�}�T�p�A�@�D�{�q�������ʦa���b$N"+ HIC"���W�I�I\n" NOR ,target);
        tell_object(target,"�Aı�o�����@�}�o��.......\n" );
        target->apply_condition("five-thunder", tt );
        target->start_busy(2);
        }
        else message_vision(HIY "���G����Ƥ]�S���o��....\n" NOR ,me);  

        return 1;
        }

        if(me->query("ap")<10 || me->query("mp")<10 ) 
                return notify_fail("�A�{�b�����A���ΡA����A���g�F�C\n");
        if(me->query_temp("is_busy/recite-sutra") )
                return notify_fail("�A�٦��t�@�i�L�A�ө��g�H�H\n");
       
        message_vision(MAG "$N�ŤF�n�򸹡A�}�l���w�_�g��C\n"NOR,me);
        me->improve_spell("recite-sutra",1 + random(1+me->query_int()/4 )+me->query_sou()*3 );
        me->add("exp",1+random(me->query_int()/3)+me->query_sou()*3 ); 
        me->receive_damage("mp", 6 );
        me->receive_damage("ap", 6 );
        me->start_busy(2);
        me->set_temp("is_busy/recite-sutra","�A���b�M�ߩ��g�A�L�k���ʡC");
        me->start_call_out( (: call_other, __FILE__, "delay", me ,6,1:), 3);
        return 1;
}

void delay(object me,int cost,int times)
{
        if(!me) return;
        if(!me->query_temp("is_busy/recite-sutra") || me->is_fighting() )
        {
                 return;
        }
        
        if(times >12 || me->query("mp")< 6 || me->query("ap") < 6 )
        {
                message_vision( MAG"$N�S�F�@�f��A����F�w�g�C\n"NOR,me);
                me->delete_temp("is_busy/recite-sutra");
                return ;
        }
        me->receive_damage("mp",cost );
        me->receive_damage("ap",cost );
        me->improve_spell("recite-sutra",1 + random(1+me->query_int()/4 )+me->query_sou()*3 );
        me->add("exp",1+random(me->query_int() /3)+me->query_sou()*3 );
        me->start_call_out( (: call_other, __FILE__, "delay", me ,cost,times+1:), 3);
}

int valid_learn(object me) { return 1; }

int improve_limite(object ob)
{
        int a;
        a=ob->query_int();
        a=75+a;
        return a;
}

void spell_improved(object me)
{
        int b,addexp;
        b = me->query_spell("recite-sutra");
        addexp=b*b*10*me->query_int();
        tell_object(me,HIG "�A�]�w�g�ᦳ�߱o�A�o��F"+ addexp +"�I�g��ȡC\n");
        me->add("exp",addexp);
        if(b % 15 == 0 && random(90) < b) //�����[int ���|
        {
                tell_object(me, HIR "�A�]�w�g�ӭץX���D�A�A�����z���ɤF�C\n" NOR);
                me->add("addition/int", 1);
        }
        me->save();
}



