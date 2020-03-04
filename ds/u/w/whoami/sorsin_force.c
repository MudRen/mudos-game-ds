/*****************************************************/
/* Sorsin_Force V2.0             DATE:2006.4.03      */
/* EDITOR:Whoami                                     */ 
/* �s�W two �N��ĤH��J�C��                         */ 
/*****************************************************/

//�i�n�͡j�����N(Watermoon)�R�@�ɶ��A�P���餺��妳�p�U���b��,�k�h���@,�@�f�A��N�o��q�f���äF�X��

#include <ansi.h>
#define SKILL_NAME "���P���q"
inherit SKILL;
inherit SSERVER; 

string *sor_str= ({
"$N������i�A��M�b$n���ǹ�$n�X�F�@��"HIC"�u"HIG"��"HIC"�v\n"NOR,
"$N���C��e�C���A���_��C�P�A�h�h�]��$n�A�X����C�@���A�@��"HIC"�u"HIB"�\\"HIC"�v\n"NOR,
"$N�}�C�@���A���O��i�C���A�ϥX"HIC"�u"HIR"��"HIC"�v"NOR"�r�Z�A�C�۬������檽���i\n",
"$N�f�������D�y�I�G�����U�l�A�A�s�����C�V�z�A�⤤���C��M�D�_�g�A�ϤF"HIC"�u"YEL"�U"HIC"�v\n"NOR,
"$N�B����u�A��W���C��M���@�T�A����J�ɡA��$n�ϥX�@��"HIC"�u"HIW"�N"HIC"�v\n"NOR,
});

int exert(object me, object target,string arg)
{
  string msg="";
  int damage,sk,c,te,i,x,delay_time,busy_time,wp; 
  object weapon,*inv;

  me=this_player();
  te=me->query_Merits("tec");
  c=target->query_armor();
  me->receive_damage("mp",random(sk));
  me->receive_damage("ap",random(sk)+sk);   
weapon=me->query_temp("weapon");
  me->add_temp("nan",1); 
  inv = all_inventory(environment(me));
  
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
  if(me->query_Merits("tec") <1)
    return notify_fail("�ϥ�"+SKILL_NAME+"�A���(TEC)���൥��s�C\n"); 
  sk=me->query_skill("sorsin_force"); 
  
  msg += "\n"HIW"$N�V�e�r�M��F�@�j�B�A�����`���b�w�g�a���A"+weapon->query("name")+"�����a���V�e�褣���B���ߪ�$n�A�C���M��p�ѲW�u���A�y�����m�C\n"NOR;

  switch ( arg ){
         case "one":
              if(me->query_skill("sorsin_force") < 1)
                return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
              if( random(me->query("dex")*4) > random(target->query_skill("dodge")*2) || target->is_busy() ){
                damage = me->query_damage()-random(c);
                damage = damage * (random(3)+1);                                      
                if( damage < 0 ) damage = 0;
                
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay���^�X�� 
                delay_time = 20/(me->query_skill("sorsin_force")/20);   //�ۤv delay ���^�X�� 
              
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
                me->start_busy(1);
                call_out("stop_delay",40/te,me);    // 40 / tec ���� 4�� ��X�U�@��    
              } 
                       
         break;
         case "two":
              if(me->query_skill("sorsin_force") < 50) // �令50 by whoami 
                return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
              if( random(me->query("dex")*5) > random(target->query_skill("dodge")*3) || target->is_busy() ){
                  damage = me->query_damage()-random(c);
                  if( damage < 0 ) damage = 0;
                
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay���^�X�� 
                delay_time = 20/(me->query_skill("sorsin_force")/20);   //�ۤv delay ���^�X�� 
                
                msg += "\n"HIM"$N����s�C�A���D��šA�C��ۼC�y���g�ӥX�I\n"NOR;  
                msg += "\n�������@�D�N�檺�C��e�g�ӥX�A�H�O�H�Q�ު��t�׵w�ͥͪ����g$n�I�I\n"NOR; 


                if( random(me->query("Merits/bio"))+sk/50 > random(target->query("Meris/bio")) ){                
                   msg += "\n�u���C������A�׵L�i�סA�������C����J$n�餺�A$n�G�n�s�z�I\n"; 
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
                call_out("stop_delay",40/te,me); 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(1);
                call_out("stop_delay",40/te,me);    // 40 / tec ���� 4�� ��X�U�@��    
              } 
         break;
         case "three":
              if(me->query_skill("sorsin_force") < 80) // �令80 by whoami 
                return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
              if( random(me->query("dex")*6) > random(target->query_skill("dodge")*4) || target->is_busy() ){

                damage = me->query_damage()-random(c);
                damage = damage + (me->query_dex()/2)*random(x);
                if( damage < 0 ) damage = 0;
                
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay���^�X�� 
                delay_time = 20/(me->query_skill("sorsin_force")/20);   //�ۤv delay ���^�X�� 

                msg += "\n$N�}�l�F���u���Ӯ��ƪ����`���R�C�C�~�Ƭ����ѫC�⪺�{�q�A�{�p���骺���~�A�@����Ţ�n�F�b�����C�@�ӤH�K\n";
                msg += "\n$N���C���p��B�B�p����B�p���r�B�p�E�y�A�C������A�����y�ߡA�N";
                
                for( i=0;i<sizeof(inv);i++ ){
                     if( !inv[i]->is_fighting(me) ) continue;
                     msg += ""+inv[i]->query("name")+"";
                     if( i > 1 ) msg+= "�B";
                     }
                msg += "���g���n�`�ι�Ţ�n�K�K\n"NOR;

                message_vision(msg,me,target);

                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                  tell_object(me,HIY"("+damage+")\n"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                  tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

                target->receive_damage("hp",damage,me); 
                COMBAT_D->report_status(target); 
 
                target->start_busy(busy_time); 
                me->start_busy(delay_time);
                
            //    me->receive_damage("ap",x*40,me);
            //    me->receive_damage("mp",x*15,me);    
                  
                call_out("stop_delay",80/te,me); 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(1);
                call_out("stop_delay",40/te,me);    // 40 / tec ���� 4�� ��X�U�@��    
              } 
         break;
         case "final":
              if(me->query_skill("sorsin_force") < 99) // �令80 by whoami 
                return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");  
              if( random(me->query("dex")*7) > random(target->query_skill("dodge")*5) || target->is_busy() ){
                damage = me->query_damage()*5-random(c);
                damage = damage + me->query_dex()*random(10);
                damage = damage - (target->query_skill("force"))*(target->query("Merits/bio")/4);
                if( damage < 0 ) damage = 0;
            
                x = me->query_skill("sorsin_force")/5+te/4;
                if( x > 25 ) x = 25;
                    
                busy_time = random(me->query_skill("sorsin_force")/30); //npc delay���^�X�� 
                delay_time = 20/(me->query_skill("sorsin_force")/20);   //�ۤv delay ���^�X�� 

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
                  
                call_out("stop_delay",80/te,me); 
                me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));   
              } else {
                msg += "\n"HIW""+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR; 
                message_vision(msg,me,target); 
                me->start_busy(1);
                call_out("stop_delay",40/te,me);    // 40 / tec ���� 4�� ��X�U�@��    
              } 
         break;
         default:
         break;
  }                            
}  
