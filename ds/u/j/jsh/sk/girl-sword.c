#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({ 
  
        ([
        "action": "$N�R�����A�A�۳N�@�ܡA�⤤��$w�L�L��Ÿ�A�@�ۡu�m���e�ܡv�A��C�׫d�A\n"
        "$N"HIW"���C�b�����e��$n"HIW"�����ؤ��W�C",
        "damage":                12,
        "dodge" :                18,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "�ζ�",
        ]),
        ([
        "action": "$N��CŸ�ʡA�p�A��ۮi�����A�Ӧ^���d�A�@�ۡu��e��U�v�u�̱o$n���Ἲ�áA\n"
        "�P��$N�۰_�⤤��$w��M�d�V$n��$l�C",
        "damage":                17,
        "dodge" :                22,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "�d��",
        ]),
        ([
        "action": "$N����L�V�e�ۡA�N�C�������e�F�ө������ݫe�A$n�������W��V$N��$l�A\n"
        "$N���ի��D�A�@�ۡu���^�����v�N�⤤$w��$n��$l�@�e�C",
        "damage":                17,
        "dodge" :               -10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),
        ([
        "action": "$N���ɨ��l�A���C�s�y�A�@�Ƭݦ������S���}�쪺�ҼˡA$n�����X���V$N��$l�A\n"
        "����$N��_�Y�ӷL�L�@���A�⤤$w�ݰʡA�@�ۡu�p������v�A�I�V$n��$l�C",
        "damage":                24,
        "dodge" :               -14,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),
        ([
        "action": "$N���S�L���A���ਭ�ߨë��C�V�U���R�X�h�h�A�ݦ������몺�C�v�@�������A\n"
        "��$n�Q����|�i�𤧮ɡA$N���ܤ@�ۡu��î�{���v�A�n�\\�C���A�⤤$w���X�F�@�D�����٦V$n��$l",
        "damage":                33,
        "dodge" :               -25,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),
        
        
});
int exert(object me, object target, string arg)
{
        int sk,damage;
        object weapon;
        mapping type;
        sk=me->query_skill("girl-sword");
        weapon=me->query_temp("weapon");
        if( me->is_ghost() ) return notify_fail("Pray luky �a . . .\n");
        if (!weapon) return notify_fail("�S�C���I�i�u�ɤk�C�k�v�z?\n");
        if(weapon->query("skill_type")!="sword") return notify_fail("�S�C���I�i�u�ɤk�C�k�v�z?\n");

        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="girl-sword")
                        return notify_fail("�A�S�ϡu�ɤk�C�k�v�� !\n");
                me->map_skill("sword");
                me->reset_action();
                write("�u�ɤk�C�k�v�w����ϥΡC\n");
                return 1;
        }

        if(me->query_skill("girl-sword")<3) return notify_fail("�[�o ! ! �ATrain�@���u�ɤk�C�k�v�C\n");
        if(me->query("ap")<20 || me->query("hp")<50) return notify_fail("�A���骬�p���ΡA�A�ϡu�ɤk�C�k�v�|���M�I�C\n");
        
        if(me->query_skill_mapped("sword")=="girl-sword")
        {
        if( me->is_ghost() ) return notify_fail("Pray luky �a !\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("�A���b�ϥΡu�ɤk�C�k�v�F�C\n");
                if (me->query_skill("girl-sword") < 50)
                return notify_fail("�u�ɤk���߼C�v�O�n���¼����ɤk�C�k�g��A�H�A���ҬɡA�|�ݧV�O�C\n");
              if(me->query("ap")<60) 
                return notify_fail("�A���ʥF�A�L�k�ϥX�u�ɤk���߼C�v�C\n");

               if(!me->can_fight(target)) return me->can_fight(target);
               if(!me->is_fighting(target) ) return notify_fail("�A�èS���b�԰���C\n");
                message_vision(HIW"$N�N�⤤"+weapon->query("name")+HIC"�C�b���ܬܦy�A�ǳƨϥX�i�ɤk���߼C�j�C\n\n"NOR,me);
                me->receive_damage("ap",15+random(20));
                me->start_busy(1+random(3));
                call_out("superpower",1,me,target,1,damage);
                return 1;
        }
        
        if(!me->skill_active( "girl-sword",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("�A���ʧ@�������C\n");

        me->map_skill("sword", "girl-sword");
        me->reset_action();
        message_vision("\n"HIM"$N�k�ⴣ�_"+weapon->query("name")+HIC"�����s�_�C���A�}�l�I�i�u�ɤk�C�k�v�C\n"NOR,me);
        me->receive_damage("ap",50);
        me->start_busy(3);
//      me->start_call_out( (: call_other, __FILE__, "delay", me ,10:), 20);
        return 1;
}
void superpower(object me,object target,int z,int damage)
{
       string msg;
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return ;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
      if(!me->is_fighting(target)) me->kill_ob(target);

       z=me->query_skill("girl-sword");

       msg +=HIY" �u"HIR"�F"HIY"�v"HIG"���@�n"NOR"\n\n";
       msg +=HIG"  $N    ��    ��    �@    ½"NOR"\n\n";
       msg +=HIW"    ��      ��     �E     �{"NOR"\n\n";
       msg +=HIW"     ���~�����z�g��$n���ݫe "NOR"\n";

       message_vision(msg, me, target);

       if( z/3 + random(z) > random(target->query_skill("dodge")) )
       {
         damage = me->query_skill("sword") + random(me->query("str")) - target->query_armor()/2 - random(target->query_armor()/2) - (target->query("con"));
         if(damage>220) damage=220+((damage-220)/5);
         if(damage<25) damage=20+random(10);

         message_vision(HIR "\n$n��M�R��ʡA�f���R�X�}�}���A�� . . . . . .�C\n" NOR,me,target);

            
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
            message_vision(HIC "\n$n��榣�����������A���������A�B�Y���T�y�U�F�@�w�N���C\n" NOR,me,target);

       }
       if(!me->is_fighting(target)) me->kill_ob(target);        
}

void delay(object me)
{
        object weapon;
        if( !me ) return;
        
        weapon=me->query_temp( "weapon" );

        if( !weapon || weapon->query("skill_type") != "sword" )
        {
                me->map_skill("sword");
                me->reset_action();
                return;
        }

        if( me->query_skill_mapped("sword")!="girl-sword" )
        {
                return;
        }


        if( me->query("ap")<20 )
        {
                me->map_skill("sword");
                me->reset_action();
                message_vision("\n"HIW"$N"HIC"�����O�����~��ϥΡu�ɤk�C�k�v�C\n"NOR,me);
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap",10);
        me->skill_active( "girl-sword",(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
