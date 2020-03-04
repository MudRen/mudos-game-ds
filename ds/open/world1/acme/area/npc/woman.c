#include <ansi.h>
inherit NPC;
void create()
{
        set_name("婦人",({"woman"}));
        set("level",5);
        set("race","人類");
        set("gender","女性");
        set("int",1);
        set("talk_reply","我在田邊種的花，你可別亂採呀。");
        set("age",35);
        set("long","她是一位穿得很樸素的婦人，正坐在椅上織著衣服。\n");
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
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
        switch( random(3) ) {
           case 0:
               say("婦人說道：這位" + RANK_D->query_respect(ob)
                                + "怎麼無故闖到別人家裡來呢？\n");
               break;
           case 1:
               say("婦人用奇怪的眼神瞄了你一下。\n");
               break;
           case 2:
               say("婦人說道：這位" + RANK_D->query_respect(ob)
                                + "請你出去，別亂跑到別人家裡。\n");
               break;
      }
}
