inherit ROOM;
void create()
{
	set("short", "水道");
	set("long", @LONG
這裡就是水道底了，到達一處漸游漸高形如圓桶的出口。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"way4",
  "east" : __DIR__"way6",
]));

	setup();
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
      fish->move(__DIR__"way5");
      me->set_temp("fish",i+1);
    }
}
