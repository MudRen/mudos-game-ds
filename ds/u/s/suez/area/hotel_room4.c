// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "小屋");
	set("long",@LONG
這小屋裡竟然是一個溫泉，外面的小溪流入的水使這個溫泉並不十分
的熱，也沒有那硫磺的臭味，反倒是竹子的味道比較濃烈，三四片竹葉飄
在水面上，一塊塊光滑的石頭陳列在旁，透過小窗而來的竹影蘇蘇而響，
你看了真想跳下去好好洗個澡。溫泉旁有面小木牌，上面寫著「玉竹泉」
。
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "bridge" : __DIR__"hotel_back",
            ]));
         set("item_desc",([
        "小木牌":"木牌上寫著「玉竹泉」,下面還有行小字「飲用水，請勿在此洗澡。」\n",
        "石頭":"上面長滿了青苔，綠色的光澤很好看，看來這不是普通的青苔。咦？怎麼有一個地方沒長青苔？好像有人常常觸摸這地方的樣子。\n",
         ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
}
void init()
{
        add_action("do_drink", "drink");
        add_action("do_knock", "knock");

}

int do_drink(string arg)
{
       object me;
      int pplmp;
        me=this_player();    
      pplmp=me->query("mp");
      if (arg != "泉水" ) return 0;
      message_vision("$N伸手掬了一些溫泉水喝下去。\n",me);
     me->start_busy(2);
      if(pplmp <10)
       {
      tell_object(me,"啊！燙燙燙燙！這裡的溫泉水看來比你想像中還熱。\n");
         return 0;
     }
     else
      {
       tell_object(me,"水中的熱氣順著咽喉流入四肢百骸之中，頓時你覺得好多了！\n");
       call_out("cure_all",1,me);
     me->receive_damage("mp", 5 );
       return 1;
     }
      
}

int do_knock(string arg)

{
        object me;
        me=this_player();
        if(arg != "石頭") return 0;
        message_vision("$N以一獨特的節奏敲擊著石頭，只見小屋靠山壁的牆緩緩上升，露出一條陰暗的通道。\n\n",me);
         set("exits", ([
               "enter":__DIR__"hole_out",
                   "bridge" : __DIR__"hotel_back",
        ]));
        return 1;
}