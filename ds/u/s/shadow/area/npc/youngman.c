/**
 *	Shadow's mob - 年輕人(解謎人物)
 */
 
#include <ansi.h>
inherit NPC;

int quest();

void create()
{
	/* 人物基本設定 */
	set_name( "年輕人", ({ "young man", "man" }) );
	set("long", @LONG
    他兩眼空洞，只是呆呆的望著湖心，不發一語，手中緊握著
一塊白玉，不時低頭撫拭，一臉的哀愁似乎是有無限的心事，也許
你可以可以和他談談。(talk with young man)
LONG
	);
	set("level", 20);	
	set("age", 21);
	set("no_fight", 1);
  set("chat_chance", 20);
  set("chat_msg", ({
		(: quest :),
	}));

	/* 關於任務的訊息 */
	set("talk_reply", "........ 要說(say)甚麼呢？失去的東西再也回不來了...");
		
	setup();

	call_out("re_quest", 900);
}

int quest()
{
	object ob = this_object();
	if(ob->query_temp("pass_quest"))	message_vision("已經沒有甚麼事情再能煩惱我了！\n",ob);
	else command("sigh");
	return 1;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("pass_quest_who");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  call_out("re_quest", 900);
  return 1;
}

void relay_say(object me, string str)
{
	object ob = this_object(), obj;
	string game_index = "no";
  if( !userp(me) ) return;
  if (ob->query_temp("pass_quest"))	{
  	write("多謝這位"+RANK_D->query_respect(me)+"的好意！已經沒有甚麼事情再能煩惱我了！\n");
  	return;
  }	
  if(strsrch(str,"失去的東西") !=-1)	{
		command("say ...................");
		message_vision(YEL"年輕人頭也不回，只是呆望著湖面不發一語。\n"NOR, me);
		message_vision(YEL"你說：我路經此地。看你愁容滿面的，看來一副心事心事重重的樣子，怎啦，最近魚兒不上勾啊!?\n"NOR, me);
		message_vision(YEL"年輕人無奈的聳聳肩勉強苦笑了一下，但隨即又重重的嘆了一口氣。\n"NOR, me);
		message_vision(YEL"這世上還有誰能幫我的忙呢？。\n"NOR, me);
		command("sigh");
  } else if (strsrch(str,"我") !=-1 || strsrch(str,"幫忙") !=-1)	{
		command("say 唉...謝謝你的好意，這可不是普通人可以幫我的..。");
		message_vision(YEL"年輕人轉身正準備回竹屋之時，眼角瞥見了你一身行頭。眼睛突然為之一亮，急忙一把抓住了你的雙手。\n"NOR, me);
		command("say 看您一身罕見的裝備，一定是行走江湖的大俠，身手想必不凡。");
		command("say 可以..可以請你幫我一個忙嘛，你..一定要幫我..一定要幫我。");
		me->command("nod");  	
  } else if ( strsrch(str,"可以") !=-1 || strsrch(str,"好") !=-1 || strsrch(str,"沒問題")!=-1 )	{
		message_vision(YEL"年輕人開始述說整個事情的來龍去脈給你聽。\n"NOR, me);
		message_vision(YEL"......\n"NOR, me);
		message_vision(YEL"她叫「涵」，我把希望都託付給你了，事成之後我一定好好報答你。\n"NOR, me);
  	message_vision(YEL"語畢，年輕人就把手中的白玉遞給你。\n"NOR, me);
		new(__DIR__"key")->move(me); /* 將白玉交給玩家 */
		//command("give " + me->query("id") + " key");
		set_temp("item_give", 1);
		set_temp("item_give_who", me->name(1));
		message_vision(YEL"年輕人：從這個浮橋可以跳下去(jump down)，一切都拜託你了。\n"NOR, me);
  	message_vision(YEL"年輕人朝你揮了揮手。\n"NOR, me);  	
  }
  return;
}

