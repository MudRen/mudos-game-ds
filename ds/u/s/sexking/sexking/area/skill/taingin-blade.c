#include <ansi.h>
inherit SKILL;
inherit SSERVER;
string *adv_attack = ({
 HIC"$N�I�i�ѼC�e�M�y�y���z���u�q�A���_�⤤$w�@���d�����p�V$n���ߺ�,"NOR,
 HIC"$N�I�i�ѼC�e�M�y�y�ǡz���u�q�A�����e�`�A�N$w�y�ݩ��T���$n���n�`��h,"NOR,
 HIC"$N�I�i�ѼC�e�M�y�y���z���u�q�A�N$w�ߨ�ѪŧQ�Τ��l�Ϥ����_���୫�����b$n���Y,"NOR,
 HIC"$N�I�i�ѼC�e�M�y�y���z���u�q�A���_�⤤$w�b$n�����W���_�����W�j�Ӧ��O���C��,"NOR,
 HIY"$N�I�i�ѼC�e�M�y�y�áz���u�q�A�N$w�c�ê��I���b$n�������W�U,"NOR,
 HIY"$N�I�i�ѼC�e�M�y�y�ءz���u�q�A����$w�b$n�����W�R�X�c�h�����R�ۦ�,"NOR,
 HIY"$N�I�i�ѼC�e�M�y�y��z���u�q�A��M���o�g�������$n�i�}�@�s�ꪺ�j�l���,"NOR,
 HIY"$N�I�i�ѼC�e�M�y�y�e�z���u�q�A�����@�˥H���p���α��դ��t�µ�$n���������F�L�h,"NOR,
});
mapping *action = ({
([
        "action":HIB"$N�����@�ܡA��ä@��A�N$w��b�a�O�W�ĦV$n�A�K�ɨϥX�@��"HIC"�u�e���٤ѡv"NOR"\n�٦V$n",
        "damage":                20,
        "dodge" :               -10,
        "attact_type":  "bar",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(bio) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
]),
([
        "action":HIR"$N������ۤM�`�A�}�y�@�ޡA�ֳt���b��$n�����ǡA�ޤM�j�١A�@��"HIG"�u���s�}�v"HIR"\n���������b$n���W",
        "damage":    15,
        "dodge" :    20,
        "attact_type":  "bar",
        "damage_type":  "�ٶ�"
]),
([
        "action":HIM"$N��w����,���l�y�ɴ�F�W�ӡA�u��$w�_�X�F�@�D�����P��,�@��"HIR"�u���K�{�v"HIM"\n�@��
         �d�����a�ۯP���U�N���n�T�N�V$n",
        "damage": 22,
        "parry" : 5,
        "attact_type":  "wit",
        "damage_type":  "�N��"
]),
([
        "action":HIC"$N��$w���W�@��A���ո��F�W�h�A��l�@�B�A\n�ϥX�@��"HIB"�u�}�Ť@�u�v"HIC"�H�M�M���G�Ƭ��@��,���@���{�q��V$n��h",
        "damage": 21,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "���"
]),
([
        "action":HIW"$N�N$w�ΤO�����J�a�O�A��M�g���j�@�A$N���ǫ_�X�F�@�D�s�����]��F$N�ĦV$n\n
        ��$N��M��q�@�n"HIR"�u��@�r�g���١�v"HIW"�A���$w�V$n���ݽ��p�h",
        "damage": 28,
        "parry" : -20,
        "attact_type":  "bar",
        "damage_type":  "�p��"
]),
([
        "action":HIC"$N�I�i�ѼC�e�M�y"HIY"�y�e�z"HIC"���u�q�A�����@�˥H���p���α��դ��t\n�µ�$n���������F�L�h"NOR,
        "damage": 22,
        "parry" : -10,
        "attact_type":  "bar",
        "damage_type":  "����"
]),
([
        "action":HIR"$N�I�i�ѼC�e�M�y"HIY"�y��z"HIR"���u�q�A��M���o�g�������$n�i�}�@�s�ꪺ�j�l���"NOR,
        "damage": 19,
        "dodge" : -9,
        "attact_type":  "bar",
        "damage_type":  "�h���M��"
]),
([
        "action":HIG"$N�I�i�ѼC�e�M�y"HIY"�y�ءz"HIG"���u�q�A����$w�b$n�����W�R�X�c�h�����R�ۦ�"NOR,
        "damage": 22,
        "dodge" : -2,
        "attact_type":  "bar",
        "damage_type":  "�h���ж�"
]),
([
        "action":HIM"$N�I�i�ѼC�e�M�y"HIY"�y�áz"HIM"���u�q�A�N$w�c�ê��I���b$n�������W�U"NOR,
        "damage": 24,
        "parry" : -2,
        "dodge" : -2,
        "attact_type":  "bar",
        "damage_type":  "�ҽk�M��"
]),
([
        "action":HIC"$N�I�i�ѼC�e�M�y"HIY"�y���z���u�q�A���_�⤤$w�b$n�����W���_�����W�j�Ӧ��O���C��"NOR,
        "damage": 15,
        "dodge" : -5,
        "attact_type":  "bar",
        "damage_type":  "�C�𹺶�"
]),
([
        "action":HIW"$N�I�i�ѼC�e�M�y"HIY"�y���z���u�q�A�N$w�ߨ�ѪŧQ�Τ��l�Ϥ����_���୫�����b$n���Y,"NOR,
        "damage": 21,
        "dodge" : -8,
        "attact_type":  "bar",
        "damage_type":  "�h���ٶ�"
]),
([
        "action":HIG"$N�I�i�ѼC�e�M�y"HIY"�y�ǡz���u�q�A�����e�`�A�N$w�y�ݩ��T���$n���L���h,"NOR,
        "damage": 25,
        "dodge" : -15,
        "attact_type":  "bar",
        "damage_type":  "���`���"
]),
([
        "action":HIR"$N�I�i�ѼC�e�M�y"HIY"�y���z���u�q�A���_�⤤$w�@���d�����p�V$n���ߺ�,"NOR,
        "damage": 23,
        "dodge" : -10,
        "parry" : -5,
        "attact_type":  "bar",
        "damage_type":  "���`�p��"
]),
});
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
 int a,c,i,j,damage,th,sd,b,d,e,da;
 string msg,aa;
 object weapon,ccc;
 mapping type;
 weapon=me->query_temp("weapon");
 da = me->query_damage();
 th = me->query_skill("taingin-blade");
 sd = me->query_skill("blade");
 if(arg=="off" )
 {
  if( me->query_skill_mapped("blade")!="taingin-blade")
  return notify_fail(HIG"�A�èS���b�I�i"HIC"�ѼC�e�M�y�C\n"NOR);
  me->map_skill("blade");
  me->reset_action();
  message_vision(HIM"$N�N�M�V�Ǥ@�ϡA�����F"HIC"�u�ѼC�e�M�y�v"NOR"���C��C\n"NOR);
  return 1;
 }
 return notify_fail(HIC"�ѼC�e�M�y"NOR"�D�ݦ��M�~��I�i�C\n"NOR);
 if(me->query_skill("blade")<60)
 return notify_fail(HIG"�A��M���{���٤����A�I�i�ѼC�e�M�y���ܷ|�����J�]�C\n"NOR);
 if(me->query("ap")<30 )
 return notify_fail(HIR",�A�{�b���O�����A�L�k�I�i"HIC"�ѼC�e�M�y"NOR"�C\n"NOR);
 if(me->query("hp")<50 ) 
 return notify_fail(HIR"�A���F���ˡA�p�G�j�j�I�i"HIC"�ѼC�e�M�y"NOR"�O�|�R�娭�`���C\n"NOR);
 if(!objectp(ccc=present("blade",me) ) )
 return notify_fail(HIC"�ѼC�e�M�y"NOR"�D�ݦ��M�~��I�i�C\n"NOR);

if(me->query_skill_mapped("blade")=="taingin-blade")
{
if( !target ) target = offensive_target(me);
if(!target)   return notify_fail(HIC"�u"HIC"�ѼC�e�M�y"NOR"�v�����ۦ�:�Q������(overlord-chop) ���q-�j�a�Y����(land-burst)�C\n"NOR);
}
if( arg == "land-burst" )
  {
  if(!me->can_fight(target)) return me->can_fight(target);
  if( !me->is_fighting(target)) me->kill_ob(target);
  if( !target->is_fighting(me)) target->kill_ob(me);
  if( me->is_busy() ) return notify_fail("�A�٨S���ɶ��X�ۡI\n");
  if (me->query_skill("taingin-blade") < 70)
  return notify_fail("�A��ثe�����ٵL�k��|��"HIC"�ѼC�e�M�y"NOR"���̲׶��q�C\n");
  c = target->query_armor();
  if(th > random(100) && sd > 60 && me->query("ap")>50 )
  {
   b = th/10;
   b = (b/2) + (random(b)/2) + 1;
   if(b>8) b=8;
   if(b<1) b=1;
   for( e=0;e<b;e++)
   {
    if(e<1) message_vision(HIY"$N���W�����ǳƨϥX"HIC"�ѼC�e�M�y"NOR"�̲׶��q-"HIR"�i�j�a�Y���١j"HIY"...."NOR"\n\n"NOR,me,target);
    d = random(sizeof(adv_attack));
    msg = adv_attack[d];
    damage = th + sd + da;
    damage =  (damage/3) + ((da*3)/2);
    damage -= (c/2) + (random(c)/2);
    if(damage<50) damage=30+random(20);
    if(damage>100) damage=100+random(90);
    if(random(me->query_dex()*2+th/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0 )
    {
     msg = adv_attack[d];
     message_vision(msg, me, target);
     me->improve_skill("taingin-blade",random(3));
     damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
     target->receive_damage("hp",damage,me);
     COMBAT_D->report_status(target);
     target->start_busy(2);
    }
    }
   if(!me->is_fighting(target)) me->kill_ob(target);
   if(!target->is_fighting(me)) target->kill_ob(me);     
   me->receive_damage("ap",8*b);
   me->improve_skill("blade",1);
   return 1;
  }
void ccc(object me,object target,int damage)
{
       string msg;
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return ;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
       if(!me->is_fighting(target)) me->kill_ob(target);
       msg +=HIG"\n$N�ɤW�@��"HIR"�i�j�a�Y���j"HIG"�@�D���j�L�񪺼C��W�N��$n�������F�W�h"NOR"�A\n";
       msg +=HIR"\n�u��$n�����˲��ֲ֡A��ݦp���A�ˤf�J���A�A��g�Q�A���G�ӭt�w�w"NOR"�A\n";
       msg +=HIC"\n�����p�����R�S�Q�D���ۦ�,�{���Ҧ��H�����T�򰩮��M,�����NŸ\n"NOR;
       message_vision(msg, me, target);
       target->receive_damage("hp",damage,me);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
       tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
       tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       COMBAT_D->report_status(target);
}
    

   if( arg == "overlord-chop" ) 
  {
   if( !me->is_fighting(target)) me->kill_ob(target);
   if( !target->is_fighting(me)) target->kill_ob(me);
   if (me->query_skill("taingin-blade") < 50)
   return notify_fail("�A��ثe�����ٵL�k��|��"HIC"�ѼC�e�M�y"NOR"����q�C\n");
   if( me->is_busy() ) return notify_fail("�A�٨S���ɶ��X�ۡI\n");
   message_vision(HIM"$N��q�@�n"HIC"�i��q�j"NOR"��"HIY"�i/�Q��"HIM"���"NOR"�١j"NOR"��Ѱʦa�A���������A�Ⲵ�o�����A�V$n��!\n"NOR,me,target);
   damage = (th/2) + (sd/5) + (da/2);
   damage = (random(damage)/2) + damage/2;
   damage -= (random(c)/2);
   if( damage < 5 ) damage = random(10);
   if( random(me->query_dex()*2+sd/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0)
   {
    msg = HIC"$n���D�Q�D�C��Ϥj�a�H��,�զp�}��,�ޤs�ˮ��G�V�F$n"NOR;
    msg +=HIR"$n�{�����εw�O���F�o�۶��q�A�K�ɳQ�A�}�F�@�D�`�i�������ˤf,�A��g�Q!!"NOR;
    message_vision(msg, me, target);
    me->improve_skill("taingin-blade",target->query("level")/5);
        // �W�[�����ˮ`���v�T
    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    me->start_busy(3);
    target->start_busy(2);
   }
   else
   {
    msg = HIC"$n�ݬ�F�o�ۡA�N�R���׶}�F�o�ۤѼC�e�M�y����q�C\n";
    message_vision(msg, me, target);
    target->improve_skill("dodge",1);
    target->start_busy(1);
    me->start_busy(2);
   }
   me->receive_damage("ap",40);
   me->start_busy(1);
   if(!me->is_fighting(target)) me->kill_ob(target);
   if(!target->is_fighting(me)) target->kill_ob(me);
   me->improve_skill("taingin-blade",1+random(me->query_int()/4));
   me->improve_skill("blade",1+random(me->query_int()/4));
   return 1;
 }
 }
 if (!me->is_fighting()) 
 return notify_fail("�A�w�g�b�I�i�u�ѼC�e�M�y�v�F�C\n");
 me->map_skill("blade","taingin-blade");
 me->reset_action();
 message_vision("\n"HIC"$N���_�⤤"+weapon->query("name")+"�A�ϥX"HIC"�ѼC�e�M�y"NOR"�C\n"NOR,me);
 me->start_busy(2);
 me->receive_damage("ap",20);
 return 1;
 }
void delay(object me,int cost)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");
        if(!weapon)
        {
        me->map_skill("blade");
        me->reset_action();
        return;
        }
        if(weapon->query("skill_type")!="blade")
        {
                me->map_skill("blade");
                me->reset_action();
                return;
        }
    if(me->query_skill_mapped("blade")!="taingin-blade")
        {
         return;
        }
    if(me->query("ap")<30)
        {
                me->map_skill("blade");
                me->reset_action();
                tell_object(me,HIR"�H�A�����O�w�L�k�A�~��ϥΤѼC�e�M�y�C\n"NOR);
                return ;
        }
        if(me->query("hp")<50)
        {
                me->map_skill("blade");
                me->reset_action();
                tell_object(me,HIR"�A�R�F�f�A��A�w�L�k�~��I�i"HIC"�ѼC�e�M�y"NOR"�C\n"NOR);
                return ;
        }
  if( me->is_fighting() ) me->receive_damage("ap",20);
  me->skill_active( "taingin-blade",(: call_other, __FILE__, "delay", me ,cost:), 10);
    }
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me) { return 1; }
int improve_limite(object ob)
{
        int a;
        a=ob->query_int();
        a=40+a;
        return a; 
}

