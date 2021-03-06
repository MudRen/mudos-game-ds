// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"旅館二樓"NOR);
	set("long", @LONG
高級的房間就是這裡了，你看到這裡的裝潢及氣氛就覺得疲勞度減輕
了一半。木製的的地板加上有清爽的盆栽陪襯，迷人的床鋪就在眼前。還
有電視、冰箱一應具全。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "north": __DIR__"room105",
            "down" : __DIR__"room079",
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
	add_action("do_sleep","sleep");
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
	message_vision(GRN"$N揉了揉眼睛，眼皮似乎被瞌睡蟲給找上了，忍不住往床上一躺∼\n\n" NOR, me);
	tell_object(me, "你眼睛一閉，隨即就在香軟錦美的床上睡著了.....\n\n" NOR );
	tell_object(me, HIB "ｚＺｚＺＺＺｚＺＺＺＺＺｚｚＺＺｚ\n\n\n" NOR );
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
	tell_object(me,HIG"你漸漸進入了夢鄉，夢見自己漂流在海上∼\n"NOR);
	me->receive_heal("hp",me->query_con()*4);
	me->receive_heal("ap",me->query_con()*2);
	me->receive_heal("mp",me->query_int()*3);
	return;
}

void sleep2(object me)
{
	if(!me) return;
	if(random(2)) tell_object(me,HIG"夢中的你遇到了大白鯊..嗚∼\n"NOR);
	else tell_object(me,HIG"你飄到了一個孤島，上面的帥哥美女都是不穿衣服的∼\n"NOR);
	me->receive_heal("hp",me->query_con()*5);
	return;
}

void wakeup(object me)
{
	if(!me) return;
	if(random(2)) tell_object(me,"你的膀胱快爆了..不得不起床了。\n");
	else tell_object(me,"你突然被一陣電話鈴聲給吵醒了。\n");
	message_vision(HIW"$N伸了一個懶腰，揉了揉眼睛醒了過來。\n" NOR,me);
	me->delete_temp("is_busy/sleeping");
	me->receive_heal("hp",me->query_con()*7);
	me->receive_heal("mp",me->query_int()*3);
	me->receive_heal("ap",me->query_con()*3);
	me->add_temp("hotel_1",-1);
	return;
}