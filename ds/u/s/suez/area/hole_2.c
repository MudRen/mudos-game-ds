#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
 set("short",HIR"獸穴");
        set("long",@LONG
你一進到這裡，一股濃濃的血腥味立即撲了過來，其中還混雜著野獸
的臭味。你突然覺得胃中一陣翻滾，不禁嘔出一些胃酸。看來這個地方，
還是不要待太久比較好。
LONG
        );


         set("exits", ([
       "up":__DIR__"hole_1",
         ]));
        create_door("up","石門","down",DOOR_CLOSED);

        set("objects",([
              __DIR__"npc/golden-monkey" : 1,
          ]) );
        setup();

 }
void init()
{
        add_action("do_kick", "kick");
        add_action("do_search", "search");
}
int do_search(string arg)
{
     object me;
     me=this_player();
     if(arg!="土堆")  return 0;
      tell_object(me, HIY "土堆鬆落了一塊，你似乎看到土堆後隱約有個通道。\n\n" NOR );
      tell_object(me, HIY "你用腳踹了一下，嗯，似乎有點鬆動，再用力踢踢看好了。\n\n" NOR );
     return 1;
}
     
int do_kick(string arg)
{
         int t;
        object me;
        me=this_player();
        if(arg != "土堆") return 0;
      if(me->query_str()<10) return notify_fail("你用力踢了一腳，哎喲﹗好痛﹗。\n");
        message_vision( HIG "$N用力踢開堆積的土塊，土塊下竟然有一條密道﹗$N看到密道後就鑽了進去。\n\n" NOR ,me);
        me->start_busy(3);
        call_out("domessage",3,me,4);

        message_vision( HIG "$N走了進去之後，突然一陣搖動﹗崩落了一些土石又把洞口埋住了。\n\n" NOR ,me);
      me->move(__DIR__"hole_3");
        return 1;
}
int domessage(object me,int b)
{
 if(b==3) 
        tell_object(me, HIB "你回去的路被土石堵住了，看來只好繼續往前找路了。\n\n" NOR );
  else if(b==2) 
        tell_object(me, HIB "狹小的洞讓你不得不用爬的，濕泥土的味道讓你覺得自己像隻蚯蚓。\n\n" NOR );
  else  if(b==1)
      tell_object(me,HIB "你覺得洞突然變寬了，可以彎著腰走著。\n\n" NOR );
 else if(b==0)
        {
        tell_object(me,HIY "盡頭是一面脆弱的石牆，你轉個姿勢用力把石牆踹開﹗\n\n" NOR );
        this_object()->delete("user");
        me->move(__DIR__"secret");
       tell_room(environment(me),HIY"石牆突然崩落"+me->query("name")+HIY"從崩落的石牆後鑽了出來。\n"NOR,me);
        return 1;
        }
b--;
me->start_busy(3);
call_out("domessage",3,me,b);
}

