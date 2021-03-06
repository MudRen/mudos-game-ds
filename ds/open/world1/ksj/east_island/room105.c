#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","山腰");
  set("long",@LONG
來到這裡溫度漸漸降低，濕氣也變重了，濕濕冷冷地感覺很不舒
服，山壁上竟有一塊區域結成一片冰壁，敲碎也許有什麼(break)。
LONG);
  set("exits",([ 
      "south":__DIR__"room107",
      "northwest":__DIR__"room104",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/four-head-snake":1,
     ]) );
  setup();
}            

void init()
{
  add_action("break_wall","break");
}

int break_wall(string str)
{
  if(this_object()->query_temp("opened") != 0) return 0;
        
  if(str=="冰壁")
  {
    object me;
    me=this_player();
    if(me->query_str()<40 )
    {
      message_vision(HIR"\n$N一拳擊向冰壁，--叩-- 一聲響，冰壁絲豪無損。\n"NOR,me);
      return 1;
    }
    message_vision(
      HIW"\n$N一拳擊向冰壁，--乓-- 一聲響，冰壁碎裂露出一個洞口。\n"NOR,me);
    set("long", @LONG
來到這裡溫度漸漸降低，濕氣也變重了，濕濕冷冷地感覺很不舒
服，山壁上有一個山洞，源源不斷透出寒氣。
LONG
    );

    set("exits",([ 
        "south":__DIR__"room107",
        "northwest":__DIR__"room104",
        "enter":__DIR__"room106",
       ]));
       
    set_temp("opened",1);
    return 1;
  }
}

void reset()
{
  set("long", @LONG
來到這裡溫度漸漸降低，濕氣也變重了，濕濕冷冷地感覺很不舒
服，山壁上竟有一塊區域結成一片冰壁，敲碎也許有什麼(break)。
LONG
  );
  set("exits",([ 
      "south":__DIR__"room107",
      "northwest":__DIR__"room104",
     ]));
  delete_temp("opened");
  ::reset();
}
