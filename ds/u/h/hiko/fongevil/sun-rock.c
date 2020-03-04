#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("陽岩",({"sun rock","rock"}));
        set("unit", "個");
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set("inlay_msg","上面什麼東西都沒有");        
        setup();
}

void init()
{
        add_action("do_inlay","inlay");
        add_action("do_peen","peen");
        call_out("slong",0);
}

int do_inlay(string arg)
{
        object me,obj,ob;
        ob=this_object();
        me=this_player();
        if(me->is_busy()) return notify_fail("你正忙著，沒空作其他事。\n");
        if(arg!="stone into rock" && arg!="alien-beast stone into rock" )
        {
                notify_fail("你要嵌什麼上去?\n");
                return 0;
        }
        if(ob->query("inlayed",1)) return notify_fail("上面有東西不能再嵌上去了");
        if(obj=present("alien-beast stone",me))
        {
                              
                  message_vision("$N將$n放上了陽岩。\n",me,obj);
                  destruct(obj);
                  ob->set("inlay_msg","上面有著一塊怪異的石頭可以敲擊(peen)");
                  ob->set("inlayed",1);      
                  call_out("slong",0);
                  return 1;
        }
         else
        {
                tell_object(me,"你身上沒有可以嵌上去的東西喔\n");
                return 1;
        }
}

int do_peen(string arg)
{
       object me,ob,hammer;
       ob=this_object();
       me=this_player();  
       if(me->is_busy()) return notify_fail("你正忙著，沒空作其他事。\n");
       if(arg!="stone")
       {
               notify_fail("你要敲擊什麼東西?\n");
               return 0;
       }
       if(!hammer = present("hammer",me)) return notify_fail("你需要一把槌子來敲擊。\n");
       if(!ob->query("inlayed")) 
       return notify_fail("上面什麼東西都沒有。\n");
       message_vision("$N舉起手中的槌子，使勁的朝著異獸石敲去。\n",me);
       me->start_busy(2);
       ob->set("inlayed",0);
       call_out("peening",2);
       return 1;
}

int peening()
{
  object me = this_player();
  message_vision("啪啦！異獸石裂成兩塊。\n",me);
  new(__DIR__"item/haltdragon-stone")->move(environment(me));
  new(__DIR__"item/halttiger-stone")->move(environment(me));
  return 1;
}

void slong()
{
this_object()->set("long",
"一把長年吸收陽氣的石頭，上面有一個凹槽。如果鑲嵌(inlay)什麼東西\n"
"上去看看的話，說不定會有甚麼奇妙的事情發生。                   \n"
HIC"" +query("inlay_msg")+ ""NOR"                               \n" 
);
}





