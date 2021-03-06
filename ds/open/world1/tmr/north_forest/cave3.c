#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "地底洞穴");
	set("long", @LONG
你正處在一個地底洞穴中，由於陽光無法照射進來，所以四週盡是黑漆
漆的一切，你只能勉強順著岩壁往前進。你注意到地上有個火堆，還有些餘
燼，不知道是怎樣的生物留下這個火堆。
LONG
	);
	set("current_light", 4);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
	  __DIR__"npc/troll4" : 2,
	  __DIR__"npc/troll5" : 2,
	  __DIR__"npc/troll6" : 1,
	]));
  set("item_desc",([
      "火堆" : "火堆中還有些餘燼，你可以用來烤一些肉(grill)。\n",
     ]));
	set("exits", ([ /* sizeof() == 2 */
 "north" : __DIR__"cave2",
]));

	setup();
}

void init()
{
  add_action("do_throw","grill");
}


void call_troll() {
	object mobp;
	if(query_temp("is_grill")) return;

	if( query_temp("meats") < 3 + random(3) ) {
              message_vision( "烤肉的香味越來越濃郁......\n" NOR, this_player());
		 return;
	}

  mobp = new(__DIR__"npc/troll7"); 
  mobp->move(environment(this_player()));   
  message_vision( HIG "忽然，一隻龐大的生物出現了！！\n" NOR, this_player(), mobp);
  mobp->force_me("lick");
  set_temp("is_grill",1);
    call_out("stop_throwed", 300 + random(60));
}

int do_throw(string arg)
{ 
  object me=this_player(), meat; 
	if(me->is_busy())
		return notify_fail("你正忙著，沒有空烤肉。\n");
  if( query_temp("is_grill") )
		return notify_fail("你發現到其實火堆並不旺，暫時無法烤肉。\n");
  if(!arg || arg != "meat")
		return notify_fail("你想要烤什麼東西？\n");
  if(!objectp(meat=present("_BEEF_MEAT_",me) ) )
    return notify_fail("這個東西無法拿來烤。\n");

  message_vision( HIY "$N將$n"HIY"放在火堆上烤，烤著烤著，一陣肉香味飄了出去，充滿整個洞穴。\n" NOR, me, meat);
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

