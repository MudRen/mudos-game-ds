inherit NPC;

void create()
{
  set_name("村民", ({ "villager" }) );
  set("gender", "男性" );
  set("long",@long
一位普通的村民，正在路旁走著。
long
);      
  set("age",20+random(20));
  set("level",7+random(3));
  set("race","human");
  set("chat_chance", 8);
  set("chat_msg", ({
     (: command("say 這位朋友你好。") :),
     (: command("say 今天天氣不錯阿。") :),
     (: command("say 有機會真想去西大陸見識見識。") :),
     (: command("say 去年裴伊川氾濫，還是造成不小的損失。") :),
     }));
  setup();
  add_money("coin",100+random(100));
}
