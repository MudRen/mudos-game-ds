
#include <ansi.h>
inherit NPC;
void create()

{
        set_name(HIB"邪惡的玩家ＣＨＡＲ"NOR,({"evil player char", "char" }) );
	set("long",@LONG

    這是一隻玩家角色，由於觸犯了規定而被封印於石壁之中，但是現在
他出來了﹗帶著仇恨以及憤怒回到這個世界，他發誓要ＰＫ所有的玩家，
要把這世界搞的天翻地覆﹗﹗﹗

LONG
);

        set("age",20);
        set("level",25);
        set("gender","男性");
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
      say (HIB"邪惡的玩家ＣＨＡＲ拿出一顆發著邪惡光芒的藥丸吞了下去。\n"NOR); 
      a=a-1;
      this_object()->receive_heal("hp",300);
      this_object()->receive_heal("mp",100);
      this_object()->receive_heal("ap",200);
       return 1 ;
}
