#include <ansi.h>
#define SKILL_NAME "�۬r"
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string dir)
{
        //string msg;     
        int damage,sk,ply_poi,cost;
        //object pos_fire;  
        sk=me->query_skill("poision_drop"); 
        ply_poi=target->query_skill("anti_poision"); 
        cost=me->query("level")/2+sk/2; 
        if(!me) return 0; 
        if(me->is_busy()) return notify_fail("�A���ʧ@�٥������C\n");
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("�A�n��֬I"+SKILL_NAME+"?\n");
        if( !living(target) || target->is_corpse() ) 
                return notify_fail("�A�n�����U�r??\n");
        if((int)me->query("mp") < 20 || (int)me->query("ap") < 20 ||(int)me->query("hp")<20)
                return notify_fail("�A�ثe�����骬�p�L�k�Ө��o�ؼ@�r�T\n"); 
       // sk=me->query_skill("poision_drop"); 
      //  ply_poi=target->query_skill("anti_poision"); 
      //  cost=me->query("level")/2+sk/2; 
        message_vision(HIW"\n\t$N����E�E�i�O�F�i�O�E�E���G�E�E���U�F�I"HIG"��"HIW"�ӡE�E"NOR,me,target);  
        me->receive_damage("mp", cost); 
        me->receive_damage("hp", cost);
        me->receive_damage("ap", cost);
        me->add_busy(3); 
 if(random(me->query_skill("poision_drop")*3) <  
    random(target->query("con")*2+target->query_skill("anti_poision")));  
        {
message_vision(HIR"\n\n\t$N�N��W��"HIG"�r��"HIR"��"HIW"$n"HIR"�y�W���F�@��I"HIC"���O�Q$n�{�F�L�h�I\n\n"NOR,me,target); 
        return 1;
        }
        else{
                damage = me->query_skill("poision_drop");
                damage = damage-target->query_skill("anti_poision")/4; 
                damage = me->query("con")*3+damage;
                damage = COMBAT_D->Merits_damage(me,target,damage,"con"); 

                message_vision(HIR"\n\n\t$N�N��W��"HIG"�r��"HIR"��"HIW"$n"HIR"�y�W���F�@��I�����@�r�I\n\n"NOR,me,target);
              
                target->receive_damage("hp", damage,me); 
                target->receive_damage("ap", damage,me);
                target->receive_damage("mp", damage,me);
                COMBAT_D->report_status(target);  

     if( userp(target) ) target->apply_condition("poison", target->query_condition("poison")+ (20+random(5))); 
     else target->apply_condition("poison", target->query_condition("poison")+ (40+random(5))); 
     if(wizardp(me) && me->query("env/debug")) tell_object(me,HIR"\n\t�r�Ȭ��G"+damage+"\n\n"NOR); 
                me->improve_skill("poision_drop", 3+random(me->query_skill("poision_drop")/10));
        }
        
        return 1; 
}

