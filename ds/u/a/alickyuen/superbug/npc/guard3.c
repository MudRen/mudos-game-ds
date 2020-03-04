inherit NPC;

void create()
{
	set_name("警察", ({ "policeman" }) );
	set("long", "一個警察，正在追捕兇徒中。\n");
	set("race","人類");
set("age",50);
	set("level", 40);
                set_skill("gun", 70);
                set_skill("combat", 75);
set_skill("dodge",50);
set_skill("parry",50);
    set("chat_chance",10);
        set("chat_msg",({
//     (: random_move :),
 //               (:command("wield gun"):),
                         (:command,"reload clip":),}));
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("shoot"):),
                (:command("reload clip"):),
         }) );
                set("talk_reply","你能幫我一點小忙(help)嗎？\n");
                set("inquiry/help","我在追捕兇徒中，你願意幫我嗎？\n");
	setup();
 carry_object(__DIR__"wp/clip2.c");
carry_object(__DIR__"wp/gun2.c")->wield();
carry_object(__DIR__"eq/suit.c")->wear();
}
void init()
{       

        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_arrest","arrest");
add_action("do_nod","nod");
}

int do_arrest(string arg)
{
        object me,obj, obj2;
obj2=this_object();
        me=this_player();
if(!me->query_temp("find_killer")) return 0;
{
        if( !arg ) return notify_fail("你想逮捕誰？\n");
   if(me->is_busy() ) return notify_fail("你正忙著。\n");
        if(!objectp(obj = present(arg, environment(me)))) return notify_fail("這裡沒有這種東西。\n");
        if( !obj->is_character() || obj->is_corpse() ) return 0;
if (arg!="killer") return notify_fail("這個不是警察想逮捕的人。\n");
if (arg="killer") 
        {
command("snort killer");
command("say 我們先打他到重傷吧。");
//message_vision("$N對著$n喝道﹕「老怪物﹗今日不是你死就是我活﹗」",me);
me->kill_ob(obj);
obj2->kill_ob(obj);
        }
}
               return 1;
}

int do_nod(string arg)
{
      object me;
      me=this_player();
if(me->query_temp("find_killer")) return 0;
{
       command("say 那我們就出發去找吧(arrest)。\n");
command("follow "+me->query("id"));
       me->set_temp("find_killer",1);
}
}
void greeting()
{
object me;
me=this_player();
          if(!me->query_temp("killed_killer") && !me->query_temp("find_killer")  || !query_temp("killed_killer") && !me->query_temp("find_killer") ) return 0;
 {
command("say 多謝你的幫助。");
command("thank "+me->query("id"));
command("say 這裡有一些報酬是給你的。");
message_vision("警察傳送了１０００個單位的電子幣去$N的戶口中。\n",me);
command("follow none");
me->delete_temp("killed_killer");
me->delete_temp("find_killer");
me->receive_money(1000);
}
}
