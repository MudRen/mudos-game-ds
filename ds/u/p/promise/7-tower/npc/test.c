#include <ansi.h>
inherit ITEM;

string *all_oppmobs = ({
__DIR__"evil7"});
void create()
        {
         set_weight(5);
         set_name(HIW"測試捲軸"NOR,({"test book","book"}));
         set("value", 1);
         set("long", "作者不詳，書皮上似乎有些灰塵，不知是否可擦拭(clean)一下？\n");
         set("unit", "本");
         setup();
}

void init()
{
        add_action("do_clean","clean");
}

int do_clean(string arg)
{
  object me = this_player();
  object ob,env;

        if(! env = environment(me)) return 0;
        if( !env->query("outdoors") )
                return notify_fail(HIW"突然有股力量讓你無從下手。\n"NOR);
        if(!arg||arg!="book") return notify_fail("指令錯誤，請再輸入一次!!\n");
        switch (random(2) ){ 
                case 0:
       message_vision("$N擦拭了書上的灰塵，但毫無變化！！\n", me);
                       me->start_busy(2); 
                       destruct(this_object());
                      break;
               case 1:
          ob= new(all_oppmobs[random(sizeof(all_oppmobs))]); 
          message("world:world1:vision",
        HIY"\n\t\t遙遠的天邊突然金光一閃，似乎有些不平靜。\n\n"NOR
        ,users() );
          message_vision(HIG"$N"HIW"擦拭了書上的灰塵後，藏匿在書中裡的"NOR"$n"HIW"藉此機會竄逃而出！！\n"NOR, me, ob);
          ob->move(environment(me));
          break;          }
          destruct(this_object());
          return 1; 
}

