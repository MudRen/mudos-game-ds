inherit NPC;

void create()
{
  set_name("老人", ({ "old person","person" }) );
  set("gender", "男性" );
  set("long",@long
黃沙鎮的居民，他己白髮蒼蒼，步伐蹣跚了。
long
);      
  set("age",80);
  set("level",5);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"老人揉了揉肩膀，打了一個呵欠。\n",
(: command("say 唉，近來盜匪越來越猖獗，這可怎麼辦才好。") :),
(: command("say 聽說天機那老頭要回去拜見他師父的靈位，但是到現在還未動身哩。") :),
(: command("say 磐龍山不知是怎生的光景，真想去看一看。") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("say 別看我老了，當年我可是.... 唉唉，老人家說話時別動手成不成？") :),
}) );
  setup();
  add_money("coin",100);
}
