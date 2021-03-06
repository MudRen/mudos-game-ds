#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "高空上");
  set ("long", @LONG

你藉著強大輕功踏飛鳥升上了高空，這裡視野遼闊，已經可以清楚看到
空地，你也發現到巨大古木離你似乎不是很遠，看來也許可以試試看往其中
一個方向跳躍過去看看。

LONG
);
  set("no_recall",1);
  set("no_goto",1);
  set("no_horse_member",1);  set("item_desc", ([
        "空地" : "古木林中的一個空地，看來頗為突兀，離此地距離不是很遠，可以順勢降落過去看看?(fall_to)。\n",            
        "巨大古木" : "一棵巨大的古木，感覺就是古木中的王，看來就在身旁，可以順勢降落過去？(fall_to)\n",            
         ]));   
  setup();
}
  

void init()
{
  object me;
  me = this_player(); 
  remove_call_out("fall_down");
  call_out("fall_down",20,me);   
  call_out("write_note",1);
}

void write_note()
{ 
  write(HIC"你來到了高空中，只見週圍雲霧瀰漫，煞是奇特，你可以考慮順勢往其他方向降落(fall_to)。\n"NOR);
  add_action("do_fall","fall_to");
}


void fall_down(object ppl)
{
  if(!ppl || environment(ppl) != this_object() ) return;
  write(HIM"你忽然一口氣提不上來，呼吸一陣渾濁，身體一沉落了下去\n"NOR);
  ppl->move(__DIR__"t18");
  ppl->start_busy(2);
  tell_room(environment(ppl), "天空一個黑影越變越大，周圍一陣飛塵竄動，"+ppl->name()+"從空中掉了下來！\n", ({ ppl }));
}


int do_fall(string arg)
{
  object me;
  me = this_player();
  if(!arg && (arg!="空地" || arg !="巨大古木") ) return notify_fail("沒有這個地方可以降落喔\n");
  write("你身體微微前傾，腳上順勢前推，便就把降落的方向改變，只見地面越來越近\n");   
  if(arg=="空地")
  {
   me->move(__DIR__"stn8"); 
   me->start_busy(1);
   write(HIG"只見你身體緩緩彎曲，四週一陣飛砂走石，可是下降的力道卻全被化掉了，你平安到達了空地\n"NOR);   tell_room(environment(me), "天空一個黑影越變越大，周圍一陣飛塵竄動，"+me->name()+"從空中降了下來！\n", ({ me }));
  }
  if(arg=="巨大古木")
 {
   me->move(__DIR__"stn9");
   me->start_busy(1);
   write(HIG"只見你身體緩緩彎曲，周圍枝葉晃動，可是下降的力道卻全被化掉了，你平安到達了巨大古木\n"NOR);
   tell_room(environment(me), "天空一個黑影越變越大，周圍一陣枝葉晃動，"+me->name()+"從空中降了下來！\n", 
   ({ me }));
}
  return 1;
}

