/*
 Sorsin_Force V2.0             DATE:2006/04/07      
                                       
 �`�@�� one two three final �|��
 one -> �Sԣ�Ϊ��o��, ���ӽmskill�Ӥw 
 two -> �R���v���C���ۦ�, �@���R��, �C��N��ĤH���͵L�i�Q�����¤O
 three -> ��������ĤH���ۦ�, ���I��penuma-sword���i������
 final -> �s���ۦ�, �̰��W����25�U, �ˮ`�O�� bar ����                        
 
 ���ӧޯ�w��ĤH���ɶ��M�ۨ� tec ����, ���F final �ˮ`�O�ҩM bio^2 ������ 

 Edit By Whoami@DS 
      P.S. �S���P�� watermoon , godfire , manto ���H���ѩۥܱԭz.. 
*/  
 
   



//�i�n�͡j�����N(Watermoon)�R�@�ɶ��A�P���餺��妳�p�U���b��,�k�h���@,�@�f�A��N�o��q�f���äF�X��

//�u��$n���Y�@�K�A�C���}���O�̻٧�V����n��
//���\: $n�������ΡA�f�Q�A��
//����: $n�����I�ޡA���F�C��y«

//�S���o�X�@�I�n���Asorsin�C�𶶵۸g�ߴ��G�����Aooxx�����@Ÿ�A�������u�������Q�G���@�áA�i�ۼL�A���@�f�S�@�f���R���A��
//�������u�������Q�G���@�áA���M�����ۤv���ި�A�����W�U��«�_�ӡAooxx�i�f�R�X�@�f�A��A�y�������ܱo�G�աC


//#include <ansi.h>
#define SKILL_NAME "���P���q"
//inherit SKILL;
#include <ansi.h>
#include <weapon.h>

inherit SSERVER; 
inherit SWORD;

void stop_delay(object me);

string *sor_str= ({
"$N������i�A��M�b$n���ǹ�$n�X�F�@��"HIC"�u"HIG"��"HIC"�v\n"NOR,
"$N���C��e�C���A���_��C�P�A�h�h�]��$n�A�X����C�@���A�@��"HIC"�u"HIB"�\\"HIC"�v\n"NOR,
"$N�}�C�@���A���O��i�C���A�ϥX"HIC"�u"HIR"��"HIC"�v"NOR"�r�Z�A�C�۬������檽���i\n",
"$N�f�������D�y�I�G�����U�l�A�A�s�����C�V�z�A�⤤���C��M�D�_�g�A�ϤF"HIC"�u"YEL"�U"HIC"�v\n"NOR,
"$N�B����u�A��W���C��M���@�T�A����J�ɡA��$n�ϥX�@��"HIC"�u"HIW"�N"HIC"�v\n"NOR,
});

void create()
{
set_name("�������C",({"yin-yang longsword","sword","longsword"})); 
set("long","�o�O�@��ѿW�u�ѤH�ҥ��y�X�Ӫ��̨γǧ@�A���O�{�b�C���o��o\n"
           "�t�H�L���E\n");
set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("limit_str",30); 
        set("limit_int",30);
        set("limit_dex",50); 
        set("limit_level",45);
        set("value",10000);
        set("material","blacksteel");
        }
        init_sword(45);
        setup(); 
}

void init()
{
     add_action("do_exert","nexert");
}

int do_exert(string arg, object me, object target)
{
  string msg="";
  int damage,sk,c,te,i,x,y,delay_time,busy_time; 
  object weapon,*inv;

  me=this_player();
  inv = all_inventory(environment(me));
  
  if(!me) return 0;
  if(!me->is_fighting()) return notify_fail(SKILL_NAME+"�O�@�ؾ԰��ޯ�!\n");
  if( me->is_busy()) return notify_fail("�A�{�b�S�šI\n");
  if( !target ) target = offensive_target(me);
  if( !target ) return notify_fail("�A�n��֨ϥX"+SKILL_NAME+"?\n");    
  if( me->query_temp("nan") )
    return notify_fail("�A�u�ɶ�������ϥ�"+SKILL_NAME+"�I\n");     
  if((int)me->query("mp") < 100 || (int)me->query("ap") < 100)
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
  if(me->query_dex() < 60) 
    return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�������ӱ��C\n"); 
  if(me->query_Merits("tec") < 1)
    return notify_fail("�ϥ�"+SKILL_NAME+"�A���(TEC)���൥��s�C\n"); 

  sk=me->query_skill("sorsin_force"); 
  te=me->query_Merits("tec");
  c=target->query_armor();
  weapon=me->query_temp("weapon");
  
  me->receive_damage("mp",(random(sk)/2)+10);
  me->receive_damage("ap",(random(sk)/2+sk/2)+10);   
  me->add_temp("nan",1);
  
  
  msg += "\n"HIW"$N";
  if( me->query("evil") ){
      msg += HIW+BLK"���������F�@�U"HIW;
      } else {
      msg += HIW"�L�L�����F�@�U";
      } 
  msg += "�A�⤤��"+weapon->query("name")+"���M�i�}�F�@��"HIM"�m�i"HIW"�몺�A���A�p���l��Q�ѻ\\�a�a�n�V$n�C\n"NOR;     

  switch ( arg ){
         case "one":
              if(me->query_skill("sorsin_force") < 1)
                return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
              if( random(me->query("dex")*4) > random(target->query_skill("dodge")*2) || target->is_busy() ){

                damage = me->query_damage()-random(c);
                damage = damage * (random(3)+1);                                      
                if( damage < 0 ) damage = 0;
                
                busy_time = random(1); //npc delay���^�X�� 
                delay_time = 2+random(2);   //�ۤv delay ���^�X�� 
              
                msg += "\n"HIM""+target->name()+"�ĤO�����I���{�k�סA�w�O���U�F�ƹD�C��I\n"NOR;  

                message_vision(msg,me,target);

                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                  tell_object(me,HIY"("+damage+")\n"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                  tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

                target->receive_damage("hp",damage,me); 
                COMBAT_D->report_status(target); 
 
                target->start_busy(busy_time); 
                me->start_busy(delay_time);
                  
                call_out("stop_delay",20/te,me); 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(2);
                call_out("stop_delay",40/te,me);    // 40 / tec ���� 5�� ��X�U�@��    
              } 
                       
         break;
         case "two":  
              if(me->query_skill("sorsin_force") < 60) // �令60 by whoami 
                return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
              if( random(me->query("dex")*5) > random(target->query_skill("dodge")*3) || target->is_busy() ){
                  damage = me->query_damage()-random(c);
                  if( damage < 0 ) damage = 0;
                
                busy_time = random(te/4); //npc delay���^�X�� 
                delay_time = random(sk/20)+1;   //�ۤv delay ���^�X�� 
                
                msg += "\n$N����s�C�A���D��šA�C��ۼC�y���g�ӥX�I\n"NOR;  
                msg += "\n\t�������@�D"HIW"�N�檺�C��"NOR"�e�g�ӥX�A�H�O�H�Q�ު��t�׵w�ͥͪ����g$n�I�I\n"NOR; 


                if( random(me->query_bio())+(sk/50) > random(target->query_bio()) ){                
                   msg += "\n�u���C������A�׵L�i�סC�������C����J$n�餺�A$n�G�n�s�z�I\n"; 
                   tell_object(target ,CYN"\t(�b�A���餺���G�h�F�@�Ѥ�í�w���𮧡C)\n");
//                   target->apply_condition("sorsin_force", 
//                   target->query_condition("sorsin_force")+random((me->query_skill("sorsin_force")/20)-1));
                   damage = damage*2;
                   } else {
                   msg += "�u��$N�@�ɮ��b�ˡA�߯��c�áA�C��y�ɥ��h�F�ǫסA�ȶ����L$n����C\n"; 
                   }

                message_vision(msg,me,target);
                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                  tell_object(me,HIY"("+damage+")\n"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                  tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

                target->receive_damage("hp",damage,me); 
                COMBAT_D->report_status(target); 
 
                target->start_busy(busy_time); 
                me->start_busy(delay_time);
                  
                call_out("stop_delay",60/te,me); // 60 / tec ���� 8�� ��X�U�@�� 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(2);
                call_out("stop_delay",40/te,me);    // 40 / tec ���� 5�� ��X�U�@��    
              } 
         break;
         case "three":
              if(me->query_skill("sorsin_force") < 80) // �令80 by whoami 
                return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
              if( random(me->query("dex")*6) > random(target->query_skill("dodge")*4) || target->is_busy() ){
      
                
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay���^�X�� 


                msg += "\n$N�}�l�F���u���Ӯ��ƪ����`���R�C�C�~�Ƭ���"HIC"�ѫC�⪺�{�q�A\n"NOR
                       "\n                �{�p"HIY"���餧��"NOR"�A�@����Ţ�n�F�b�����C�@�ӤH�K\n";
                msg += "\n$N���C���p"HIY"��B"NOR"�B�p"HIM"����"NOR"�B�p"HIC"���r"NOR"�B�p"HIG"�E�y"NOR"�A"HIY"�C�����"NOR"�A"HIY"�����y��"NOR"�A�N";

                for( i=0;i<sizeof(inv);i++ ){
                     if( !inv[i]->is_fighting(me) ) continue;
                     me->add_temp("sorsin_ppl_account",1);
                     inv[i]->add_temp("sorsin_target",1);
                     delay_time = i;   //�ۤv delay ���^�X�� 
                    }
                    
                for( i=0;i<sizeof(inv);i++ ){
                     if( !inv[i]->query_temp("sorsin_target") ) continue;
                     msg += ""+inv[i]->query("name")+"";
                     if( me->query_temp("sorsin_ppl_account") > 1 ){
                     msg += "�B"; 
                     me->add_temp("sorsin_ppl_account",-1);
                     }
                    }
                for( i=0;i<sizeof(inv);i++ )
                     inv[i] -> delete_temp("sorsin_target"); 

                msg += "���g���n�`�ι�Ţ�n�K�K\n"NOR;

                message_vision(msg,me,target);
                
                for( i=0;i<sizeof(inv);i++ ){ 
                     if( !inv[i]->is_fighting(me) ) continue; 

                x = random(me->query_skill("sorsin_force")/30)+te/4;
                if( x > 5 ) x = 5;         
                       
                     damage = me->query_damage()-random(c);
                     damage = damage + (me->query_bio()*me->query_bio()*(random(me->query_dex()/10)) );
                     damage = damage*x;
                     
                     if( damage < 0 ) damage = 0;
                     if( random(me->query("dex")*6) > random(inv[i]->query_skill("dodge")*4) || inv[i]->is_busy() ){
                     message_vision("\n$N���Φp�q�A�C�ۤ@�۱��ۤ@�ۻ��X�A"+inv[i]->query("name")+"�������ΡA����"+chinese_number(x)+"�C�I\n",me); 
                     if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        tell_object(me,HIY"("+damage+")\n"NOR);
                     if(inv[i]->query_temp("apply/show_damage") || inv[i]->query_temp("show_damage") )
                        tell_object(inv[i],HIR"("+damage+")"NOR+" ("+inv[i]->query("hp")+"/"+inv[i]->query("max_hp")+")");
                      inv[i]->receive_damage("hp",damage,me); 
                      COMBAT_D->report_status(inv[i]); 
                      inv[i]->start_busy(busy_time); 

                     } else {
                     message_vision("\n�����l�@�ӻ��ժ����ۡA�I�L�@��a�{�}�F�o�O��Q�C�ۡI\n",me,inv[i]);
                     }       
                }       
                me->start_busy(delay_time);
          
                me->delete_temp("sorsin_ppl_account");                      
                call_out("stop_delay",100/te,me);   // 100 / tec ���� 12�� ��X�U�@��   
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(2);
                call_out("stop_delay",40/te,me);    // 40 / tec ���� 5�� ��X�U�@��    
              } 
         break;
         case "final":
              if(me->query_skill("sorsin_force") < 99)  
                return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
              if( random(me->query("dex")*7) > random(target->query_skill("dodge")*5) || target->is_busy() ){

                x = me->query_skill("sorsin_force")/5+te/4;
                if( x > 25 ) x = 25;

                damage = me->query_damage()-random(c);
                damage = (damage*me->query_bio()*me->query_bio())/5;
//                damage = damage - (target->query_skill("force"))*(target->query("Merits/bio")/2);
                damage = damage + random(me->query_dex()/10)*x;
                if( damage < 0 ) damage = 0;
                   
                busy_time = random(te)/2; //npc delay���^�X�� 
                if( busy_time < 1 ) busy_time = 0;
                delay_time = x/te;   //�ۤv delay ���^�X�� 

                message_vision("\n\t"HIW"$N�@�ѧ@��I�N"HIB"���l"HIW"�@���ɤJ�C���A�ϥX�e���s�ޡy"HIC"���P�Ѿ�"HIW"�z\n\n"NOR,me,target);

                for(i=0;i<x;i++)
                {
                 msg=sor_str[random(sizeof(sor_str))];
                 message_vision(msg,me,target);
                }
                
                target->receive_damage("hp",damage,me); 

                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                  tell_object(me,HIY"("+damage+")\n"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                  tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

                COMBAT_D->report_status(target); 
 
                target->start_busy(busy_time); 
                me->start_busy(delay_time);
                  
                call_out("stop_delay",120/te,me);  // 120 / tec ���� 15�� ��X�U�@��   
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(2);
                call_out("stop_delay",40/te,me);    // 40 / tec ���� 5�� ��X�U�@��    
              } 
         break;
         default:
              tell_object(me,HIC"\n"+SKILL_NAME+"�ثe�� one two three final �|���\\��A�Ԩ� help sorsin_force�C\n"NOR);        
         break;
  }
  return 1;                            
}  

void stop_delay(object me)
{
 if(!me) return;
 me->delete_temp("nan");
}

int improve_limite(object ob)
{
 return 100;
}
