inherit NPC;

void create()
{
  set_name("婦女", ({ "woman" }) );
  set("gender", "女性" );
  set("long",@long
一位正在洗衣服的婦女。
long
);      
  set("age",26);
  set("level",5);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"婦女拿起手中溼淋淋的衣服看了一下，翻個面又埋首慢慢的捶打起來。\n",
(: command("say 有時可以看到天機老人在後方竹林裡的亭子呢，不知在作些什麼。") :),
(: command("say 上次有小賊偷了人家的荷包，真是令人生氣。") :),
(: command("say 昨天好像有人來盜砍青竹，奇怪，又不是多值錢，想必是哪位有雅好的人士所為吧。") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("say 光天化日強搶民女啊∼∼我的白馬王子快來救我哪∼∼") :),
}) );
  setup();
  add_money("coin",300);
  carry_object(__DIR__"eq/eq1")->wear();
}
