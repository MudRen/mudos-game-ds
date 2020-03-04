#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void ccc(object me,object target,int z,int damage);
mapping *action = ({
([
        "action":"$N�ϥX�v�����G�M�y��"HIC"�u�G�q���v"NOR"�A�ϥ���W���M�V$n�e�t���A�t�@��]�H�ΦӨ� "NOR,
        "damage":    15,
        "dodge" :    20,
        "attact_type":  "bar",
        "damage_type":  "���"
]),
([
        "action":"$N�ϥX�v�����G�M�y��"HIG"�u�Q�r���v"NOR"�A�N���M��e���V$n���ߺ� "NOR,
        "damage": 22,
        "parry" : 5,
        "attact_type":  "wit",
        "damage_type":  "���"
]),
([
        "action":"$N�ϥX�v�����G�M�y��"HIR"�u�e�t�è�v"NOR"�A���⮳��$w���_���V$n�e�t�è�"NOR,
        "damage": 24,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "���"
]),
([
        "action":"$N�ϥX�v�����G�M�y��"HIR"�u�W�C����v"NOR"�A�@�M���a�A�@�M�����H�U�¤W��V$N����"NOR,
        "damage": 25,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "�������"
]),
([
        "action":"$N�ϥX�v�����G�M�y����q"HIM"�u���P���ű١v"NOR"�A�����p���P���šA�S�p�e����٦V$n"NOR,
        "damage": 40,
        "dodge" : 20,
        "attact_type":  "bar",
        "damage_type":  "�ٶ�"
]),
});
int exert(object me, object target, string arg)
{
        int sk,damage;
        object weapon;
        mapping type;
        sk=me->query_skill("sea-blade");
        weapon=me->query_temp("weapon");
        if( me->is_ghost() ) return notify_fail("�����H...?\n");
        if (!weapon) return notify_fail("�u�v�����G�M�y�v�o�n���M�~�i�I�i�C\n");
        if(weapon->query("skill_type")!="blade") return notify_fail(HIC"�v�����G�M�y"NOR"�D�ݦ��M�~��I�i�C\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("blade")!="left-blade")
                return notify_fail("�A�S���I�i"HIM"�u�v�����G�M�y�v"NOR"�C\n");
                me->map_skill("blade");
                me->reset_action();
                write("�A�N�u�v�����G�M�y�v���C�𴲥h�C\n");
                return 1;
        }
        if(me->query("ap")<20 || me->query("hp")<20) return notify_fail("�A�����骬�p�L�k�I�i"HIC"�u�v�����G�M�y�v"NOR"�C\n");
        //�ĤG��exert
        if(me->query_skill_mapped("blade")=="left-blade")
        {
        if( me->is_ghost() ) return notify_fail("�A�w�O����L�k�I�i�Z�\\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("�A�w�b�B��u�v�����G�M�y�v�F�C\n");
                if (me->query_skill("left-blade") < 50)
                return notify_fail("�A��ثe�����ٵL�k��|��"HIC"�v�����G�M�y"NOR"�����q�C\n");
                if(me->query("ap")<50) 
                return notify_fail("�A�ثe�����l�����A�L�k�ϥζ��q�C\n");
                if(!me->can_fight(target)) return me->can_fight(target);
                if(!me->is_fighting(target) ) return notify_fail("�A�õL�b�԰���\n");
                message_vision(HIR"$N��M�N�⤤���M�Ϥ��e�A���n�[�աA��V�G�H...\n\n"NOR,me,target);
                me->receive_damage("ap",15+random(32));
                me->start_busy(1+random(2));
                call_out("ccc",1,me,target,1,damage);
                return 1;
        }
        if(!me->skill_active( "left-blade",(: call_other, __FILE__, "delay", me ,5:), 10))
        return notify_fail("�A�u�t�v�����y�v���ʧ@�٨S�����C\n");
        me->map_skill("blade", "left-blade");
        me->reset_action();
        message_vision(HIG"$N�N���M��e���R,�b�Ѫŵe�F�Ӷ�,�I�i�X"HIC"�v�����G�M�y"HIG"...�C\n"NOR,me);
        me->receive_damage("ap",15);
        me->start_busy(2);
        return 1;
}
void ccc(object me,object target,int z,int damage)
{
       string msg;
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return ;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
       if(!me->is_fighting(target)) me->kill_ob(target);
       z=me->query_skill("left-blade");
       msg = HIC"\n$N��M��}�@���A�ϥX"HIR"�i���q�j"HIY"�i�g�P�ѥ��Q���١j!!!\n"NOR;
       msg +=HIC"\n��M�@�}�M���C�v...�C���n�T�p����!!\n"NOR;
       target->start_busy(2);
       message_vision(msg, me, target);
       if( z >= random(target->query_skill("dodge")) )
       {
        message_vision(HIR"\n\n$n�b�o�@�b�����F�X�M�Ƥ]�Ƥ��M..�y�ɤM�˲ֲ�.." NOR,me,target); 
       damage = me->query_skill("left-blade")+random(me->query("str")*2) +random(target->query("str"))-target->query_armor()/5 - random(target->query_armor()/5);
       damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
       target->receive_damage("hp",damage,me);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
       tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
       tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       COMBAT_D->report_status(target);
       
       }
       else {
          message_vision(HIG"\n\n$n���ζդ���A�Ψ���}�A���٬O�Q���F�X�M�C" NOR,me,target);   
       damage = me->query_skill("left-blade")*1/2+random(me->query("str")) +random(target->query("str"))-target->query_armor()/5 - random(target->query_armor()/5);
       damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
       target->receive_damage("hp",damage,me);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
       tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
       tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       COMBAT_D->report_status(target);
    
       }
if(!me->is_fighting(target)) me->kill_ob(target);   
}
void delay(object me)
{
        object weapon;
        if( !me ) return;
        
        weapon=me->query_temp( "weapon" );

        if( !weapon || weapon->query("skill_type") != "blade" )
        {

                me->map_skill("blade");
                me->reset_action();
                return;
        }

        if( me->query_skill_mapped("blade")!="left-blade" )
        {
                return;
        }

        if( me->query("ap")<20 )
        {
                me->map_skill("blade");
                me->reset_action();
                message_vision(NOR"\n$N�R�F�X�f�A��A�ݼˤl�w���l���L�C\n"NOR,me);
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( "left-blade",(: call_other, __FILE__, "delay", me :), 8);
}
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{return action[random(sizeof(action))];}
int practice_skill(object me) { return 1; }
