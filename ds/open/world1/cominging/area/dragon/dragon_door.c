#include <ansi.h>
#include <path.h>
inherit ROOM;

int dragon(object me);

void create()
{
	set("short", HIC"狂龍之門"NOR);
	set("long",@LONG
你走到這裡，看到一扇五尺高的大門，門上有兩個龍形把手，把
手的上面各寫著狂龍。當你看見這兩個字時，心頭一震，原來這裡就
是江湖上鼎鼎大名的狂龍幫。傳說狂龍幫行俠仗義，好打不平，所有
武林中人都想入此幫派。但無奈要入狂龍幫，得先接受一連串的考驗
才可入門，你仔細考慮過後，決定進去試試。在門旁有幾尊石獅，石
獅雕的精細無比，栩栩如生。狂龍幫的外圍由圍牆所圍住，並且時常
有狂龍幫高手守衛著。
LONG
	);
	set("outdoors","land");
	set("light",1);
	set("exits",([
  "enter" : __DIR__"dragon_garth.c",
  "west" : TMR_PAST+"area/street5.c",
]));
	set("item_desc",([
  "龍形把手": "精細的一個把手，上面刻著狂龍兩字，似乎很難以刻上去。\n",
  "石獅": "一尊由名師田慎終所刻成的一尊石獅，雕的如真的一般，可以避邪之用。\n",
  "圍牆": "在門旁的圍牆，圍牆上有許\多的繪畫，似乎在美化環境。\n",
]));
set("no_goto",1);
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
	setup();
}

void init()
{
	::init();
        dragon(this_player());
}

int dragon(object me)
{
   object ob;
	if(!me) return 1; if(wizardp(me) ) return 1; // 要判斷 me 是否存在才能再用wizardp/userp -alick
   if(!userp(me)) // for mob. 避免別幫的招喚生物進入.
   {
   	if(ob=me->query("creater"))
   	{
   		if( !objectp(present("dragon plate",ob)) )
		{
			message_vision("狂龍幫的守衛大喝: 想混水摸魚? 做你的大頭夢吧, $N。\n"NOR,ob);
			me->move(TMR_PAST+"area/street5.c");
	        	tell_room(environment(me),me->name()+"被狂龍守衛趕了出來。\n",({ me }));
			return 1;
		}
	}
   }
    else
   {
	if( !objectp(present("dragon necklace",me)) && me->query("club/name")!="狂龍幫" )
	{
        message_vision(HIW"狂龍幫的守衛見$N不是狂龍幫的兄弟，立即將$N送至街上。\n"NOR,me);
		me->move(TMR_PAST+"area/street5.c");
	        tell_room(environment(me),me->name()+"被狂龍守衛給丟了出來。\n",({ me }));
		return 1;
	}
	
	if( me->query_temp("killer") )
	{
		message_vision("天上傳來一個幽幽的聲音: $N, 因為你剛剛殺了人所以暫時不能進入幫會。\n"NOR,me);
		me->move(TMR_PAST+"area/street5.c");
	        tell_room(environment(me),me->name()+"想逃入幫會可是被趕了出來。\n",({ me }));
		return 1;
	}
	
	if( me->query_temp("invader") )
	{
		message_vision("天上傳來一個幽幽的聲音: $N, 因為你剛剛攻擊無辜玩家, 所以暫時不能進入幫會。\n"NOR,me);
		me->move(TMR_PAST+"area/street5.c");
		tell_room(environment(me),me->name()+"想逃入幫會可是被趕了出來。\n",({ me }));
		return 1;
	}
	call_out("meeting",2,me);
	return 1;
   }   
}

void meeting(object me)
{
if(!me) return;
	switch( me->query("club/level") )
	{
		case 0:
		case 1:
			message_vision(HIY"狂龍守衛對$N說﹕"+"兄弟請進！請進！\n"NOR,me);
		break;

		case 2:
			message_vision(HIY"狂龍守衛對$N說﹕"+"這位堂主兄弟請進！請進！\n"NOR,me);
		break;

		case 3:
			message_vision(HIY"狂龍守衛對$N說﹕"+"護法請進！請進！\n"NOR,me);
		break;

		case 4:
			message_vision(HIY"狂龍守衛很有禮貌的對$N說﹕"+"這位狂龍長老請進！請進！\n"NOR,me);
		break;

		case 5:
			message_vision(HIY"狂龍守衛對$N鞠躬敬禮說﹕"+"副幫主大人您好呀！\n"NOR,me);
		break;

		case 6:
			message_vision(HIY"狂龍守衛對$N鞠躬敬禮說﹕"+"幫主大人您好呀！\n"NOR,me);
		break;
	}
	return;
}
