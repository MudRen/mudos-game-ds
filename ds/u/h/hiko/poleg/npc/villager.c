inherit NPC;

void create()
{
  set("title","資深漁夫");
  set_name("村民", ({ "villager" }) );
  set("gender", "男性" );
  set("long",@long
泊浪村的漁夫們，平時都是在外捕魚，不知因為何事群聚討論。
long
);      
  set("age",37+random(5));
  set("level",10);
  set("con",14);
  set("race","human");
  set("exp",3000);  set("chat_chance", 10);
  set("chat_msg", ({
(: command("say 你好..歡迎來到我們泊浪村。") :),
(: command("say 最近那些傢伙出現越來越頻繁，咱們怎麼去捕魚呀。") :),
(: command("say 我們頭目真是一個傳奇人物，聽說是去了一個藏有隱世高手的地方學藝回來。") :),
(: command("say 唉！村子的未來就放在阿泊他們那些小鬼了，可是每次都如此衝動，真令人擔心。") :),
(: command("say 聽說那些傢伙是從異國來的，也不知道為什麼偏偏挑上我們村子，真是多禍。") :),
(: command("say 那群傢伙真是猖狂無比，除了不讓我們捕魚外，還到處劫色，真是可惡至極。") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
(: command("say 可惡呀..敢欺負我們捕魚郎，莫非你是那些傢伙的同黨?") :),
}) );
  setup();
  add_money("coin",500);
}

