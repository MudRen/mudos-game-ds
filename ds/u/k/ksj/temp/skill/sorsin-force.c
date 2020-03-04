/*****************************************************/
/* WIND CLASS NEW SKILL          DATE:2003.5.24      */
/* EDITOR:Jangshow               NOTE:NO WEAPON SK   */ 
/* �@�q�ɶ���,��ppl������,�A�ݭn���n�}�s�C           */
/*****************************************************/
#include <ansi.h>
#define SKILL_NAME "���P���q"
inherit SKILL;
inherit SSERVER; 
mapping *action = ({ 
([
   "action": "$N�}�C�@���A���O��i�C���A�ϥX"HIC"�u"HIR"��"HIC"�v"NOR"�r�Z�A�C�۬������檽���i",
   "damage":       100+random(99),  //�o�ӬO�ˮ`�j�ƪ��ʤ��� , ���O�ˮ`�I��
   "attack":       10,
   "attact_type":  "tec",  // �]�w�ޯ઺�������� // �ͪ�(bio) �~��(bar) �]�k(wit)���F(sou)���(tec)
   "damage_type":  "���", 
]),
([
   "action": "$N���C��e�C���A���_��C�P�A�h�h�]��$n�A�X����C�@���A�@��"HIC"�u"HIB"�\\"HIC"�v"NOR"�W�V$n��$l",
   "damage":       100+random(99),
   "dodge":        -5,
   "delay":        1,
   "attack_type":  "tec",
   "damage_type":  "���",
]),
([
   "action": "$N������i�A��M�b$n���ǹ�$n�X�F�@��"HIC"�u"HIG"��"HIC"�v"NOR,
   "damage":       100+random(99),
   "delay":        2,
   "attack_type":  "tec",
   "damage_type":  "���",
]), 
([
   "action": "$N�f�������D�y�I�G�����U�l�A�A�s�����C�V�z�A�⤤���C��M�D�_�g�A�ϤF"HIC"�u"YEL"�U"HIC"�v"NOR,
   "damage":       100+random(99),
   "delay":        2,
   "attack_type":  "tec",
   "damage_type":  "���",
]),
([
   "action": "$N�B����u�A��W���C��M���@�T�A����J�ɡA��$n��$l�ϥX�@��"HIC"�u"HIW"�N"HIC"�v"NOR,
   "damage":       100+random(99),
   "attack_type":  "tec",
   "damage_type":  "���",
]), 
([
   "action": "\n"HIM"�ĤO�����I�񨭶K�ԡA�w�O���U�F�ƹD�C��I\n"NOR, 
   "damage":       200+random(99),
   "delay":        2,
   "attack_type":  "tec",
   "damage_type":  "�ж�",
]),
});

string *sor_str= ({
"$N������i�A��M�b$n���ǹ�$n�X�F�@��"HIC"�u"HIG"��"HIC"�v"NOR,
"$N���C��e�C���A���_��C�P�A�h�h�]��$n�A�X����C�@���A�@��"HIC"�u"HIB"�\\"HIC"�v"NOR"�W�V$n��$l",
"$N�}�C�@���A���O��i�C���A�ϥX"HIC"�u"HIR"��"HIC"�v"NOR"�r�Z�A�C�۬������檽���i",
"$N�f�������D�y�I�G�����U�l�A�A�s�����C�V�z�A�⤤���C��M�D�_�g�A�ϤF"HIC"�u"YEL"�U"HIC"�v"NOR,
"$N�B����u�A��W���C��M���@�T�A����J�ɡA��$n��$l�ϥX�@��"HIC"�u"HIW"�N"HIC"�v"NOR,
"\n"HIM"�ĤO�����I�񨭶K�ԡA�w�O���U�F�ƹD�C��I\n",
});

int exert(object me, object target,string arg)
{
  string msg;
  int damage,sk,c,te,i; 
  object weapon,wp;  
  me=this_player();
  if(!me) return 0;
  if(!me->is_fighting()) return notify_fail(SKILL_NAME+"�O�@�ؾ԰��ޯ�!\n");
  if( !target ) target = offensive_target(me);
  if( !target ) return notify_fail("�A�n��֨ϥX"+SKILL_NAME+"?\n");    
  if( me->query_temp("nan") )
    return notify_fail("�A�u�ɶ�������ϥ�"+SKILL_NAME+"�I\n");     
  if((int)me->query("mp") < 50 || (int)me->query("ap") < 100)
    return notify_fail("�A�ثe�����骬�p�L�k�ϥγo��@�P���Z�\\�T\n");
  if(!weapon=me->query_temp("weapon")) return notify_fail("�ϥί��P���q�ݭn�ϥΪZ���C\n"); 
  if(weapon->query("skill_type")!="sword") 
    return notify_fail("�ϥ�"+SKILL_NAME+"�����n���C�C\n"); 
  if(me->query_skill("sword")<100) 
    return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�����Ϲꪺ�C�k��¦�C\n"); 
  if(me->query_skill("dodge")<100)
    return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�����Ϲꪺ�{����¦�C\n");
  if(me->query_skill("sorgi_sword")<100)
    return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�����Ϲꪺ�����C�k�C\n");
  if(me->query_skill("star-sword")<100)
    return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�����Ϲꪺ���P�C�q�C\n");
  if(me->query_skill("moon_force")<100)
    return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn���p���ݤ�ߪk�C\n");
  if(me->query_skill("force")<100)
    return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn���p�����\\�C\n"); 
  if(me->query_dex() <60) 
    return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�������ӱ��C\n");
  sk=me->query_skill("sorsin_force"); 
  te=me->query_Merits("tec");
  c=target->query_armor();
  message_vision("\n"HIW"$N�N���O�e�`��⤤���C�A�R�ժ�"HIC"�C��"HIW"�W�իݵo�E�E�E\n"NOR,me,target);
  me->receive_damage("mp",15+sk/5);
  me->receive_damage("ap",30+sk/3);
  if(arg != "one") return notify_fail("\n�A�n�ϥX"+SKILL_NAME+"������\\��H\n");
  if(me->query_skill("sorsin_force") >33) 
    return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
  if(me->query_dex()*2 < target->query_skill("dodge")+random(12))
  {
    msg += "\n"HIW""+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR; 
    message_vision(msg,me,target);
    me->add_temp("nan",1);
    call_out("stop_delay",180/te,me);
  }
  else
  {
    damage = me->query_damage()*2+sk*2+me->query_dex()*2-c/2;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");             
    msg += "\n"HIM"�ĤO�����I���{�k�סA�w�O���U�F�ƹD�C��I[����("+damage+")�I���ˮ`]\n"NOR; 
    message_vision(msg,me,target);
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(te/2); 
    me->start_busy(2); 
    me->add_temp("nan",1);
    call_out("stop_delay",180/te,me); 
    me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8)); 
  }

  if(arg != "two") return notify_fail("\n�A�n�ϥX"+SKILL_NAME+"������ۦ��H\n"); 
  if(me->query_skill("sorsin_force") >66) 
    return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
  if(me->query_dex()*2 < target->query_skill("dodge")+random(12))
  {
    msg += HIW"\n"+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR; 
    message_vision(msg,me,target);
    me->add_temp("nan",1);
    call_out("stop_delay",180/te,me);
  }
  else
  {
    damage = me->query_damage()*3+sk*7+me->query_dex()*4-c/3;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");    
    msg += "\n\t"HIG"�C���@�_�I\n"
    "\t\t"HIB"�y"HIC"�ݤ뤧���E�۷��e��"HIB"�z\n"
    "\t\t"HIW"�@�ѼC�𱽿��b"+target->name()+"���P��I�|���Ů�����@�T�I\n"
    "\t\t"HIC"�ѯe�P�}"HIW"�ܼC�ӥX�I�ʹD�C��E�E�Ѱ}�ɤJ�E�E\n"
    "\t\t"HIR"�A��s�z�E�E"+target->name()+"�i���E�E[("+damage+")�I���ˮ`��]\n"NOR; 
    message_vision(msg,me,target);
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(te/2); 
    me->start_busy(2); 
    me->add_temp("nan",1);
    call_out("stop_delay",240/te,me); 
    me->improve_skill("sorsin_force",2+random(me->query_dex()/8+me->query_Merits("tec")/4+sk/8));  
  } 

  if(arg != "three") return notify_fail("\n�A�n�ϥX"+SKILL_NAME+"������?\n"); 
  if(me->query_skill("sorsin_force") >99) 
    return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n"); 
  if(me->query_dex()*2 < target->query_skill("dodge")+random(12))
  {
    msg += "\n"HIW""+target->name()+"���o��H�I���F$N���ۦ��C\n"NOR; 
    message_vision(msg,me,target);
    me->add_temp("nan",1);
    call_out("stop_delay",180/te,me);
  }
  else
  {
    damage = me->query_damage()*5+sk*10+me->query_dex()*5-c/2;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");   
    msg += "\n\t"HIG"�C���@�_�I"HIR"$N�������Q������л\\�I\n"
    "\t\t"HIB"�y"HIC"�ݤ뤧���E�۷��e��"HIW"�E���E�ѡE��"HIB"�z\n"  
    "\t\t"HIW"�@�ѼC�𱽿��b"+target->name()+"���P��I�|���Ů�����@�T�I\n"
    "\t\t"HIW"���ɥX�F����"HIC"�ѯe�P�}"HIW"�I�d�D�C��I"HIR"���L�j�I\n"
    "\t\t""HIR"+target->name()+"�o�b"HIW"�ե�"HIR"�{������A�w�˦b��y���E�E[("+damage+"�I���ˮ`��)]\n"NOR; 
    message_vision(msg,me,target);
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(te/2);
    me->start_busy(2);
    me->add_temp("nan",1);
    call_out("stop_delay",360/te,me);
    me->improve_skill("sorsin_force",10+random(me->query_dex()/2+me->query_Merits("tec")*2+sk/2)); 
  }
         
  if(arg != "final") return notify_fail("\n�A�n�ϥX"+SKILL_NAME+"������?\n");
  if(me->query_skill("sorsin_force") >99)
    return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n"); 
  if(me->query_dex()*2 < target->query_skill("dodge")+random(12))
  {
    msg += "\n"HIW""+target->name()+"���o��H�I���F$N���ۦ��C\n"NOR;
    message_vision(msg,me,target);
    me->add_temp("nan",1);
    call_out("stop_delay",540/te,me); 
  }
  else
  {
    damage = me->query_damage()*10+sk*10+me->query_dex()+10-c/2;
    //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");                
    message_vision("\n"HIC"$N�@�ѧ@��I�N���l�@���ɤJ�C���A�ϥX�e���s�ޡy"HIW"���P�Ѿ�"HIC"�z\n"NOR,me,target);
    for(i=0;sizeof(sor_str);i++)
    {
      msg=sor_str[random(sizeof(sor_str))];
      message_vision(msg,me,target);
    }
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(te/2);
    me->start_busy(2);
    me->add_temp("nan",1);
    call_out("stop_delay",360/te,me);
    me->improve_skill("sorsin_force",10+random(me->query_dex()/2+me->query_Merits("tec")*2+sk/2));
  }          
  return 1;
}
                 
void stop_delay(object me)
{
  if( !me ) return;
  me->delete_temp("nan");
}

int improve_limite(object ob)
{
  return 100;
}
