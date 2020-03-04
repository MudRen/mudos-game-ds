#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "林傑克", ({ "jack lin","lin","jack"}));
 set("long",@LONG
他就是鼎鼎大名的四海大惡人之一, 綽號吃錢不吐骨的林傑克
, 想不到如今它會跑到無砂來作走私, 不過以他視錢如命的性格
這似乎也想的通, 你看他一臉癡呆愚蠢的模樣, 實在想不到他竟
然是最會作生意的黑道人物, 除此之外, 他對部下的嚴格態度也
使的他的走私貿易成為海政司最頭痛的地方.
LONG
    );

        set("level",20);
        set("gender", "男性");
        set("race", "人類");
        set("age", 36);
   	set("attitude", "peaceful");
   	set("sell_list",([   
           __DIR__"eq/fire_gun"   :30,
           __DIR__"eq/fire_bullet"    :25, 
      ]) );
  set("chat_chance", 3 );
  set("chat_msg", ({       
(:command("grin"):),
}) );
      setup();
      add_money("dollar", 40);       
      carry_object(__DIR__"obj/manto");
      carry_object(__DIR__"eq/cloth")->wear();
      carry_object(__DIR__"eq/fur_waist")->wear();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
	if(ob->query("id") == "eagle mark")
           {
		if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了林傑克一個 "+ob->query("name")+"。\n",who);
             command("fear");
             obj->start_busy(10);
             obj->set_temp("givemark",1);
             destruct(ob);
             call_out("givemark",1,obj);
	return 1;
	   }

}

void givemark()
{
      int i;
      object me,obj,thing,thing2;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givemark");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"林傑克大吃一驚, 兩道目光忽然朝你凌烈的看去! \n"NOR);
            obj->set_temp("givemark",i+1);
            call_out("givemark",1,me);
            break;
          case 2:
            command(CYN"say 難道先遣隊那麼快就到了??."NOR);
            obj->set_temp("givemark",i+1);
            call_out("givemark",1,me);
            break;
          case 3:
            say(CYN"林傑克忽然道: 嗯...既然如此, 在下當然不留餘力相助\n"NOR);
            obj->set_temp("givemark",i+1);
            call_out("givemark",1,me);
            break;
          case 4:
            thing=new(__DIR__"eq/fire_bullet");
            thing->move(obj);
         thing=new(__DIR__"eq/fire_bullet");
         thing->move(obj);
         thing=new(__DIR__"eq/fire_bullet");
         thing->move(obj);
         thing=new(__DIR__"eq/fire_bullet");
         thing->move(obj);
         thing=new(__DIR__"eq/fire_bullet");
         thing->move(obj);
      command("give bullet to "+ me->query("id") );
    command("give bullet to "+ me->query("id") );
    command("give bullet to "+ me->query("id") );
    command("give bullet to "+ me->query("id") );
    command("give bullet to "+ me->query("id") );
          obj->set_temp("givemark",i+1);
            call_out("givemark",1,me);
            break;
          case 5:
            command("say 對了, 這個也麻煩你拿給阿瑟芬副官...");
            obj->set_temp("givemark",i+1);
            call_out("givemark",1,me);
            break;
          case 6:
            thing2=new(__DIR__"obj/letter");
            thing2->move(obj);
            command("give letter to "+ me->query("id") );
            obj->delete_temp("givemark");
            break;
          }
}
