#include <ansi.h>;
inherit __DIR__"room";
void create()
{
        set("short", "情城池走道");
        set("long", @LONG
這裡，情城池的一條走廊，在它左右兩邊分別站有兩位守衛，陣陣的
殺氣從他們身上散發出來，真不愧是傳說中的武林禁地，忽然，你定眼一
看，愕然發現原來連這裡的守衛都是女的，和附近的殺氣相互映襯下，令
你感到一股神秘感•
LONG
        );
   set("no_recall",1);
        set("exits", ([ 
 "north" : __DIR__"room2",
  ]));
        set("objects", ([
 __DIR__"npc/guard" : 4,
]));
        set("light",1);
        setup();
}
void init()
{
  write(HIG"〈想離開請打out，謝謝合作。〉\n"NOR);
	add_action("do_exit", ({ "out"}) ); // "go"
 add_action("do_flee","flee");
}
int do_exit(string dir,object me)
{
 me = this_player();
//        if( dir == "out" ) 
	{
// if(!me->query_temp("kill_love") > 0)
   if(!me->query_temp("kill_love") )
   {
  message_vision(HIW+me->query("name")+"很有威嚴的大喝一聲：閃開！我要出城！\n"NOR,me);
  me->move("/open/world1/wilfred/sand/room26");   message_vision(HIG+me->query("name")+"緩緩的從情城池中出來了！\n"NOR,me);  
 return 1;
   }
 else
   {
 return notify_fail(HIW"〈臨陣脫逃(flee)？你現在還不行離開這裡。〉\n"NOR);
   }
	}
}
int do_flee(object me)
{
   int sk;
   object npc1,npc2,file1,file2;
        file1=load_object(__DIR__"room8");
        file2=load_object(__DIR__"room9");
me = this_player();
 if(me->query_temp("kill_love") > 0)
   {
  sk = me->query_skill("combat") - 1;
    if(objectp(npc1 = present("killer",file1)))
    {
        destruct(npc1);
    }
    if(objectp(npc2 = present("killer",file2)))
    {
        destruct(npc2);
    }
message("world:world1:vision",
HIM"\n\n《情城大捷》：\n\t"HIW+me->name()+HIM"不敵情城池的眾位女俠，已經跪地投降了，請各位英雄好漢大聲的嘲笑吧！\n\n\n"NOR,users() );

message_vision(HIW+me->query("name")+"跪地求饒，很沒骨氣的說：各位女俠，請放我出城吧！\n"NOR,me); 
  me->add("combat_exp",-500);  me->set_skill("combat",sk);
  me->add("exp",-2000);
  me->delete_temp("kill_love");
  message_vision(HIW"$N因為挑戰失敗，所以戰鬥技能下降一級, 經驗值下降2000, 戰熟下降500\n"NOR,me);
  me->move("/open/world1/wilfred/sand/room26");   message_vision(HIG+me->query("name")+"被一腳踢出情城池了！\n"NOR,me);  
  return 1;
   }
 else
   {
 return notify_fail(HIW"〈離開請打out, 謝謝。〉\n"NOR);
   }
}

