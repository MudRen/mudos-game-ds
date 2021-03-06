inherit NPC;

void create()
{
  set_name("海女",({"woman fisher","fisher"}) );
  set("long",@LONG
專門潛入海中，搜集像龍蝦、鮑魚、生蠔等漁產的島國女性，她
們可以不用任何裝備就能長時間潛在海中，耐力著實驚人。
LONG);
  set("race","人類");
  set("gender", "女性");  
  set("age",25);
  set("level",17);
  set("attitude","friendly");
  set("chat_chance",5);
  set("chat_msg",({
      "海女將採來的生蠔放入腰間的袋子中。\n",
      "海女換了口氣後，又潛入海中。\n",
     }));
  setup();
  add_money("coin",300);
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
 
  switch( random(100) )
  {
    case  0..9:
          new(__DIR__"eq/coral-bracelet")->move(this_object());
          break;
    case  10..25:
          new(__DIR__"eq/sea-urchin")->move(this_object());
          break;
    case  50..54:
          new(__DIR__"eq/lobster-wrists")->move(this_object());
          break;
    case  90..99: new(__DIR__"eq/pearl-earring")->move(this_object());
          break;
  }
  ::die();
  return;
}
