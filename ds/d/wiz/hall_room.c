// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "房間討論廳");
 set("long", @LONG
這裡是巫師討論區域房間寫法和發表新區域的地方，往西是區域
研究室。要觀看房間注意事項請輸入< about room > 

LONG
	);
 set("light",1);
// set("exits", ([ /* sizeof() == 2 */
// ]));
 set("hide_exits", ([ /* sizeof() == 2 */
    "west"   : __DIR__"hall_area",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/room_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="room")
 {
   if( file_size("/doc/wiz/room.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/room.txt") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}

// 可以用來做特殊效果(如燙傷,凍傷,中毒,補血,或是定時訊息)
// 由/feature/damage.c 呼叫此函數.
// add by Luky.
int room_effect(object me)
{
	switch(random(14))
	{
		
	 case 7:	message_vision("∼咻∼∼碰!!　$N突然被天上掉下來的花瓶打到了。\n",me);
	 		me->receive_damage("hp",random(3)+1);
	 		return 1;
	 case 6:	message_vision("∼咻∼∼啪!!　$N突然被天上掉下來的龍蝦糞砸到頭。\n",me);
	 		me->receive_damage("mp",random(3)+1);
	 		return 1;
	 case 5:
	 case 4:	tell_object(me,"∼咻∼∼突然天上掉下來一坨龍蝦糞。\n");
	 		return 1;
	 
	 case 3:
	 case 2:	tell_object(me,"∼咻∼∼突然天上掉下來一個花瓶。\n");
	 		return 1;
	 case 1:
	 case 0:	message_vision("$N挖了挖鼻孔。\n",me);
	 		return 1;
	 
	 default:	return 1;
	}
}