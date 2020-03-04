#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cure_all(object me,object target,int sk,int inn);
int attack_a(object me,object target,int sk,int inn);
int attack_b(object me,object target,int sk,int inn);

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

        if(sk < 20) return notify_fail("�A���u����ë�g�v�٥������J�A�|�L��O�ϥΡC\n");
        if(me->is_busy() ) return notify_fail("�A�{�b�����ۡA�S���ŧa�C\n");
        if(environment(me)->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");
        if(me->query("hp")<100 || me->query("mp")<100) return notify_fail("�A�ثe�����骬�A�L�k�ϥΡu����ë�g�v���C\n");
        
        if(me->is_fighting() )
        {

                if(!target ) target = offensive_target(me);
                if(!me->can_fight(target)) return me->can_fight(target);

                switch( random(2) ) 
                {
                  case 0:
                     message_vision(
                     "\n$N�q��"HIM"�u����ë�g�v"NOR"��"HIR"�u�����v"NOR"�Z�G\n\n"
                     +"      �u��b�B�I���W�C�A���Y�����b���D�C�v\n"
                     +"      �u�ѭ��f�ư_��ȡA�Z�e���Ұʷ��Y�C�v\n"
                     +HIC"\n�u��$N�Y�W�@�D�벴�j���A���M�X�{�T�쯫�N�A�­������A���i�@�@�I�I\n" NOR,me);
                     cost=(sk/4)+(inn/4)+random(inn/2);
                     me->start_busy(2);
                     call_out("attack_a",3,me,target,sk,inn);
                     break;
                  default:
                     message_vision(
                     "\n$N�q��"HIM"�u����ë�g�v"NOR"��"HIC"�u���͡v"NOR"�Z�G\n\n"
                     +"      �u�j�v�����A�U�����l�C�v\n"
                     +"      �u�ܫv�[���A�U�����͡C�v\n"
                     +HIC"\n$N���⥪�k�e��A�x�X�H�Ť����A�K���ť��|���A�ιγ�¶��$n�C\n"NOR,me,target);
                     cost=(sk/5)+(inn/4)+random(inn/3);
                     me->start_busy(2);
                     call_out("attack_b",2,me,target,sk,inn);
                     break;
                } //end of switch()
                me->receive_damage("mp",cost);
                me->set_temp("power_cast",1+sk/20);
         } //end of is_fighting()
        else
        {
                if(!target ) target = me;
                message_vision(
                "\n$N�q��"HIM"�u����ë�g�v"NOR"��"HIW"�u�j�D�v"NOR"�Z�G\n\n" NOR
                +"      �u�Ѫ���g�m���}�A�j���x�����E���C�v\n" 
                +"      �u�U���@�ɪg�t�ơA�a�͹��R�K����C�v\n" NOR,me);

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
 int damage,i;
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
 message_vision(HIW"$N���⵲�W�A�C�����n�A�X��"HIR"�u��b�v"NOR"�A"HIY"�u���Y�v"NOR"�A"HIC"�u�ѭ��v"HIW"�޼S�P��$n�I�I\n"NOR,me,target);
 
    for (i=0;i<=2;i++)
    {
      switch( i ) 
      {
         case 0:
   message_vision(HIR"��b��"NOR"�⤤���b�����A�Q�T�M�A��V$N�Y�B��B�ݤT�L�n�`�I�I"NOR,target);
         break;

         case 1:
   message_vision(HIY"���Y��"NOR"���R��W�G��ܻ�P�A�C�C�|�Q�E���s��$N�ݡB�y�U�n�`�۩I�I�I"NOR,target);
         break;
 
         default:
   message_vision(HIC"�ѭ���"NOR"��B��W�ﰩ�j�A�@���u�ۯ}����v�A�Q���O�D��V$N�ݤf�n�ޡI�I"NOR,target);
         break;
      }

      if(random(target->query_skill("dodge")/2+target->query_shield()*3/2 ) < random(sk)+inn )
      {
         damage = (sk/3)+inn+random(inn+sk);
         if(userp(target)) damage = damage - (damage/5);
         damage = damage - (target->query_shield()/2);

         if(damage<20) damage=20+random(inn/2); //����̧C�ˮ`
         if(damage>150) damage=100+random(50);  //����̰��ˮ`

         damage = COMBAT_D->Merits_damage(me,target,damage,"wit"); 
         target->receive_damage("hp",damage,me);
         target->start_busy(1);

      if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
      tell_object(me,HIY"("+damage+")"NOR);
      if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
      tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
      message_vision("\n",target);
      if(wizardp(me) && me->query("env/debug")) tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
      COMBAT_D->report_status(target);         //���target���A
      }
      else
      {
           switch( random(5) ) {
           case 0:
               message_vision("\n���G�O�D�Ӥp�èS���y��$n���ˮ`�C\n",me,target);
               break;
           case 1:
               message_vision("\n      ���O�Q$n�ήɰ{�L�F�C\n",me,target);
               break;
           case 2:
               message_vision("\n      ���O�Q$n���F�a���}�F�C\n",me,target);
               break;
           case 3:
               message_vision("\n      ���O�Q$n�ή��׶}�C\n",me,target);
               break;
           case 4:
               message_vision("\n      ���O$n�W�W�i�i���k�}�F�C\n",me,target);
               break;
           default:
               message_vision("\n      ���O$n�W�W�i�i���k�}�F�C\n",me,target);
               break;
           }
      }
   }
  message_vision("\n",me);
  me->improve_spell("god-benison",random(2+me->query("level")/3)+inn/10);
  if(!target->is_fighting(me)) target->kill_ob(me);
  if(!me->is_fighting(target)) me->kill_ob(target);

}

int attack_b(object me,object target,int sk,int inn)
{
 int damage,i;
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
 
 if(target->query("mp")<10) i += 1;
 if(target->query("ap")<10) i += 2;
 
 if(random(target->query_skill("dodge")/2+target->query_shield()*3/2 ) < random(sk)+inn )
 {
     damage = ((sk+inn)*3)/5;
     if(userp(me)) damage = damage + (damage/4) - random(damage/5);
     damage = damage - (target->query_shield()/2);
     if(damage<6) damage=6+random(sk/3);
     damage = COMBAT_D->Merits_damage(me,target,damage,"wit");

   switch( i ) {
     case 1:  //�o��ܼĤHmp�S���F�A�G�l�L��ap
     message_vision(HIC"�H�Ŧ�����"NOR"�ĤJ$n�餺�A$n��ı���l�@���d���A�K�������q$n���X�A�Q$N�l���F�C\n"NOR,me,target);
            target->receive_damage("ap",damage,me);
            me->receive_heal("ap",damage/2);
     break;
     case 2:  //�o��ܼĤHap�S���F�A�G�l�L��mp
     message_vision(HIC"�H�Ŧ�����"NOR"�ĤJ$n�餺�A$n�y�ɺ믫�鱫�A�K�������q$n���X�A�Q$N�l���F�C\n"NOR,me,target);
            target->receive_damage("mp",damage,me);
            me->receive_heal("mp",damage/2);
     break;
     case 3:  //�o��ܼĤHap�Mmp���S���F�A�G�l�L��hp
     message_vision(HIC"�H�Ŧ�����"NOR"�ĤJ$n�餺�A$n�R�F�@�f�A��A�K�������q$n���X�A�Q$N�l���F�C\n"NOR,me,target);
            target->receive_damage("hp",damage,me);
            me->receive_heal("hp",damage/2);
     break;
     default: //�o��ܼĤHhp,ap,mp���٫ܦh�A�l�L��mp
     message_vision(HIC"�H�Ŧ�����"NOR"�ĤJ$n�餺�A$n�y�ɺ믫�鱫�A�K�������q$n���X�A�Q$N�l���F�C\n"NOR,me,target);
            target->receive_damage("mp",damage,me);
            me->receive_heal("mp",damage/2);
     break;
   }
      if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
      tell_object(me,HIY"("+damage+")"NOR);
      if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
      tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
      message_vision("\n",target);
      if(wizardp(me) && me->query("env/debug")) tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
      COMBAT_D->report_status(target);         //���target���A
      target->start_busy(2);
 }
 else
 {
   message_vision(HIC"�H�Ŧ�����"HIG"�ĦV$n�A���O$n�W�W�i�i�A����k�ҡA�k�X�F�ť�����¶�C\n\n"NOR,me,target);
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
