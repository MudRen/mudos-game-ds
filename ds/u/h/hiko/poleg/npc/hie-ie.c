#include <ansi.h> 
inherit NPC;
inherit SSERVER;
void do_heal();  // add -Jangshow
void create()
{
      set_name(HIB"����" NOR,({"hie-ie","hie"}) );
      set("title",HIG "���|�Y��" NOR);   
      set("long",@LONG
�u�����v�O�{�����|�Y�ءA�ͩʥ��H�A�֦~�ɴ��g�]�t�ڷ|�o�첧
�H�ۧU�A�ϱo�ߨ�@�����j�\�ҡA���W�����˳\����A�紿�ѥ[�L
�j�C�F�A�b�����O�n��̰����H���A�ثe�ѩ����m�\�A�]������
�ѻP�������ơA�Ӿڻ��ѥL�i�o���������@�����@�ǨơA�ϱo�\�h
���򤧤H���_�e�ӻP�L�߰ݡA�M�u�Q�L�v�E�ɬO�P�m�C 
LONG    
        );
        set("race", "human");    
        set("unit","��");
        set("age",38);
        set("level",50); 
        set("max_ap",6000); 
        set("max_mp",6000);
        set("Merits/bar",9);
        set("Merits/tec",5);        set("max_hp",15000);
        set("exp",70000+random(10000));
        set("limbs", ({ "�Y��", "����","�ݳ�","�ⳡ","�}��" }) );      
        add("addition_armor",200);
        add("addition_damage",100);  
        set("chat_chance", 50);
        set("chat_msg", ({
  (: command("exert jurlong-awi") :), 
  (: do_heal :),
  (: do_heal :),
}));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
  (: command("exert jurlong-awi") :),  
  (: do_heal :),  
  (: command("exert jurlong-awi") :),  
  (: do_heal :),   
  (: do_heal :),
})); 
      map_skill("hammer","jurlong-awi");
      set_skill("jurlong-awi",100);     
      set_skill("hammer",100);   
      set_skill("dodge",100);  
      set_skill("peep",100);   
      set_temp("apply/hit",15);
      setup(); 
      carry_object(__DIR__"wp/jur-hie-hammer")->wield();} 

int special_attack(object me,object target,int hitchance) //�S��..�ۨ��S�Z���ɥX
{ 
    int z,t,s; 
    object wp;
    target = offensive_target(me);  // �ĤH
    me = this_object();
    wp=me->query_temp("weapon");
    if(!me || !target) return 0;
    if(wp) return 0;
    if(random(6)) return 0;
    z=target->query_dex();
    t=target->query_con();
    s=random(120);
   if( s > (t+z)/2 ) 
    {
      message_vision(HIY"\n$N"+HIR"��q�@�n�A�B�_"+HIY"�����߳Z--�}���Z\n"
         +HIW"�V$n���X"+HIY"�X"+HIC"��"+HIY"�X"+HIC"��"+HIY"�X"+HIC"��"+HIY"�X"+HIW"�I\n"
         +HIW"$n�Q�j�j����l��"+HIR"���������I\n"
         +HIC"���ѱo���r�M�h�F�\\�h�B\n\n"+NOR,me,target);   
      target->receive_damage("hp",300+random(200),target);
      target->start_busy(1);
      COMBAT_D->report_status(target); 
      return 1; 
    }
    else
    {
      if( s+20 > (t+z)/2 )
       {
        message_vision(HIY"\n$N"+HIW"�����򴤡A"+HIY"�����߳Z--�}���Z"+NOR"���X\n"
                    +HIG"�y�ɮ�l�g�W"+HIC"���O�@��"+HIW"��V$n..\n"  
                    +HIW"$n���ɷP��M�I�I���O������l�d��\n"
                    +HIC"�ϱo���쪺�ˮ`��C\n\n"+NOR,me,target);
        target->receive_damage("hp",200+random(me->query_str()+50),target);
        target->start_busy(1);
        COMBAT_D->report_status(target);
        return 1;
       }
      else    
       {
        message_vision(HIY"\n$N"+HIW"�W�դw�[�A"+HIY"�����߳Z--�}���Z"+NOR"���X\n"
                    +HIG"�@���n����H�A���O�ǳƧ�V$n..\n"  
                    +HIC"$n�o���w�o�{�A���P�{�L\n\n"+NOR,me,target);
        target->receive_damage("hp",100+random(me->query_str()),target);
        COMBAT_D->report_status(target);
        return 1;
       }
    }
}
void do_heal() //�^��
{
        object ob;
        ob=this_object();
        if(!ob) return 0;
        if( (ob->query("hp") + 1500 < ob->query("max_hp") ) && ob->query("mp") > 20 ) 
        {
         message_vision(HIG"$N�ϥΤF"+HIY"�����߳Z--�j���Z"+HIC"�ϱo��O�j�W\n"+NOR,ob); 
         ob->add("hp",250+random(200));
         ob->receive_damage("mp",20);
         ob->start_busy(1);  //start_busy -Jangshow
         return; // Jangshow
        }
          return 0;
}

void die()
{
        object ob;
        ob = this_player(1);
        if( !ob = query_temp("last_damage_from") )           
        if( !ob ) 
        {
                ::die();
                return;
        }
        if(ob->query_temp("killhieea")==2)
          { ob->set_temp("solo_hieea",1); }         
        message("world:world1:vision",
        "\n"HIY"�i"HIC"�u���_�T"HIY"�j"HIG"���|�Y��"HIW"�u"HIC"�� ��"   
        HIW"�v�Q"+ob->name(1)+"����H��O���ˤF�C\n\n"NOR,users());
        ob->add("popularity",5); 
        message_vision("$N"HIC"�S�X�岧�������J"+HIW"�G�M���s�N�N���H�X . . 
        �ڦ��ӵL�ѧr\n"+NOR,this_object());  // ob -by Jangshow        
        ::die();
        return;
}










