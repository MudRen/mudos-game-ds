#include <ansi.h>
inherit NPC;
void create()
{
        set_name(WHT"黑衣女子"NOR,({"black killer","killer"}));
        set("long" ,
"情城池的秘密殺手，看她躍出的身法，可得知她武功\也不弱。\n");
        set("nickname", MAG"斷滅七情"NOR );
        set("attitude", "friendly"); 
        set("age", 16);
        set("gender","女性");
        set("level", 22);
        set("class1","情城池");
        set("title",HIR"情城池秘密殺手"NOR);
        set_temp("apply/armor",20);
        set_skill("run_cloud",90);
        set_skill("masen_whip",60);
        map_skill("dodge","run_cloud");
        map_skill("whip","masen_whip");
        setup();
        carry_object(__DIR__"obj/whip7")->wield();
        }
void init()
{       
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
      }
}
int do_guard(string arg)
{
        if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
      command("grin");
           say(WHT"黑衣女子"NOR"喝道："HIR"要滅派？先問問我的鞭吧！\n"NOR);
        return 1;
}

