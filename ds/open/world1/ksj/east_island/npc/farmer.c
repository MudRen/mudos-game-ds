inherit NPC;

void create()
{
  set_name("農夫",({"farmer"}) );
  set("long",@long
一位長像老實的農人，正在田裡工作。
long);      
  set("age",33);
  set("level",13+random(2));
  set("race","人類");
  set("attitude", "peaceful");
  set("unarmed",20);
  set("chat_chance",5);
  set("chat_msg",({
      "農夫蹲在田邊細心地整理田地。\n",
      "農夫停了下來，用脖子上的毛巾擦了擦汗。\n",
       }) );
  set_skill("unarmed",20);
  setup();                
  add_money("coin",100);
}
