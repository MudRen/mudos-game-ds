inherit ROOM;
void create()
{
        set("short","古木上");
        set("long",@LONG
你來到了分枝的末端，這裡看來已經沒什麼路了，此地也比旁邊的分枝
高了不少，往上可以看到遼闊的天空，往下則可以清楚的眺望樹下的古木林
，而你也注意到旁邊有著一棵巨大的古木，而且高聳無比，似乎可以稱為這
裡的樹王也不為過。
LONG
        );
        set("exits", ([
  "south" : __DIR__"stn6",
]));
        set("no_clean_up", 0);
        set("light",0);
        set("item_desc", ([
            "古木林" : "很多的古木層層交雜，形成了頗壯觀的古木林，古木林隱約有一個小空地？\n",
            "空地" : "古木林中的一個空地，看來頗為突兀，離此地有段距離，可能要想辦法通過(jump_to)。\n",            
            "天空" : "很廣闊的一片天空，雖然周圍有古木遮掩，但是這裡的視野卻很清晰。\n",
            "巨大古木" : "一棵十分巨大的古木，感覺就是古木中的王，可以跳上去看看？(jump_to)\n",            
         ]));   
        setup();
}


void init()
{
 add_action("do_jump","jump_to");
}

int do_jump(string arg)
{
  object me,ob = this_object();
  string msg;
  int rets;
  me=this_player();
  if(!arg ) return notify_fail("你要跳到哪裡 ?\n");
  if(me->is_busy() || me->is_fighting() )  return notify_fail("你正在忙\n");
  if(arg=="空地" || arg=="巨大古木")
  {
   msg="$N奮力往空中一躍而起";
   if(me->query_skill("force",1)<60) msg+="，但是內力不夠後繼而掉了下去。\n";
   else if(me->query_skill("force",1) < 80 ) msg+="，$N全心催運內功\，可是氣脈吐盡而無力掉了下去。\n";
   else if(me->query_skill("force",1) < 100 ) msg+="，$N將內功\一口氣提至丹田，卻還是無法成功\躍上。\n";
   else if(me->query_skill("force",1) == 100 ) msg+="，$N將內功\運至頂峰，可惜僅差幾呎而滑落林下。\n"; 
   message_vision(msg,me);
   rets = me->query_skill("force",1)/20;
   me->receive_wound("left_leg",60/rets);
   me->receive_wound("right_leg",60/rets);
   me->receive_wound("left_arm",60/rets);
   me->receive_wound("right_arm",60/rets);
   me->receive_wound("head",60/rets);
   me->receive_wound("body",60/rets);             
   me->receive_damage("hp",me->query("hp")*1/(rets+1));
   me->start_busy(1);
   me->move(__DIR__"t18.c");
   tell_room(environment(me), "砰的一聲，"+me->name()+"從古木掉了下來，看來受傷不淺！\n", ({ me }));
  }
  else if(arg=="bird")
  {
   if(!ob->query("can_jump_bird")) return notify_fail("你要跳到哪裡 ?\n");
   msg="$N運起輕功\往飛鳥而去";
   if(me->query_skill("dodge",1)<60) msg+="，但是輕功\造詣不夠而掉了下去。\n";
   else if(me->query_skill("force",1) < 70 ) msg+="，$N躍至飛鳥上，可是輕功\不夠借力，而力盡落下。\n";
   else msg+="，$N跳至飛鳥上借力而上半空，空地就在下方不遠處。\n";
   message_vision(msg,me);
   if(me->query_skill("force",1) >= 70)
   {
        me->move(__DIR__"stsky");
        me->start_busy(4);
        tell_room(environment(me), "人影一閃，"+me->name()+"從下方緩緩升起，輕功\出神入化！\n", ({ me }));
   } 
   else{
        me->receive_wound("left_leg",10+random(15));
        me->receive_wound("right_leg",10+random(15));
        me->receive_wound("left_arm",10+random(15));
        me->receive_wound("right_arm",10+random(15));
        me->receive_wound("head",10+random(15));
        me->receive_wound("body",10+random(15));             
        me->receive_damage("hp",me->query("hp")*1/3);
        me->start_busy(1);
        me->move(__DIR__"t18.c");
        tell_room(environment(me), "砰的一聲，"+me->name()+"從古木掉了下來，看來受傷不淺！\n", ({ me }));       }    
  }
  else return notify_fail("你要跳到哪裡 ?\n"); 
  return 1;
}

void can_jump()
{
        set("item_desc", ([
            "天空" : "很廣闊的一片天空，天空上有一隻頗大的飛鳥，也許\可以向牠借力往空中?(jump_to)。\n",
         ]));
        set("can_jump_up",1);
        call_out("delele_jump",180);       
        return;
}


void delete_jump()
{
        set("item_desc", ([
        "天空" : "很廣闊的一片天空，雖然周圍有古木遮掩，但是這裡的視野卻很清晰。\n",            
        ]));
        delete("can_jump_up");       
        tell_room("天空上的飛鳥在盤旋了許\久之後，仰天怒嘯而去了\n");        
        return;
}
















