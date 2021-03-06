// talk.c 為了讓任務更有變化以及NPC更生動, 加了此一指令.
// 
//  以下為NPC新增函數, 對應於talk 可以做到所有動作.
//
// □1. talk_action [回應動作]
//
//     若NPC有加入此函式, 則 talk 時會NPC執行此函式之動作.
//     return 1 則不會出現 talk_reply訊息, 若為return 0; 則執行完action後會呼叫reply
// 
// 範例:(/u/l/luky/npc/passenger.c)
//
// int talk_action(object me)	
// {
// command("smile "+me->query("id") );
// return 1;
// }
//
// □2.talk_reply [回應訊息]
// 
//      若NPC有設定此字串( set("talk_reply",<訊息>); ) 則在talk時會說出此<訊息>字串.
//	字串中可以有$N(NPC名稱) $n(玩家名稱) 等等代號;
//      若沒有設, 則會以NPC的態度設定來決定會應訊息, 若態度為"killer"則會開始攻擊.
//
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int flag=0;
          string dest, attitude, words,*keyword;
	object ob;
	mapping keywords;
	mixed reply,output;
	
	if( ! arg )
		return notify_fail("你自言自語了一會兒覺得很無聊。\n");
	if( sscanf(arg, "with %s about %s",dest,words) != 2 )
	{
	 	if(sscanf(arg, "with %s",dest) != 1)
		return notify_fail("指令格式﹕talk with <某人>\n");
	}
	if( !(ob = present(dest, environment(me))) )
		return notify_fail("這裡沒有 " + dest + "。\n");
	if( !living(ob) )
		return notify_fail("這個物件不能對談。\n");
	if( ob == me )
		return notify_fail("你自言自語了一會兒覺得很無聊。\n");
	if( userp(ob) )
	{
	  if(words) 
	  {
	   message_vision(YEL"$N向$n說: "+words+"\n"NOR,me,ob);
	  }
	  else
	  {
	   tell_object(ob,me->query("name")+"似乎有事情要和你討論。\n");
	   write("你向"+ob->query("name")+"提出聊天的建議。\n");
	  }
	  return 1;
	}
	else
	{
	 if(keywords=ob->query("inquiry"))
	 {
	 	flag=1;
	 	keyword=keys(keywords);
	 }
	 if(!userp(me) && words)
	 message_vision("$N向$n說: "+words+"\n",me,ob);
	 else
	 message_vision(YEL"$N對$n說: 你好.. 有什麼地方我可以效勞的嗎?\n"NOR,me,ob);
	 
	 if(ob->talk_action(me)) return 1;
	 reply=ob->query("talk_reply");
	 if(functionp(reply)){
	 	output=evaluate(reply);
	 	if(stringp(output))
	 	{
	 		message_vision(HIY"$N對$n說: "HIG+output+"\n"NOR,ob,me);
	 		return 1;
	 	}
	 }
	 else if(stringp(reply))
	 {
	  message_vision(HIY"$N對$n說: "HIG+reply+"\n"NOR,ob,me);
	  return 1;
	 }
	 else
	 { 
	  if(flag)
	  {
		words=HIY+"$N說: "+HIG+"如果想打聽關於『"+implode(keyword, "、")+"』的問題，可以問(ask)我。\n"+NOR;
		message_vision(words,ob,me);
		return 1;
	  }
	  if( ob->query("race")=="人類" || ob->query("race")=="human" )
	  {
	  	attitude = ob->query("attitude");
	  	switch(attitude)
	  	{
	  	 case "friendly" :
	  	 		message_vision(YEL"$N笑著說: 你太客氣了, 目前一切都很順利不用麻煩您了。\n"NOR,ob);
	  	 		break;
	  	 case "peaceful" :
	  	 		message_vision(YEL"$N瞇著眼睛笑著說: 託您的福, 凡事都還算順利。\n"NOR,ob);
	  	 		break;
	  	 case "heroism"	 :
	  	 		message_vision(HIW"$N冷冷的說: 我的事情我自己會解決, 不勞閣下費心。\n"NOR,ob);
	  	 		break;
	  	 case "aggressive" :
	  	 		message_vision(HIM"$N冷哼一聲: 嘿..你先解決你自己的困難吧。\n"NOR,ob);
	  	 		if(random(6) > 3) ob->kill_ob(me);
	  	 		break;
	  	 case "killer" :
			 	message_vision(HIC"$N大喝: 你也太不知道天高地厚了!! 你老子的事不用你管!!!!\n"NOR,ob);
				ob->kill_ob(me);
				break;
		 default :
		 		message_vision(YEL"$N說: 嗯..還好啦!! 我想應該還有其他人比我更需要你的幫助吧。\n"NOR,ob);
				break;
	        }
		return 1;
	  }
	  else
	  {
	   message_vision("$N一臉茫然.. 似乎聽不懂$n說的話。\n",ob,me);
	   return 1;
	  }
	 } 
	}
	return 0;
}

int help(object me)
{
	write(@Help
指令格式﹕talk with <某人>

  和某位人物溝通, 通常當你發現某個人似乎有困難時, 可以用此指令得知問題
  之所在, 以便解決問題(任務)。有時對方也可能會做出讓你出乎意料的反應。

Help
	);
	return 1;
}
