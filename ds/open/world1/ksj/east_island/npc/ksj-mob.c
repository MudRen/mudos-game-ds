inherit NPC;

void create()
{
  set_name("樵老的隨從", ({ "ksj's follower","follower"}));
  set("long",@long
一個年輕的樵夫，負責分擔樵老的工作。
long);      
  set("gender", "男性" );
  set("age",19);
  set("level",10);
  set("race","human");
  set("chat_chance", 10);
  set("chat_msg", ({
      "樵老的隨從說道：東方島已開放測試，請大家多去逛逛。\n",
      "樵老的隨從說道：向無沙鎮的水手購買天翔珠就能到島上了。\n",
      "樵老的隨從說道：新手請在村莊內打 mob 較安全。\n",
     }));
  setup();
  add_money("coin",10+random(10));
}
