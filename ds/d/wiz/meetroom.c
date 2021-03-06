// This Program was Written by Luky (ds.muds.net 7000)
// Original: The Dream of Seven.
// All rights reserved.1999.11.23
#include <ansi.h>
inherit ROOM;
void greeting();

string TOPIC="none";
int do_say(string arg);

void create()
{
 set("short",HIW"地下會議室"NOR);
        set("long", @LONG
這裡是巫師開會討論的地方。你看到這裡有一張很大的圓桌，桌
旁有許多高級的沙發椅，會議室上方還懸著一座十分豪華的水晶弔燈
，旁邊有個管理會議室的秘書小姐正坐在一旁的助理桌後。你看到樓
梯旁有張佈告欄(note)，上面寫著一些開會應注意的事項。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
//  "up" : __DIR__"hall1",
]));
	set("light",1);
        set("item_desc",([
        "note" : @NOTE
	
	會議用指令:
	============     ===============================
        start [名稱]     開始一個[名稱]會議 (arch以上)
        silent           將會議室設定為靜音狀態 (主持者)
        handover         將主持棒移交給他人 (主持者)
        kickout          將某個人踢出會議室 (主持者)
        topic            查詢目前會議的主題
        over             結束會議 (主持者)
        beginvote [字串] 開始投票 (可以利用 to beginvote)
        vote [數字]      投票
        endvote          結束投票
        ============     ===============================
        
        注意事項: 

        1. 一但開會之後，任何人不得隨意離開，除非議長同意。
	2. 開會時請用 say (') 發言。
NOTE
,
]));
         set("no_clean_up", 0);
         set("no_recall",1);
         setup();
}

void init()
{
        greeting();
        add_action("do_say","say");
        add_action("do_start","start");
        add_action("do_kickout","kickout");
        add_action("do_handover","handover");
        add_action("do_over","over");
        add_action("do_topic","topic");
        add_action("do_silent","silent");
        add_action("do_nomove","goto");
        add_action("do_nomove","home");
        add_action("no_chat","chat");
        add_action("no_chat","tchat");
        add_action("no_chat","wiz");
        add_action("no_chat","shout");
        add_action("no_chat","rumor");
        add_action("no_chat","sys");
        add_action("do_beginvote","beginvote");
        add_action("do_vote","vote");
        add_action("do_endvote","endvote");
        add_action("noupdate","update");
}

int no_chat(string arg)
{
	if(!this_object()->query("silent")) return 0;
	tell_object(this_player(),"現在會議室是靜音模式，禁止使用一些頻道喔。\n");
	return 1;
}

int do_nomove(string arg)
{
	if(TOPIC!="none")
	{
		write("正在開會中喔!! 如果真的要離開請用 up 離開。\n");
		return 1;
	}
	return 0;
}
int noupdate(string arg)
{
	if(TOPIC!="none" && ( arg == "here" || arg == "/d/wiz/meetroom" || arg == "/d/wiz/meetroom.c"))
	{
		write("正在開會中喔!!請勿擾亂會議。\n");
		return 1;
	}
	return 0;
}

int do_beginvote(string arg)
{
	object me;
	me=this_player();
	if(!wizardp(me)) return notify_fail("你不是巫師。\n");
	if(stringp(this_object()->query("vote"))) return notify_fail("目前正在舉行投票!\n");
	if(TOPIC=="none" ) return notify_fail("目前並沒有開會!\n");
	message_vision(HIC"\n$N提出投票:\n"+arg+"\n"NOR,me);
	log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)提出投票項目。\n\n"NOR+arg+NOR+"\n\n",me->query("name"),me->query("id")));
	this_object()->set("vote",arg);
	this_object()->set("vote_leader",me->query("id"));
	this_object()->delete("vote_result");
	this_object()->delete("vote_member");
	return 1;
}

int do_vote(string arg)
{
	object me;
	string *members;
	me=this_player();
	if(!stringp(this_object()->query("vote"))) return notify_fail("目前並沒有舉行投票!\n");
	if(TOPIC=="none" ) return notify_fail("目前並沒有開會!\n");
	if(!arg) return notify_fail("你要投什麼票?!\n");
	members=this_object()->query("vote_member");
	if(sizeof(members))
	{
		if(member_array(({me->query("id")}),members)!=-1) return notify_fail("你已經投過票了!\n");
	}
	this_object()->add("vote_result/"+arg,({me->query("id")}));
	this_object()->add("vote_member",({me->query("id")}));
	message_vision(HIG"\n$N投票給: "+arg+"\n"NOR,me);
	log_file("meeting/"+TOPIC,sprintf(HIG"%s(%s)投票給 "NOR+arg+NOR+"\n",me->query("name"),me->query("id")));
	return 1;
}

int do_endvote(string arg)
{
	object me;
	mapping vote;
	string *keys,*who,str;
	int i,j;
	me=this_player();
	if(!stringp(this_object()->query("vote"))) return notify_fail("目前並沒有舉行投票!\n");
	if(TOPIC=="none" ) return notify_fail("目前並沒有開會!\n");
	if(me->query("id")!=this_object()->query("vote_leader")) return notify_fail("必須是發起人才能結束投票!\n");
	message_vision(HIC"\n$N結束了這次的投票:\n"NOR,me);
	log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)結束投票。\n"NOR,me->query("name"),me->query("id")));
	vote=this_object()->query("vote_result");
	if(!mapp(vote))
	{
		message_vision(HIW"秘書小姐說: 這次投票沒有結果。\n"NOR,me);
	}
	else
	{
		keys=keys(vote);
		str=HIW"秘書小姐說: 這次投票結果如下:\n";
		for(i=0;i<sizeof(keys);i++)
		{
			str+="  投給: "+keys[i]+" 的有"+sizeof(vote[keys[i]])+"票";
			for(j=0;j<sizeof(vote[keys[i]]);j++) str+="("+vote[keys[i]][j]+")";
			str+="\n"+NOR;
		}
		message_vision(str,me);
		log_file("meeting/"+TOPIC,str);
	}
	this_object()->delete("vote");
	this_object()->delete("vote_leader");
	this_object()->delete("vote_result");
	this_object()->delete("vote_member");
	return 1;
}

int do_silent(string arg)
{
	object me,*members;
	int i;
	string chief,*channels;
	me=this_player();
	if(TOPIC=="none" || !stringp(chief=this_object()->query("meeting_chief"))) return notify_fail("目前並沒有開會!\n");
	if(me->query("id")!=chief) return notify_fail("只有目前會議的招集人("+chief+")才能設定為靜音模式!\n");
	message_vision("$N將會議室設定為靜音模式。\n",me);
	members= all_inventory(this_object());
	for(i=0;i<sizeof(members);i++)
	{
		if(members[i]->query_temp("channels")) continue;
		if(channels=members[i]->query("channels"))
		{
			members[i]->set("channels", ({"sys"}));
			members[i]->set_temp("channels",channels);
		}
		members[i]->set("env/auto_reply","巫師現在正在開會喔!!\n");
	}
	set("silent",1);
	return 1;
}

int do_kickout(string arg)
{
	object me,who;
	int i;
	string chief;
	me=this_player();
	if( TOPIC=="none" || !stringp(chief=this_object()->query("meeting_chief")) ) return notify_fail("目前並沒有開會!\n");
	if( me->query("id")!=chief ) return notify_fail("只有目前會議的招集人("+chief+")才能踢人!\n");
	if(!arg) return notify_fail("你要踢誰出去!?\n");
	who = present(arg, this_object());
	if(!who) return notify_fail("這裡沒有這個人。\n");
	if( who == me ) return notify_fail("你不能將自己踢出會議室。\n");
	message_vision(HIW"$N將$n踢出會議室。\n"NOR,me,who);
	add("kickouts",({ who->query("id") }));
	who->move(__DIR__"hall1");
	log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)將%s(%s)踢出會議室。\n"NOR,me->query("name"),me->query("id"),who->query("name"),who->query("id")));
	return 1;
}

int do_topic(string arg)
{
	string chief;
	if(TOPIC=="none") write("目前並沒有會議在進行。\n");
	else
	{
		write(HIG"目前會議的主題是: [ "HIW+TOPIC+HIG" ] "NOR);
		if(chief=this_object()->query("meeting_chief")) write(HIG"主持人是: [ "HIW+chief+HIG" ] "NOR);
		write("\n");
	}
	return 1;
}

void greeting()
{
	object ob;
	string *kickouts;
	ob=this_player();
	kickouts=this_object()->query("kickouts");
        if(!arrayp(kickouts))
        {
        	     if(TOPIC=="none") message_vision(HIG"\n 會議秘書對$N微笑的說: 嗨! "+ob->name()+"現在還沒開始開會喔！\n\n"NOR, ob);
        	     else
        	     {
        	     	message_vision(HIG"\n 會議秘書對$N說: 啊! 會議已經開始了趕快找位置坐下吧！\n\n"NOR, ob);
        	        log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)進入會議室。 [%s]\n"NOR,
			this_player()->query("name"),this_player()->query("id"),ctime(time())));
        	     }
        }
        else
        {
        	if( member_array(ob->query("id"),kickouts) || !userp(ob))
        	{
    			message_vision(YEL"\n會議秘書一看見$N想進來就把$N推了出去:"HIW" 現在正在開會中，閒雜人等請勿進入！\n\n"NOR, ob);
			ob->move(__DIR__"hall1");
        	}
        }
        return;
}

int do_say(string arg)
{
	if(!arg) return 0;
	remove_call_out("rush");
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg = replace_string(arg, "$BEEP$", BEEP);
	message_vision(HIY+"$N說:"+arg+"\n"NOR,this_player());
        if(TOPIC !="none")
  	log_file("meeting/"+TOPIC,sprintf( "%s(%s)說道: "HIC+arg+NOR"\n",
	this_player()->query("name"),this_player()->query("id")));
        call_out("rush",300);
        return 1;
}

int do_start(string str)
{
	object me;
        me=this_player();
        if(!wizardp(me)) return notify_fail("你不是巫師。\n");
  	if( wiz_level(me) < wiz_level("(arch)") )
  		return notify_fail(HIW"arch 以上的職務才能主持會議。\n"NOR);
  	if(TOPIC !="none") return notify_fail("目前已經有一個會議了。\n");
  	if(!str ) return notify_fail("開會必須要指定一個主題才能做記錄。\n");
        if( str =="none") return notify_fail("會議名稱不可以為 none 。\n");
        TOPIC =str;
 	message_vision("[開始開會]-會議名稱:"HIC+str+NOR" 主持者: "HIG"$N "NOR"。\n",this_player());
 	log_file("meeting/"+TOPIC, sprintf("開始開會-會議名稱:" HIC+str+NOR" 主持者: "HIG"%s \n",this_player()->short(1)));
 	log_file("static/MEETING",
  	sprintf( "%s(%s)主持會議 "HIC+TOPIC+NOR"。[%s]\n",me->name(1), geteuid(me), ctime(time()) ) );
        this_object()->set("meeting_chief",me->query("id"));
        return 1;
}

int do_handover(string arg)
{
	object me,who;
	int i;
	string chief;
	me=this_player();
	if(TOPIC=="none" || !stringp(chief=this_object()->query("meeting_chief")) ) return notify_fail("目前並沒有開會!\n");
	if(me->query("id")!=chief) return notify_fail("只有目前會議的招集人("+chief+")才能轉移主持棒!\n");
	if(!arg) return notify_fail("你要將主持棒交給誰!?\n");
	who = present(arg,this_object());
	if(!who) return notify_fail("這裡沒有這個人。\n");
	if( who == me ) return notify_fail("你已經是主持人了。\n");
	message_vision(HIW"$N將主持棒移交給$n。\n"NOR,me,who);
	this_object()->set("meeting_chief",who->query("id"));
	log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)將主持棒移交給%s(%s)。\n"NOR,
	me->query("name"),me->query("id"),who->query("name"),who->query("id")));
	return 1;
}

int do_over(string arg)
{
	object me,*members,leader;
	string chief,*channels;
	int i;
        me=this_player();
        if(!wizardp(me)) return notify_fail("你不是巫師。\n");
	if(TOPIC=="none")
	{
		if(stringp(chief=this_object()->query("meeting_chief"))) this_object()->delete("meeting_chief");
		return notify_fail("目前並沒有會議。\n");
	}
 	if(stringp(chief=this_object()->query("meeting_chief")) && chief != me->query("id"))
 	{
 		if(leader=present(chief,this_object()) ) return notify_fail("只有目前會議的招集人"+leader->name()+"("+chief+")才能結束會議!\n");
 		else 
 		{
 			message_vision("秘書小姐宣佈: 由於主持者 "+chief+" 離開了, 所以會議被迫結束囉!!\n",me);
 		}
 	}
 	message_vision(YEL"$N對秘書說: 會議都紀錄下來了嗎? 好吧，那麼今天的會議就到此結束。\n"+HIW+"會議秘書高興的說: "+TOPIC+"會議結束，謝謝大家的參予!\n"NOR,this_player());
        this_object()->delete("meeting_chief");
        log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)宣佈結束會議(%s)。\n"NOR,
	me->query("name"),me->query("id"),TOPIC));
 	log_file("static/MEETING",
  	sprintf( "%s(%s)結束會議 "HIC+TOPIC+NOR"。 [%s]\n",me->name(1), geteuid(me), ctime(time()) ) );
        TOPIC ="none";
        members= all_inventory(this_object());
	for(i=0;i<sizeof(members);i++)
	{
		if(channels=members[i]->query_temp("channels"))
		{
			members[i]->set("channels", channels);
			members[i]->delete_temp("channels");
		}
		members[i]->delete("env/auto_reply");
	}
	this_object()->delete("kickouts");
	this_object()->delete("silent");
	this_object()->delete("vote");
	this_object()->delete("vote_leader");
	this_object()->delete("vote_result");
	this_object()->delete("vote_member");
        return 1;
 }

int valid_leave(object me, string dir)
{
	string *channels;
        if( dir=="up" )
        {
        	if(me->query("id")==this_object()->query("meeting_chief") && TOPIC != "none") return notify_fail("請先結束會議(over)再離開!\n");
        	if(channels=me->query_temp("channels"))
        	{
        		me->set("channels",channels);
        		me->delete_temp("channels");
        		me->delete("env/auto_reply");
        	}
        	if(TOPIC!="none")
        	{
        	
        		log_file("meeting/"+TOPIC,sprintf(HIW"%s(%s)離開會議。 [%s]\n"NOR,
			this_player()->query("name"),this_player()->query("id"),ctime(time())));
		}
        }
        return ::valid_leave(me, dir);
}

void rush()
{
	tell_room(this_object(),YEL"會議秘書小聲的說: 請大家踴躍發表意見。\n"NOR);
	call_out("rush",300);
}
