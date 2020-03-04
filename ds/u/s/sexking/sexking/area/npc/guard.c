#include <ansi.h>
inherit NPC;
void create()
{
             set_name( "浪人營輪番守衛", ({ "guard","guard" }) );
             set("level",20);
             set("combat_exp",2000);
             set("long" ,"他是每天與其它浪人輪流換班守衛的武士。\n");
             set("age",35);
             set("gender","男性");
             set_skill("blade",45);
             set_skill("dodge",40);
             set_skill("parry",40);
             set_skill("combat",40);
             set("talk_reply","我在守衛不要吵我。");
             set("chat_chance",8);
             set("chat_msg", ({
  name()+"說:喂!小子你要幹嘛?。\n",
  name()+"手按著刀柄，像是隨時要出刀的樣子。\n",
  (: command("hmm") :),
  }) );
        setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
        carry_object(__DIR__"eq/rattan_leggings")->wear();
}
void init()
{
       object me;
       ::init();
   add_action("do_guard", "go");
}
int do_guard(string arg)
{
if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        {
        if ( this_player()->query_temp("nice")>=1)  
        { 
        this_player()->move("/u/s/sexking/sexking/area/map_2");
        return 1;
        } 
        if ( this_player()->query_temp("bad")>=1)
        { 
        this_player()->move("/u/s/sexking/sexking/area/map_2");
        return 1;
        } 
        else
        {
        write( name() + "將你擋了下來。\n");
        command("no");
        say("浪人營輪番守衛說道："HIR"這裡不是你該來的地方！！\n"NOR);
        return 1;
        }
}
}
