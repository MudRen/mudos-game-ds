#include <ansi.h>
inherit NPC;

void create()
{
      set_name(HIB"�ܹFù" NOR,({"gua da-lou","lou"}) );
      set("title",HIC "�^��" NOR);   
      set("long",@LONG
�P�����ܪ��^���A���Q��������A���g�L���몺����A
�S�A�״_���A�]�B�o�짯�뤧�ۡA���y�@���|�@�L������
�}�A����A�P����Ӥ@���ͦ����C
LONG    
        );
        set("race", "human");    
        set("unit","��");
        set("age",80);      
        set("level",70); 
        set("max_ap",10000);
        set("max_mp",10000); 
        set("max_hp",20000);
        set("combat_exp",600000);    
        set("limbs", ({ "�Y��", "����","�ݳ�","�ⳡ","�}��" }) );      
        add("addition_armor",300);
        add("addition_damage",300);  
        set("chat_chance", 100);
        set("chat_msg", ({
  (: command("reload bolt") :), 
}));
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
  (: command("shoot") :),   
  (: command("shoot") :),   
  (: command("cast shiro-spell") :),  
  (: command("cast shiro-spell") :),  
  (: command("reload bolt") :),    
  (: command("wield bow") :), 
})); 
      set_spell("shiro-spell",100);      
      set_skill("force",100);
   setup();
      carry_object(__DIR__"obj/purple-bow")->wield();   
      carry_object(__DIR__"obj/bolt"); 
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt"); 
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt"); 
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
}

void die()
{
   object ob,obj;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
    HIG"\t\t\n�i���i�� ���T�j"+HIB " ���ܹFù��"+HIW"�P"+HIB"��"+ob->name(1)+"��"+HIC"�Ԫ����h�O�ɡI\n\n"      
    HIW"\t\t����b�̫�@�����ɭԡA"+HIB"�ܹFù"+HIW"���M"+HIR"��"+HIW"�F�E�E�E�E\n\n"+NOR,users());
        ob->add("popularity",9+random(3));  
        ob->set("guild_rank",HIB"�ܹFù"HIW"��"HIR"�ܰ��i�h"NOR);
        ::die();
        return;
}
