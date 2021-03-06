// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"旅館二樓"NOR);
	set("long", @LONG
陽光從窗戶透射進來，照亮了整個房間。從這裡可以很清楚的看見窗
外的風景，如果把窗簾(drapes)拉上，你會發現窗簾就好像是一幅畫一樣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room104",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("no_fight",1);
	set("no_cast",1);
	set("no_exert",1);
	set("room_type","hotel");

	setup();
}

void init()
{
	add_action("do_draw","draw");
	add_action("do_sleep","sleep");
}

int do_draw(string arg)
{
        if( arg == "drapes" )
        {
                if( query_temp("drapes_close") )
                        return notify_fail("窗簾已經拉了起來了 !\n");
                message_vision("$N將窗簾輕輕的拉了起來, 裡面變得比較暗了..\n", this_player());
                tell_room(this_object(),"你準備舒舒服服的睡個覺(sleep)了嗎 ?\n", ({ }));
//              message_vision("你似乎發現窗簾似乎帶有著某些圖案\n", this_object());
//              準備給冒險者用。 by cominging
                set_temp("long", @LONG
拉上的窗簾掩住了強烈的陽光，轉而變成一道道柔和的陽光，投射了
進來，房間內給了你溫和、舒服的感覺。
LONG            );
                set_temp("drapes_close", 1);
                return 1;
        }
        else return 0;
}

int do_sleep(string arg)
{
	object me;
	me=this_player();
	if(me->query_temp("is_busy/sleeping"))
	{
		write("你正在睡覺。\n");
		return 1;
	}
	if( me->query_temp("hotel_1") <= 0 )
	{
		write("你要先付費才能休息。\n");
		return 1;
	}
	message_vision( GRN"$N揉了揉眼睛，眼皮似乎被瞌睡蟲給找上了，忍不住往床上一躺∼\n\n" NOR, me);
	tell_object(me,"你眼睛一閉，隨即就在香軟錦美的床上睡著了.....\n\n" NOR );
	tell_object(me, HIB"ｚＺｚＺＺＺｚＺＺＺＺＺｚｚＺＺｚ\n\n\n" NOR );
	me->set_temp("is_busy/sleeping","你正在睡覺。");
	me->start_busy(10);
	call_out("sleep1",3,me);
	call_out("sleep2",8,me);
	call_out("wakeup",15,me);
	return 1;
}

void sleep1(object me)
{
	if(!me) return;
	tell_object(me,HIG"你漸漸進入了夢鄉，夢見自己漂流在沙漠∼\n"NOR);
	me->receive_heal("hp",me->query_con()*4);
	me->receive_heal("ap",me->query_con()*2);
	me->receive_heal("mp",me->query_int()*3);
	return;
}

void sleep2(object me)
{
	if(!me) return;
	if(random(2)) tell_object(me,HIG"夢中的你遇到了一群野狼..凹嗚∼\n"NOR);
	else tell_object(me,HIG"你走到了一片綠洲，有好多的水果喔∼\n"NOR);
	me->receive_heal("hp",me->query_con()*5);
	return;
}

void wakeup(object me)
{
	if(!me) return;
	if(random(2)) tell_object(me,"你覺得你的膀胱快爆了..不得不起床。\n");
	else tell_object(me,"你突然被附近小孩的哭聲給吵醒了。\n");
	message_vision(HIW"$N伸了一個懶腰，揉了揉眼睛醒了過來。\n" NOR,me);
	me->delete_temp("is_busy/sleeping");
	me->receive_heal("hp",me->query_con()*7);
	me->receive_heal("mp",me->query_int()*3);
	me->receive_heal("ap",me->query_con()*3);
	me->add_temp("hotel_1",-1);
	return;
}
