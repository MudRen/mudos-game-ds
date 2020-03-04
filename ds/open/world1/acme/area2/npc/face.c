#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "鬼面魔種", ({ "ghost face","ghost","face", "__GUARD__" }) );
        set("level",30);
           set("combat_exp",3000);
set("exp",2000);
        set("long","他是一隻全身長著大大小小的鬼頭在胸前、背後，直教人驚駭。\n");
        set("age",50);
        set("evil",60);
     set("title",CYN"鬼出神沒"NOR);
        set("gender","男性");
        set("attitude","killer");
             set_skill("unarmed",60);
        set_skill("dodge",60);
                  set_skill("parry",60);
        set("Merits/wit",2);
        setup();
}
void init()
{   
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && this_object()->visible(this_player())) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
          object me;
          me=this_player();
          if( !ob || environment(ob) != environment() ) return;
          {    
            command("hehe");
            command("pk");
            say("鬼面魔種大喝：惡賊！！去死吧！！\n");
            message_vision("鬼面魔種趁$N不注意時，偷襲暗算$N，發招猛攻。\n",me);
            message_vision("你看見鬼面魔種前胸的大鬼頭，噴射而出，往$N急衝而去。\n",me);
            message_vision(HIR "\n鬼頭往$N的腳上咬去，看來$N已受傷不輕。\n"NOR,me);
            me->receive_damage("hp",40);
           me->receive_wound("left_leg",5);
           me->receive_wound("right_leg",5);
            set("attitude","killer");
          }
}
