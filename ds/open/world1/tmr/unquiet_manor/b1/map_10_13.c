#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "血池");
        set("long", @LONG
淌在你面前是座泊泊不停的血池，血池像是煮沸的滾水，不停地翻動
血浪，在血水之中盡是人骨遺骸，還有好幾具半爛的屍首在血池中載浮載
沉。你注意到血池中立著一座石柱，上頭擺著金玉盆，不知道有何作用。
LONG
        );
  set("item_desc",([
      "金玉盆" : "金玉盆可以用來祭屍仙，要是不怕死的話，可以試試擺\放(arrange)一些生肉在裡面。\n",
     ]));
        set("exits",([
        "south" : __DIR__"map_11_13",
        "north" : __DIR__"map_9_13",
        "west" : __DIR__"map_10_12",
        "east" : __DIR__"map_10_14",
        ]));
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
  add_action("do_throw","arrange");
}


void call_troll() {
        object mobp;
        if(query_temp("is_grill")) return;

        if( query_temp("meats") < 3 + random(3) ) {
             message_vision( "血池翻動的更厲害了...\n" NOR, this_player());
             return;
        }

        // 帶兩隻兵
        mobp = new("/open/world1/tmr/unquiet_manor/npc/demon.c"); 
        mobp->delete("chat_msg");
        mobp->move(environment(this_player()));  
        mobp = new("/open/world1/tmr/unquiet_manor/npc/demon.c"); 
        mobp->delete("chat_msg");
        mobp->move(environment(this_player()));  
        mobp = new("/open/world1/tmr/unquiet_manor/npc/corpse_king.c"); 
        mobp->move(environment(this_player()));  
        message_vision( HIG "忽然，從血池深處冒出三道鬼影，血腥之氣登時充滿整座墓室！！\n" NOR, this_player(), mobp);
        set_temp("is_grill",1);
        call_out("stop_throwed", 180 + random(60));
}

int do_throw(string arg)
{ 
  object me=this_player(), meat; 
        if(me->is_busy())
                return notify_fail("你正忙著，沒有空做事。\n");
  if( query_temp("is_grill") )
                return notify_fail("你發現金玉盆裡面還有些碎肉。\n");
  if(!arg || arg != "meat")
                return notify_fail("你想要擺\什麼東西？\n");
  if(!objectp(meat=present("_BLOOD_MEAT_",me) ) )
    return notify_fail("這個東西無法這樣使用。\n");

  message_vision( HIM "$N小心翼翼將$n"HIM"擺\放在金玉盆內。\n" NOR, me, meat);
  destruct(meat);
  add_temp("meats",1);
  me->start_busy(2);  
  call_out("call_troll", 2);

  return 1;
}

void stop_throwed()
{
  if(!this_object()) return; 
        delete_temp("is_grill");
        delete_temp("meats");
}



