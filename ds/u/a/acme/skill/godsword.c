#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
void firesword(object me,object target,int damage);
mapping *action = ({
        ([
        "action": "$N�C���s���A�ۤ��M�ۡA�@�C���ۤ@�C�A\n\t�@�ۡu��魸�r�v�A�ⴤ$w��$n��������h",
        "damage":                15,
        "dodge" :                10,
        "parry" :                -8,
        "attact_type":  "bio",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(bio) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�@���u½���ЫB�v�A�ڦp�s���A�B�p��R�A�ⴤ$w�s��$n���ܡB�e�áB���y�A�C�B�j��",
        "damage":                10,
        "dodge":                 -5,
        "parry" :                14,
        "attact_type":  "bio",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�C�լ�S�@�ܡA�ѻ��F���֡A�ର�I�p�����A\n\t�@���u�g���Ѫe�v�A�ⴤ$w��$n��A�ӥh",
        "damage":                17,
        "dodge" :               -10,
        "parry" :                10,
        "attact_type":  "bio",
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�@�ۡu�M������v�����R��A�ت`�C�y�A���x�}�����C�Z�A\n\t�⤤$w���a��$n�ߺ۱��h",
        "damage":                13,
        "dodge" :                20,
        "parry" :                -10,
        "attact_type":  "bio",
        "damage_type":  "�C��",
        ]),

        ([
        "action": "$N�ⴤ$w�ݤ��X�@�ۡu�}�H��šv�A�C�y�T�I�A\n\t���I$n�����ءy�t���z�B�y�Ůڡz�A�y�����z�A�T�B�j��",
        "damage":                10,
        "dodge" :               -10,
        "parry" :                15,
        "attact_type":  "bio",
        "damage_type":  "���",
        ]),
});
int exert(object me, object target, string arg)
{
        int slv,flv,armor,shield,level,damage;
        object weapon;
        weapon=me->query_temp("weapon");
        slv=me->query_skill("sword");
        flv=me->query_spell("god-fire");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="godsword")
                        return notify_fail("�A�èS���ϥί��Z�C�Z�C\n");
                me->map_skill("sword");
                me->reset_action();
                write("�ޯ�[���Z�C�Z]�w�����C\n");
                return 1;
        }
        if(!weapon) return notify_fail("�ϥί��Z�C�Z�����⤤�n���C�C\n");
        if(weapon->query("skill_type")!="sword") return notify_fail("�ϥί��Z�C�Z�����⤤�n���C�C\n");
        if(me->query_skill("sword")<10) return notify_fail("�A���C�k��¦�����L�k�ϥί��Z�C�Z�C\n");
        if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥί��Z�C�Z�C\n");

        //�ĤG��exert
        if(me->query_skill_mapped("sword")=="godsword")
        {
            if(me->is_ghost()) return notify_fail("�����F�A�٭n�X�Ӯ`�H�H\n");
            if(!target) target = offensive_target(me);
            if(!me->is_fighting()) return notify_fail("�A�w���b�I�i�u���Z�C�k�v�F�C\n");
            if(me->query_skill("godsword") < 49 ) return notify_fail("�̧A�ثe���Z�C�k���y�ڡA�L�k�ϥε��ۡC\n");
            if(me->query_spell("god-fire") < 49 ) return notify_fail("�̧A�ثe���Z�u�����y�ڡA�L�k�t�X�C�k�ϥε��ۡC\n");
            if(me->query("ap")<49) return notify_fail("�A�ثe�����l�����A�L�k�ϥε��ۡC\n");
            if(me->query("mp")<49) return notify_fail("�A�ثe���k�O�����A�L�k�ϥε��ۡC\n");
            if(!me->is_fighting()) return notify_fail("�԰��פ�F�A�Ӱ���F�C\n");
            if(!target) return notify_fail("�ؼЮ����F�C\n");      
            if( environment(me) != environment(target) ) return notify_fail("�ؼ����}�F�A�������d��C\n");

          //�����ʪ��n�S�O�`�N�n�[�U�����.
          if(!me->can_fight(target)) return me->can_fight(target);
          if(me->query_temp("firepower") > 0)
          {
             armor=target->query_armor();
             shield=target->query_shield();
             damage=(slv*2/3)+(flv*2/3);
             damage -= (random(armor)+shield);
             if(damage<50) damage=random(50)+30;
             switch( me->query_temp("firepower") ) {
               case 1:
                 message_vision("$N�@��" +HIR+ "�y" +NOR+ "���_���D" +HIR+ "�z" +NOR+ "�A�⤤" +weapon->name()+NOR+ "�A����$n�ܤߡA�C�y�ɥX�L�Ƥ��K�I�I\n",me,target);
                 break;
               case 2:
                 message_vision("$N�@��" +HIR+ "�y" +NOR+ "���ۼC�e" +HIR+ "�z" +NOR+ "�A�⤤" +weapon->name()+NOR+ "�A�U��d���A$n�ܤߡA�C�y«�X�L�Ƥ��D�I�I\n",me,target);
                 damage += 70+random(40);
                 break;
               case 3:
                 message_vision("$N�@��" +HIR+ "�y" +NOR+ "�Ѥ��R��C����" +HIR+ "�z" +NOR+ "�A�⤤" +weapon->name()+NOR+ "�����|�g�A�C��|���A����$n�ߺۡA�C�y�ĥX�L�Ƥ��s�I�I\n",me,target);
                 damage += 130+random(60);
                 break;
               }

               me->delete_temp("firepower");

            if( random(me->query_skill("godsword"))+random(flv) > random(99) )
            {
             message_vision(HIR"$n�����L$N�r�P����աA�Q�P�K���]�S�F�I�I"NOR,me,target);
             //�W�[�����ˮ`���v�T
             damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
             target->receive_damage("hp",damage,me);
             if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
             if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
             message_vision("\n",target);
             if(wizardp(me) && me->query("env/debug")) tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
             COMBAT_D->report_status(target);         //���target���A
            }
            else {
               message_vision(HIW"  �u��$N�W�W�i�i�a�V�@�Ǻu�F�}�ӡC\n"NOR,target);
            }
               me->start_busy(1);
          }
          else {
            message_vision(HIW"$N�f����ᦳ���A�⤤"+weapon->query("name")+HIW "�����x�_�벴�����A�@�ѯP�V�]���"+weapon->query("name")+"�C\n\n"NOR,me);
            me->start_busy(1);
            call_out("firesword",2,me,target,1,damage);
          }
            me->receive_damage("ap",slv/10+random(10));
            me->receive_damage("mp",flv/10+random(5));
         return 1;
        }
        if(!me->skill_active( "godsword",(: call_other, __FILE__, "delay", me ,6:), 10)) return notify_fail("�A�����۰ʧ@�٨S�����C\n");
        me->map_skill("sword", "godsword");
        me->reset_action();
        message_vision("\n"HIW" $N���|��W��"+weapon->name()+", �}�l�I�i�y���Z�C�Z�z�C\n"NOR,me);
        me->receive_damage("ap",6); //luky
        me->start_busy(1);
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
        return 1;
}
void firesword(object me,object target,int damage)
{
     int slv,flv,armor,shield,level;
     object weapon;                
     me=this_player();

     if(!target) return;
     if(!me) return ;
     if(!me->is_fighting()) return;
     if( environment(me) != environment(target) ) return;

     weapon=me->query_temp("weapon");
     slv=me->query_skill("sword");
     flv=me->query_spell("god-fire");
     armor=target->query_armor();
     shield=target->query_shield();

     message_vision("$N�@��" +HIR+ "�y" +NOR+ "���_���D" +HIR+ "�z" +NOR+ "�A�⤤" +weapon->name()+NOR+ "�A����$n�ܤߡA�C�y�ɥX�L�Ƥ��K�I�I\n",me,target);

     if( random(me->query_skill("godsword"))+random(flv) > random(99) )
     {
       damage=(slv*2/3)+(flv*2/3);
       damage -= (random(armor)+shield);
       if(damage<50) damage=random(50)+30;
       message_vision(HIR"$n�����L$N�r�P����աA�Q�P�K���]�S�F�I�I"NOR,me,target);
       //�W�[�����ˮ`���v�T
       damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
       target->receive_damage("hp",damage,me);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       if(wizardp(me) && me->query("env/debug")) tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
       COMBAT_D->report_status(target);         //���target���A
        me->start_busy(1);
     }
     else {
        message_vision(HIW"  �u��$N�W�W�i�i�a�V�@�Ǻu�F�}�ӡC\n"NOR,target);
        me->start_busy(1);
     }

}
void delay(object me,int cost)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");
        if(!weapon)
        {
                me->map_skill("sword");
                me->reset_action();
                return;
        }
        if(weapon->query("skill_type")!="sword")
        {
                me->map_skill("sword");
                me->reset_action();
                return;
        }
        if(me->query_skill_mapped("sword")!="godsword")
        {
         return;
        }
    if(me->query("ap")<7)
        {
                me->map_skill("sword");
                me->reset_action();
                message_vision("\n"HIW"$N����O�����L�k�~��ϥί��Z�C�Z, �u�n��Τ@��C�ۡC\n"NOR,me);
                return ;
        }
    if( me->is_fighting() ) me->receive_damage("ap",6); //luky
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
        me->skill_active( "godsword",(: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
