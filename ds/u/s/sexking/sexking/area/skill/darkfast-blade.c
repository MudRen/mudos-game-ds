#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void ccc(object me,object target,int z,int damage);
mapping *action = ({
([
        "action":"$N��$n�ϥX"HIM"�u�t�v�T��--�Ĥ��{�v"NOR"�A�H���֤��t�p���{��̹L$n���e "NOR,
        "damage":    15,
        "dodge" :    20,
        "attact_type":  "bar",
        "damage_type":  "�ٶ�"
]),
([
        "action":"$N��$n�ϥX"HIM"�u�t�v�T��--�����{�v"NOR"�A�H���֤��t�p���{��̹L$n���e "NOR,
        "damage": 22,
        "parry" : 5,
        "attact_type":  "wit",
        "damage_type":  "�ٶ�"
]),
([
        "action":"$N��$n�ϥX"HIM"�u�t�v�T��--�����{�v"NOR"�A�H���֤��t�p���{��̹L$n���e"NOR,
        "damage": 21,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "���"
]),
([
        "action":"$N�ϥX"HIM"�u�t�v����--�������{�v"NOR"�A�@�L�ة۪����G$n "NOR,
        "damage": 21,
        "dodge" : 10,
        "attact_type":  "bar",
        "damage_type":  "���"
]),
([
        "action":"$N�ϥX"HIM"�u�t�v�㦡--�����Y�v"NOR"�A���Φ��ܡA�M���C�v���q�۩I�b$n���W"NOR,
        "damage": 21,
        "dodge" : 20,
        "attact_type":  "bar",
        "damage_type":  "�d��"
]),
([
        "action":"$N�ϥX"HIM"�u�t�v�~��--���������}�v"NOR"�A�C��o�X�F���@�n���T�G�i$n"NOR,
        "damage": 45,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "���j�ˤf"
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
        if (!weapon) return notify_fail("�u�t�v�����y�v�o�n���M�~�i�I�i�C\n");
        if(weapon->query("skill_type")!="blade") return notify_fail(HIM"�t�v�����y"NOR"�D�ݦ��M�~��I�i�C\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("blade")!="darkfast-blade")
                return notify_fail("�A�S���I�i"HIM"�u�t�v�����y�v"NOR"�C\n");
                me->map_skill("blade");
                me->reset_action();
                write("�A�N�u�t�v�����y�v���C�𴲥h�C\n");
                return 1;
        }
        if(me->query("ap")<20 || me->query("hp")<20) return notify_fail("�A�����骬�p�L�k�I�i"HIM"�u�t�v�����y�v"NOR"�C\n");
        //�ĤG��exert
        if(me->query_skill_mapped("blade")=="darkfast-blade")
        {
        if( me->is_ghost() ) return notify_fail("�A�w�O����L�k�I�i�Z�\\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("�A�w�b�B��u�t�v�����y�v�F�C\n");
                if (me->query_skill("darkfast-blade") < 60)
                return notify_fail("�A��ثe�����ٵL�k��|��"HIM"�t�v�����y"NOR"�����q�C\n");
                if(me->query("ap")<50) 
                return notify_fail("�A�ثe�����l�����A�L�k�ϥζ��q�C\n");
                if(!me->can_fight(target)) return me->can_fight(target);
                if(!me->is_fighting(target) ) return notify_fail("�A�õL�b�԰���\n");
                message_vision(HIR"��������?$n���ݤf��M�_�X�F�@�D��]�K,�A�����夣�_����X��....\n\n"NOR,me,target);
                me->receive_damage("ap",15+random(32));
                me->start_busy(1+random(2));
                call_out("ccc",1,me,target,1,damage);
                return 1;
        }
        if(!me->skill_active( "darkfast-blade",(: call_other, __FILE__, "delay", me ,5:), 10))
        return notify_fail("�A�u�t�v�����y�v���ʧ@�٨S�����C\n");
        me->map_skill("blade", "darkfast-blade");
        me->reset_action();
        message_vision(HIC"$N����⤤���M�`�A��}�ϥX�ǳƬI�i"HIM"�u�t�v�����y�v"HIC"���[���C\n"NOR,me);
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
       z=me->query_skill("darkfast-blade");
       msg = HIG"$N�C�n���D:"HIM"�u�t�v�����y�v"HIC"<---��---�C--->......."NOR;
       msg +=HIC"\n\n<---��---�C--->"HIY"���C���ֳs�ײ����L�k�@��,$n���F�o���۹ꤣ��"NOR;
       target->start_busy(2);
       message_vision(msg, me, target);
       if( z >= random(target->query_skill("dodge")) )
       {
       message_vision(HIR"\n\n$n���˦b�a...��y����!!!\n" NOR,me,target);   
       damage = me->query_skill("darkfast-blade")+random(me->query("str")*2) +random(target->query("str"))-target->query_armor()/5 - random(target->query_armor()/5);
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
      message_vision(HIG"\n\n��$n�w�w�P����A�V����D�j�T���C�F"HIC"<---��---�C--->"HIG"���¤O�C\n" NOR,me,target);   
                damage = me->query_skill("darkfast-blade")+random(me->query("str")) +random(target->query("str"))-target->query_armor()/5 - random(target->query_armor()/5);
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

        if( me->query_skill_mapped("blade")!="darkfast-blade" )
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
        me->skill_active( "darkfast-blade",(: call_other, __FILE__, "delay", me :), 8);
}
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{return action[random(sizeof(action))];}
int practice_skill(object me) { return 1; }

