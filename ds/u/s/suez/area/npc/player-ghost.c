
#include <ansi.h>
inherit NPC;
void create()

{
        set_name(HIB"���c�����a�Ѣ֢Ϣ�"NOR,({"evil player char", "char" }) );
	set("long",@LONG

    �o�O�@�����a����A�ѩ�Ĳ�ǤF�W�w�ӳQ�ʦL��۾������A���O�{�b
�L�X�ӤF�T�a�ۤ���H�μ���^��o�ӥ@�ɡA�L�o�}�n�ޢ٩Ҧ������a�A
�n��o�@�ɷd����½�a�СT�T�T

LONG
);

        set("age",20);
        set("level",25);
        set("gender","�k��");
        set("chat_chance", 36);
       set("chat_chance", 30);
        set("chat_msg",({ 
                  (:command("exert godsword"):),
                  (:command("exert mirage-steps"):),
                  (:command("exert bagi_fist"):),
                  (:command("exert sorgi_sword"):),
                  (:command("exert fogseven"):),
                  (:command("pk"):),
                  (:command("get all"):),
                  (:command("get all from corpse"):),
                  (:command("wield sword"):),
                  (:command("wear all"):)
}));
      set("attitude", "killer"); 
     set("evil",700);
     set_skill("godsword", 50);
     set_skill("mirage-steps", 50);
     set_skill("bagi_fist", 50);
     set_skill("horse-steps", 50);
     set_skill("sorgi_sword", 50);
     set_skill("fogseven", 50);
       set("chat_chance_combat",160);
     set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("exert mirage-steps"):),
                  (:command("exert bagi_fist"):),
                  (:command("exert sorgi_sword"):),
                  (:command("exert fogseven"):),
     }));
       setup();

        carry_object( __DIR__"eq/evil_boots")->wear();
        carry_object( __DIR__"wp/evil_sword")->wield();
        carry_object( __DIR__"eq/evil_armor")->wear();      
 
}
int a=10;
int special_attack()
{
        int hp ,max_hp;
        hp=this_object()->query("hp");
        max_hp=this_object()->query("max_hp");
        if(hp>max_hp/2)  return 0;
      if(a==0) return 0;
      say (HIB"���c�����a�Ѣ֢Ϣள�X�@���o�ۨ��c���~���ĤY�]�F�U�h�C\n"NOR); 
      a=a-1;
      this_object()->receive_heal("hp",300);
      this_object()->receive_heal("mp",100);
      this_object()->receive_heal("ap",200);
       return 1 ;
}
