#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","地下水道");
	set("long",@LONG
幾隻蝙蝠被光一照就啪啦啪啦的飛了起來，富麗堂皇的設計讓這陰暗
的地底增添了些許詭異的氣氛，一陣寒風不知從何處吹來，牆上雕刻的奇
異圖形更讓人毛骨悚然，這裡似乎和地下水道的其他地方不太一樣....
LONG 
);	
	set("light",0);
	set("exits",([
	    "south":__DIR__"port_b5",
	    "west":__DIR__"port_b2"
		]));
	set("world","world1");
	set("objects",([
	    __DIR__"npc/bat":5,
		]));

	setup();
}
void init()
{
        add_action("do_search", "search");
}
void do_search(object me,string arg)
{
	switch(arg){
	 case "here":tell_object(me, "你發現這裡有 風,圖形.\n" );break;
	 case "風":tell_object(me, "你發現風竟然是從牆壁中吹出來的!\n" );break;
	 case "圖形":tell_object(me, "其他的圖形都是人物雕刻，但這個似乎是個魔法陣...？\n" );break;
	 case "牆壁":tell_object(me, "摸這個牆壁是實心的感覺啊！為什麼風會.....？\n" );break;
	 case "魔法陣":
		tell_object(me, "你仔細檢查這個魔法陣....\n" );
		me->start_busy(3);
		tell_object(me, "你面前的牆壁突然消失了！你一個不穩跌到另一面去！\n" );
		me->move(__DIR__"port_b6");
		break;
	 default:tell_object(me, "這裡的"+arg+"似乎沒什麼特別的。\n" );break;
	}
}