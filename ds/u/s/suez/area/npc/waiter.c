inherit NPC;
inherit SELLMAN;
void create()
{
       set_name("���p�G",({"waiter"}));
       set("long","���p�G�A�A�ȥ͡A�]�󪺡A�H�K�A���s�A\n"
                       "�ϥ��L�N�O���ԧA�j�ݪ��C\n");
       set("gender","�k��");
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
     "���p�G���������D:�u��P�ȴ̰Z�O�A�������a��I�H�v\n"
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
               say("���p�G���D�G�w����{�A�o��" + RANK_D->query_respect(ob)
                                + "�M�гo�䧤�I\n");
               break;
           case 1:
               say( "���p�G�۹D�R�@��" + RANK_D->query_respect(ob)
                                + "�M�ӣ��I�W���W���I\n");
               break;
           case 2:
               say("���p�G���D�G�o��" + RANK_D->query_respect(ob)
                                + "�M���Ч��A�ݷ|��p�H�N�ӡC\n");
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
     command("say ��P�ȴ̰Z�O�A�������a��I�I");
  this_object()->kill_ob(this_player());
}
