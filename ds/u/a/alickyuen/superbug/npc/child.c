#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小孩" , ({ "child" }) );
        set("level",10);
 set("race", "人類");
    set("chat_chance",10);
        set("age", 50);
        set("long","一個小孩，不知為什麼正在大哭。\n");
    set("chat_chance",10);
        set("chat_msg",({
                         (:command,"cry":),}));
        setup();
}
void init()
{       

        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
add_action("do_nod","nod");
}

int do_nod(string arg)
{
      object me;
      me=this_player();
          if(!me->query_temp("find_child")) return 0;
 {
        command("say 那你快帶我爸媽來找我，謝謝，快唷。");
command("smile");
me->delete_temp("find_child");
me->set_temp("go_child",1);
}
}
void greeting()
{
object me;
me=this_player();
          if(!me->query_temp("gived_key")) return 0;
 {
        command("cry");
command("say 你是來救我的嗎？我迷路了不懂怎回家去。");
me->delete_temp("gived_key");
me->set_temp("find_child",1);
}
}
