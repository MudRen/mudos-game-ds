#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIC"渡船內"NOR);
   set("long","
可以藉此離開此地，通往傳說中的古堡。
");
    
  set("exits", ([ /* sizeof() == 1 */
      "out" : __DIR__"snow6",
     ]));
  set("no_clean_up", 0);
  set("light",1);
  set("no_kill",1);
  set("no_fight",1);
  set("no_recall",1);
  setup();

}

void init()
{
        add_action("douse","push");
}


int douse(string arg)
{
        int t;
        object me,room,*inv;
        me=this_player();
        if(arg != "石輪") return 0;
        if(!this_object()->query_temp("moving")) 
        {
                inv = all_inventory(this_object());
                message_vision(HIW "$N推了一下石輪，船漸漸的動起來了！！\n\n"NOR,me);
                me->start_busy(3);
                call_out("domessage",3,3);
                this_object()->set_temp("moving",1);
                this_object()->delete("exits");
                room = load_object(__DIR__"snow6");
                room->delete("exits/enter");
                room->set("long",@ROOM_LONG
在這雪地裡居然還有未結冰的小溪，這一點就證明了此地生態環
境的怪異。渡船已離開了此地，前往了古堡。
ROOM_LONG
);
                tell_room(room,HIG"船緩緩的出發了！！\n"NOR);
                return 1;
        }else
        {
                tell_object(me,HIR"船已經消失的不見人影！！\n"NOR);
                return 1;
        }

}
int domessage(int b)
{
  object *inv,room;
  object me = this_player();
  int i;
  if(b==3) tell_room(this_object(),HIW+me->query("name")+HIW"推了下在旁的石輪，漸漸的離岸了！！\n\n" NOR);
  else if(b==2) tell_room(this_object(), HIW "此行旅途上冰天雪地，毫無生態變化！！\n\n" NOR );
  else if(b==1) tell_room(this_object(), HIW "船速度漸漸的緩和下來，想必快要到達目的地了。\n\n" NOR );
  else  {

                inv = all_inventory(this_object());
                tell_room(this_object(),HIR "船緩緩的行駛靠岸了！！\n\n" NOR );
                this_object()->delete_temp("moving");
                room = load_object(__DIR__"o1");
                tell_room(room,HIY"你看見船漸漸的靠岸！！\n"NOR);
                for(i=0;i<sizeof(inv);i++)
                {
                        if(living(inv[i])) inv[i]->move(__DIR__"o1");
                }
                tell_room(room,HIC"一下船後，船居然消失了？！\n"NOR);
                this_object()->set("exits", ([
                        "out" : __DIR__"snow6",
                ]));
                room = load_object(__DIR__"snow6");
                tell_room(room,HIY"一瞬間，船又緩緩的靠岸了！！\n"NOR);
                room->set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"snow5",
  "enter" : __DIR__"boat",
]));
                room->set("long",@ROOM_LONG2
在這雪地裡居然還有未結冰的小溪，這一點就證明了此地生態環
境的怪異。旁邊有一小船，似乎可以利用此船，離開本地。
ROOM_LONG2
);
                return 1;
                
        }
        b--;
        call_out("domessage",3,b);
}


