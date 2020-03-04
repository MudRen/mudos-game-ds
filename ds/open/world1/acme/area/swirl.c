inherit ROOM;
void create()
{
	set("short", "深洞中");
	set("long", @LONG
這是流波潼下具有強力吸力的深洞中，你直往裡頭吸去，得快點
想辦法脫逃出去，否則將溺斃於此。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"valley",
  "east" : __DIR__"swirl2",
]));
	setup();
}
void init()
{
    object me;
    me=this_player();
    call_out("start",2,this_player() );
    me->start_busy(2);
}
int start()
{
    int i;
    object me;
    me=this_player();
    i=me->query_temp("swirl");
    if(me->query_skill("swim")<40)
    {
      message_vision("$N被強力的漩渦所吸，轉眼間$N已無影無蹤。\n",me);
      me->receive_damage("hp",random(10)+20);
      if(i>4)
      {
        me->move(__DIR__"swirl2");
        me->delete_temp("swirl");
      }
      else {
        me->set_temp("swirl",i+1);
        me->move(__DIR__"swirl");
      }
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
      fish->move(__DIR__"swirl");
      me->set_temp("fish",i+1);
    }
}
