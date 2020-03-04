// ��s���: 1999.10.15
// ��s��: Luky
// QCer: Luky
#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cure_all(object me,object target,int sk,int inn);
int attack_a(object me,object target,int sk,int inn);
int attack_b(object me,object target,int sk,int inn);
int attack_c(object me,object target,int sk,int inn);

int cast(object me, object target)
{
        int sk,i,inn,cost;
        object *enemy;
	
	//1. �I�k��delay�n��e��(�i��call_out) 2.�`�Ndelay����H���Ŷ����ܤ�.
	//3. ghost�����O�n���ҭ���.
	//luky
	//return notify_fail("�o�ӧޯ�]�������D, �Ȱ��ϥΡC\n");
        
        sk=me->query_spell("god-benison");
        inn=me->query_int();

        if(sk < 20) tell_object(me,"�A���u����ë�g�v�٥������J�A�|�L��O�ϥΡC\n");
        if(me->is_busy() ) return notify_fail("�A�{�b�����ۡA�S���ŧa�C\n");
	if(environment(me)->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");
        if(me->query("hp")<100 || me->query("mp")<100) return notify_fail("�A�ثe�����骬�A�L�k�ϥΡu����ë�g�v���C\n");
	
        if(me->is_fighting() )
        {

		if(!target ) target = offensive_target(me);
		if(!me->can_fight(target)) return me->can_fight(target);

        	switch( random(3) ) 
        	{
        	  case 0:
                     message_vision(HIG
                     "$N�q��u����ë�g�v���u���X�v�Z�G\n\n" NOR
        	     +HIM    "      �u�s�������X�A��뽪���СC�v\n" NOR
        	     +HIM    "      �u���ϯB�_���A����Ӫ��ɡC�v\n" NOR
        	     +HIY    "\n$N�Y���W��Ƥة����E�ƹD�L�Ϊ����b��....\n" NOR
                		,me);
 		     cost=15;
 		     enemy = me->query_enemy();
                     me->start_busy(2);
                     for(i=0; i<= (sk/20) && i<sizeof(enemy); i++) call_out("attack_a",2,me,enemy[i],sk,inn);
                     break;
                  case 1:
                     message_vision(HIG
                     "$N�q��u����ë�g�v���u�����v�Z�G\n\n" NOR
                     +HIM    "      �u��b�B�I���W�C�A���Y�����b���D�C�v\n" NOR
                     +HIM    "      �u�ѭ��f�ư_��ȡA�Z�e���Ұʷ��Y�C�v\n" NOR
                     +HIC    "\n�u��$N�Y�W�@�D�벴�j���A���M�X�{�T�쯫�N�A�­������A���i�@�@�I�I\n" NOR,me);
                     cost=(sk/2)+(inn/2)+random(inn/2);
                     me->start_busy(2);
                     call_out("attack_b",3,me,target,sk,inn);
                     break;
                  default:
                     message_vision(HIG
                     "$N�q��u����ë�g�v�����u���͡v�Z�G\n\n" NOR
                     +HIM"      �u�j�v�����A�U�����l�C�v\n" NOR
                     +HIM"      �u�ܫv�[���A�U�����͡C�v\n" NOR    
                     +HIC"\n$N���⥪�k�e��A�x�X�H�Ŧ⤧���A�K���ť��|���A�ιγ�¶��$n�C\n"NOR,me,target);
                     cost=(sk/3)+(inn/2)+random(inn/3);
                     me->start_busy(2);
                     call_out("attack_c",2,me,target,sk,inn);
                     break;
                } //end of switch()
                me->receive_damage("mp",cost);
                me->set_temp("power_cast",1+sk/20);
         } //end of is_fighting()
        else
        {
        	if(!target ) target = me;
                message_vision(HIG
                "$N�q��u����ë�g�v���u�j�D�v�Z�G\n\n" NOR
                +HIM"      �u�Ѫ���g�m���}�A�j���x�����E���C�v\n" NOR
                +HIM"      �u�U���@�ɪg�t�ơA�a�͹��R�K�����C�v\n" NOR
                ,me);

                me->receive_damage("mp",15);
		me->start_busy(3);
		call_out("cure_all",3,me,target,sk,inn);
        }
        return 1;
}

int cure_all(object me,object target,int sk,int inn)
{
 if(!me) return 0;
 if(!target) target=me;
 else if(environment(me)!=environment(target)) target==me;
 if(random(inn+sk+me->query("level")) > random(20) )
 {
   message_vision(HIW"\n$N�����W�U��¶�ۤ@�}�ե��A�M�ấ�����h�C\n" NOR,target);
   target->receive_curing("all",sk/20+inn/8);
   me->improve_spell("god-benison",random(2+inn/5));
   return 1;
 }
 tell_object(me,"���G����Ʊ����S�o�͡C\n");
 tell_room(environment(me),me->query("name")+"�n�n�Y, ���檺�ĤF�@�f��C\n",({me}));
}

int attack_a(object me,object target,int sk,int inn)
{
 int damage;
 if(!me) return 0;
 if(me->query("mp")<15) return notify_fail("�A���]�O�����C\n");
 if(!target) return notify_fail("�ؼЮ����F�C\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 	  
       message_vision(HIY"$N�q��@�n�G�u�h�v�A�@�D�����b�𨳱��L���L��a��$n�g�h�I�I\n" NOR,me,target);
       if(random(target->query_skill("dodge")/2+target->query_shield() ) < random(sk+inn) )
       {
         message_vision(HIR"\n$N�{�����Τ��F�D�����b��A�uť$N�G�I�@�n�A�ݨӨ��ˤ����C\n\n"NOR,target);
	damage = (sk*2/3)+random(inn*2)+10+me->query("level");
	damage = damage - target->query_shield();
	if(damage<10) damage=10+random(inn/3);
	damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
         target->receive_damage("hp",damage,me);
         COMBAT_D->report_status(target);
       }
        else
       message_vision(HIG"\n�uť$N��I�@�n�A�ϺɦY�����O��A�n���e�����}�F�����b�𪺰l���C\n\n"NOR,target);
     
     me->improve_spell("god-benison",random(2+me->query("level")/3)+inn/10);
     if(!target->is_fighting(me)) target->kill_ob(me);
     if(!me->is_fighting(target)) me->kill_ob(target);
     return 1;
}

int attack_b(object me,object target,int sk,int inn)
{
 int damage;
 if(!me) return 0;
 if(!target) return notify_fail("�ؼЮ����F�C\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 
  message_vision(HIY "\n$N���⵲�W�A�C�����n�A�X�ϡu��b�v�A�u���Y�v�A�u�ѭ��v�޼S�P��$n�I�I\n\n"NOR,me,target);

  if(random(target->query_skill("dodge")/2+target->query_shield() )< random(sk+inn) )
  {
   message_vision( MAG"��b���⤤���b�����A�Q�T�M�A��V$N�Y�B��B�ݤT�L�n�`�I�I\n" NOR
                  +MAG"���Y�����R��W�G��ܻ�P�A�C�C�|�Q�E���s��$N�ݡB�y�U�n�`�۩I�I�I\n" NOR
                  +MAG"�ѭ�����B��W�ﰩ�j�A�@���u�ۯ}����v�A�Q���O�D��V$N�ݤf�n�ޡI�I\n" NOR
                  +HIR"\n$N�G�I�@�n�A�n�ɦ��|�q�B�g�R�Ƥf�A��A�ݨӨ��ˤ����C\n\n" NOR
                  ,target);
   damage = (sk/3)+inn+random(inn+sk);
   if(userp(target)) damage = damage - (damage/5);
   damage = damage - (target->query_shield()/2);
   if(damage<20) damage=20+random(inn/2);
   damage = COMBAT_D->Merits_damage(me,target,damage,"wit"); 
   target->receive_damage("hp",damage,me);
   COMBAT_D->report_status(target);
  }
  else
  {
   message_vision(HIG"\n$n�ϥX�����ѼơA�T�V���k�}�F�o�@���C\n\n"NOR,me,target);
  }
  me->improve_spell("god-benison",random(2+me->query("level")/3)+inn/10);
  if(!target->is_fighting(me)) target->kill_ob(me);
  if(!me->is_fighting(target)) me->kill_ob(target);
}

int attack_c(object me,object target,int sk,int inn)
{
 int damage;
 if(!me) return 0;
 if(!target) return notify_fail("�ؼЮ����F�C\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
  if(random(target->query("inn")/2+target->query_shield() )< random(sk+inn) )
  {
   message_vision( HIC"�H�Ŧ⤧���ĦV$n�餺�A�u��$n���n�b�a�W�A�C�C�a�q$n����̴��X\n" NOR
                  +HIR"����⪺�����A$N���X����A���ئR�o�A�������w�w���Q$N�l���F�C\n\n" NOR,me,target);
   damage = ((sk+inn)*3)/5;
    if(userp(me)) damage = damage + (damage/4) - random(damage/5);
   damage = damage - (target->query_shield()/2);
   if(damage<6) damage=6+random(sk/3);
   damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
   target->receive_damage("mp",damage,me);
   target->receive_damage("hp",damage/3,me);
   me->receive_heal("mp",damage);
   me->receive_heal("hp",damage/3);
  }
   else
  {
   message_vision(HIG"\n$n�W�W�i�i�A����k�ҡA�k�X�F�ť�����¶�C\n\n"NOR,me,target);
  }
  if(!target->is_fighting(me)) target->kill_ob(me);
  if(!me->is_fighting(target)) me->kill_ob(target);
  me->improve_spell("god-benison",random(2+me->query("level")/3)+inn/10);
}

int improve_limite(object ob)
{
	if(ob->query("adv_class")==1) return (ob->query_int()+30); 
        else return 90;
}