#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIM"娃娃"HIW"小"HIR"紅"HIW"帽"NOR,({"doll lady","christmas","lady"}));
set("gender","女性");
set("race","人類");
set("title",HIR"娃娃美少女"NOR);
  set("long",
"要拿測試娃娃請打(want)!!\n",
);
       set("age", 14);
       set("combat_exp", 0);
       set("attitude", "friendly");

setup();
}
void init()
{
add_action("do_want", "want");
}
int do_want(string arg)
{

       object me,dolls,doll;
       me = this_player();
       dolls=new(__DIR__"test_doll");
       if(objectp(doll = present("test doll", me) ))
       return notify_fail(HIY"真是貪心的人，我討厭你>.<~\n"NOR);
      else  
{
message_vision(HIM"聖誕"HIW"小紅帽"NOR"給"+me->query("name")+"一隻"HIG"測試娃娃"HIR""NOR"，並且幫"+me->query("name")+"打打氣加加油！！\n"NOR,me);
dolls->move(me);
 }
       return 1;
}

