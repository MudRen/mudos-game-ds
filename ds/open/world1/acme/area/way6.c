inherit ROOM;
void create()
{
	set("short", "水道出口");
	set("long", @LONG
終於到了水道出口了，在出口的前方有個石崖，此石崖甚高，故
石崖上頭沒有水了，但要爬上去是十分不易的事。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"way5",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "石崖" : "這是一個相當陡峭的石崖，要爬(climb)上去頗為困難。\n",
]));

	setup();
}
void init()
{ 
         add_action("do_climb","climb");
}
int do_climb(string arg)
{
          object me;
          me=this_player();
          if(arg != "石崖")
            return notify_fail("你要攀爬什麼？\n");
          else {
            if(me->query("str")<9) 
            {
              tell_object(me,"你的力量不夠無法攀爬上去。\n");
            }
            else {
              message_vision("$N奮力的往石崖上爬去。\n",me);
              me->move(__DIR__"stone3");
            }
            return 1;
          }
}
int room_effect(object me)
{
        if( !userp(me) ) return notify_fail("只有玩家才會被水嗆到哦。....:P\n");
        switch(random(4))
        {
                
         case 0:        message_vision("$N承受不住這強力的水壓，$N只覺得喉頭一甜，吐出了一口鮮血。\n",me);
                        me->receive_damage("hp",random(20)+50);
                        call_out("fish",4,me);
                        return 1;
         case 1:        message_vision("$N因憋氣過久，一時撐不住，喝了一大口的水。\n",me);
                        me->receive_damage("hp",random(20)+30);
                        return 1;
         default:       message_vision("$N一個不小心吸被水嗆到了，露出了痛苦的表情。\n",me);
                        me->receive_damage("hp",random(20)+10);
                        return 1;
        }
}
int fish()
{
    int i;
    object me,fish;
    me=this_player();
    i=me->query_temp("fish");
    if(i<10)
    {
      message_vision("你看見在深洞中游出了一群食人魚，可能是嗅到血腥味，才游來這裡的吧。\n",me);
      fish=new(__DIR__"npc/fish");
      fish->move(__DIR__"way6");
      me->set_temp("fish",i+1);
    }
}
