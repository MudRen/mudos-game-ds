#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void ccc(object me,object target,int z,int damage);
mapping *action = ({
([
        "action":"$N���M���Τ@���ϥX�u"HIC"�g���ʤ�"NOR"�v�A��զ��p�g�ܮ������L$n���e"NOR,
        "damage":    30,
        "dodge" :    20,
        "attact_type":  "bar",
        "damage_type":  "����"
]),
([
        "action":"$N�@�ɧ�խ�F�ϥX�u"HIC"�b���г�"NOR"�v�A�⤤$w�����i���p�b�����$n
�L�k�۬["NOR,
        "damage": 30,
        "parry" : 5,
        "attact_type":  "bar",
        "damage_type":  "����"
]),
([
        "action":"$N�⤤�ۦ����M���èϥX�u"HIC"�î�����"NOR"�v�A�b$n�鱫���ɩ��M�s��"NOR,
"damage": 30,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "�_��"
]),
([
        "action":"$N�r�M�@���u"HIC"�Q������"NOR"�v�A�ۦ��@�L�ةۥO$n�L�k��m "NOR,
        "damage": 30,
        "dodge" : 10,
        "attact_type":  "bar",
        "damage_type":  "�_��"
]),
([
        "action":"$N�⤤$w���_�۰ʨϥX�u"HIC"����L��"NOR"�v�A�ۦ����M�Ѧ��A�@�L������
���b$n���W"NOR,
        "damage": 30,
        "dodge" : 20,
        "attact_type":  "bar",
        "damage_type":  "����"
]),
});

int exert(object me, object target, string arg)
{
        int sk,damage;
        object weapon;
        mapping type;
        sk=me->query_skill("jurlong-awi");
        weapon=me->query_temp("weapon");
        if( me->is_ghost() ) return notify_fail("�����H...?\n");
        if (!weapon) return notify_fail("�u�������q�v�o�n���l�~�i�I�i�C\n");
        if(weapon->query("skill_type")!="hammer") return notify_fail(HIC"�������q"NOR"�D�ݦ��l�~��I�i�C\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("hammer")!="jurlong-awi")
                return notify_fail("�A�S���I�i"HIC"�u�������q�v"NOR"�C\n");
                me->map_skill("hammer");
                me->reset_action();
                write("�A�N�u�������q�v���Q�𴲥h�C\n");
                return 1;
        }
        if(me->query("ap")<20 || me->query("hp")<20) return notify_fail("�A�����骬�p�L�k�I�i"HIM"�u�������q�v"NOR"�C\n");
        //�ĤG��exert
 if(me->query_skill_mapped("hammer")=="jurlong-awi")
        {
        if( me->is_ghost() ) return notify_fail("�A�w�O����L�k�I�i�Z�\\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("�A�w�b�B��u�������q�v�F�C\n");
                if (me->query_skill("jurlong-awi") < 91)
                return notify_fail("�A��ثe�����ٵL�k��|��"HIC"����"NOR"�����q�C\n");
                if(me->query("ap")<50) 
                return notify_fail("�A�ثe�����l�����A�L�k�ϥζ��q�C\n");
                if(!me->can_fight(target)) return me->can_fight(target);
                if(!me->is_fighting(target) ) return notify_fail("�A�õL�b�԰���\n");
                message_vision(HIC"���M�@�n��q�A$N�⤤$n�@��A�ϥX�F"HIR"��������"HIC"
                �A�O�H�ԷX\n"NOR,me,target);
                me->start_busy(1);
                call_out("ccc",1,me,target,1,damage);
                me->start_busy(1);
                return 1;
        }
        if(!me->skill_active( "jurlong-awi",(: call_other, __FILE__, "delay", me ,5:), 10))
        return notify_fail("�A�u�������q�v���ʧ@�٨S�����C\n");
        me->map_skill("hammer", "jurlong-awi");
        me->reset_action();
        message_vision(HIC"$N����⤤��$n�A��}�ϥX�ǳƬI�i"HIM"�u�������q�v"HIC"
 ���[���C\n"NOR,me);
        me->receive_damage("ap",40);
        me->start_busy(1);
        return 1;
}
void ccc(object me,object target,int z,int damage)
{
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return ;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
       if(!me->is_fighting(target)) me->kill_ob(target);
       z=me->query_skill("jurlong-awi");
             me->start_busy(1); 
             target->start_busy(3);
     message_vision(HIC"\n�u��$N���M�R��ʦ��p������ӡK\n"NOR, me);                   message_vision(HIM"�@�@$N���M�⤤�ۦ��������X�̱j�@���K\n\n"NOR, me);
     message_vision(HIM"  $N�ϥX - ���q "HIY"�y "HIC"�X"HIM"��"HIC"�X"HIM"��"HIC"�X"HIM"�� "HIC"�X"HIM"�U"HIY"�z\n"NOR, me);
 
      if( z >= random(target->query_skill("dodge")) )
       {
       message_vision(HIR"\n\n$n�Q���𱲤J...�L�k��B���쭫��!!!\n" NOR,me,target);   
       damage = me->query_skill("jurlong-awi")+random(me->query("str")*5)
       +random(me->query_damage())-target->query_armor()/5-random(target->query("dex")*3);
       if(damage < 1) { damage = random(60)+me->query_skill("jurlong-awi"); } 
       damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
       target->receive_damage("hp",damage,me);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
       tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
       tell_object(target,HIR"("+damage+")"NOR+"   ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       COMBAT_D->report_status(target);
      
       }
       else {
      message_vision(HIG"\n\n��$n�w�w�P����A���O��������d��"HIC"�������q"HIG"���¤O�j�j���C�F�C\n" NOR,me,target);   
       damage = me->query_skill("jurlong-awi")+random(me->query("str")*3)   +random(me->query("damage")) - random(target->query("dex")*2);
       if(damage < 1) { damage = random(me->query_skill("jurlong-awi")); }
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

        if( !weapon || weapon->query("skill_type") != "hammer" )
        {

                me->map_skill("hammer");
                me->reset_action();
                return;
        }

        if( me->query_skill_mapped("hammer")!="jurlong-awi" )
        {
                return;
        }

        if( me->query("ap")<20 )
        {        me->map_skill("hammer");
                me->reset_action();
                message_vision(NOR"\n$N���M�@�}�F�O�A�ݼˤl�w���l���L�C\n"NOR,me);
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( "jurlong-awi",(: call_other, __FILE__, "delay", me :), 8);
}
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
     return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }







