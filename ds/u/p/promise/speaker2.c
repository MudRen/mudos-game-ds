// 神話世界﹒西游記﹒版本４．５０
/* <SecCrypt CPL V3R05> */

// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIR"七域大聲公"NOR, ({"ds speaker"}));
        set("gender", "男性" );
        set("age", 13);
        set("title", HIC"大聲派掌門人"NOR);
        set("nickname", HIG"他媽的吵死人了的人"NOR);
       set("long", "代表Promise發言一切他想說的!!\n");
       set("no_kill",1);
       set("no_fight",1);
       setup();
       remove_call_out("msg");
        call_out("msg",60);
}

void msg()
{
       message("world:world1:vision","【"HIY"七域大聲公"HIW"公告"NOR"】："NOR"老玩家多多幫助新來玩家，別讓他們處於無人求助的境界！！\n"NOR,users());
      
       remove_call_out("msg");
       call_out("msg",600);

}


