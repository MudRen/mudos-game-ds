inherit NPC;
void create()
{
  set_name("掃地童僕", ({ "young servant","servant" }) );
  set("gender", "男性" );
  set("long",@LONG
他是嬤嬤請來打掃院子小男孩，一臉頑皮的樣子，笑嘻嘻的。
LONG
);      
  set("age",15);
  set("level",5);
  set("race","human");
   set("chat_chance", 20);
  set("chat_msg", ({
"掃地童僕掃著地上的垃圾...嘿咻...嘿咻...。\n",
(: command("say 嬤嬤說，千萬不可以去搖(move)櫻花樹！") :),
(: command("say 搖樹的話，會把樹搖壞的唷！") :),
}));
  setup();
}



