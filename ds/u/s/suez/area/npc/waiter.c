inherit NPC;
inherit SELLMAN;
void create()
{
       set_name("店小二",({"waiter"}));
       set("long","店小二，服務生，跑堂的，隨便你怎麼叫，\n"
                       "反正他就是伺候你大爺的。\n");
       set("gender","男性");
       set("age", 21);
       set("level", 20);
       set("attitude", "peaceful");
       set("dex", 50);
       
       set("sell_list",([	
           __DIR__"obj/water"  : 25, 
        __DIR__"obj/meet"  : 25
       ]) );				     

       set("chat_chance",9);
       set("chat_msg",({(:command, "unwield dagger":),
}));

     set("chat_chance_combat",17);
     set("chat_msg_combat", ({
      (:command("snort"+this_player()->query("id")):),
     "店小二輕蔑的說道:「月嵐客棧豈是你撒野的地方！？」\n"
     }) );
    
        setup();
        add_money("coin", 200);
        carry_object( __DIR__"eq/cloth")->wear();    
        carry_object(__DIR__"wp/long_dagger.c");
        carry_object(__DIR__"eq/sky-walk_b.c") -> wear(); 
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_kill","kill");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
           case 0:
               say("店小二說道：歡迎光臨，這位" + RANK_D->query_respect(ob)
                                + "﹐請這邊坐！\n");
               break;
           case 1:
               say( "店小二喊道﹕一位" + RANK_D->query_respect(ob)
                                + "﹐來ㄟ！上茶上菜喔！\n");
               break;
           case 2:
               say("店小二說道：這位" + RANK_D->query_respect(ob)
                                + "﹐先請坐，待會兒小人就來。\n");
               break;
        }
}
int do_kill(string arg)
{
  object obj;
  obj=this_object();
  if(arg != "yen" && arg !="yen-lu-yu" && arg !="waiter" )  return 0;
  if(!this_player()) return 0;
  if(environment(this_player())!=environment(obj)) return 0;
     command("wield dagger");
     command("say 月嵐客棧豈是你撒野的地方！！");
  this_object()->kill_ob(this_player());
}
