inherit NPC;

void create()
{
  set_name("少尉", ({"acting sublieutenant","sublieutenant"}));
  set("long",@long
一個活潑的小女孩，正在路旁玩遊戲。
long);      
  set("gender", "女性" );
  set("age",12);
  set("level",3);
  set("race","human");
  set("title",HIC"海軍"NOR);
  set("chat_chance", 5);
  set("chat_msg", ({
      "米子將一顆酸漿放在嘴巴，一邊走一邊吹著玩。\n",
      "米子拿著小樹枝到處跑來跑去。\n",
      "米子說道：咦？我的貝殼項鏈呢？人家辛苦收集貝殼做的說，掉哪邊去了。\n",
      "米子低著頭搜尋四周，好像在找尋什麼。\n",
       (: command,"go south" :),
       (: command,"go north" :),
     }));
  setup();
  add_money("coin",10+random(10));
}

int accept_object(object who,object ob)
{
  object obj,page;
  obj=this_object();

  if(ob->query("id") == "seashell necklace")
  {
    if(obj->is_busy() || obj->is_fighting())
      {
        command("whisper "+who->query("id")+" 我沒空，別來煩我。\n");
        return 0;
      }
    message_vision("$N拿給米子一串 "+ob->query("name")+"。\n",who);
    command("jump");
    message_vision("米子說道：謝謝你，你找回了我的項鏈，我有一張藏寶圖喔，給你。\n",who);
    obj->start_busy(3);
    destruct(ob);
    page=new_ob(__DIR__"eq/neck-design-page");
    page->move(obj);
    command("give page to "+ this_player()->query("id") );
    return 1;
  }
  return 0;
}