// 幫會信物
// "level": 玩家在幫會中的等級(1~?)
// 1: 一般幫眾 
// 2: 堂主 
// 3: 護法 
// 4: 長老 
// 5: 副幫主 (限1名)
// 6: 幫主 (限1名)
// "title": 幫會頭銜
// "info1": 備用區1 (分堂名稱)
// "info2": 備用區2
// "info3": 備用區3
// info:
// ([
//    level:
//    title:
//    info1:
//    info2:
// ])
#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "狂龍幫"
#define CLUB_ID "dragon"
#define CLUB_CHANNEL "dragon"
#define CLUB_MARK "dragon necklace"
inherit NECK;
private string *members_level = ({
	"幫友", //0
	"幫眾", //1
	"堂主", //2
	"護法", //3
	"長老", //4
	"副幫主", //5
	"幫主", //6
});
void create()
{
	set_name(HIR"龍形項鍊"NOR,({"dragon necklace","necklace","club_mark"}));
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",0);
		set("material","iron");
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","串");
	set("long",@LONG
這是一串火紅色的項鍊, 用來證明自己是狂龍幫的一份子。
你可以用(help dragon)來查看有什麼幫會指令。若想了解狂龍幫
的歷史可以用(about dragon)來取得進一步的資料。

LONG
);
	}
	set("club_id",CLUB_ID);
	set("club",CLUB_NAME);
	set("sub_club",({"神龍堂","狂龍堂","猛龍堂","火龍堂"}));
	set("club_max_level",6);
	set("armor_prop/shield", 1);
	setup();
	set("volume",1);
}

int query_autoload() { return 1; } //save_item

void init()
{
 mapping info;
 int level;
 if(environment(this_object())!=this_player()) return;
 level=CLUB_D->check_member(CLUB_ID,getuid(this_player()));
 if(level==0)
 {
 	if(wizardp(this_player()))
 	{
 		 info = ([
		 "level": wiz_level(this_player()),
		 "title": "狂龍幫特級顧問",
		 "info1": "無",
		 "info2": ctime(time()),
		 "info3": ""
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(this_player()),info);
	}
	else 
	{
 		tell_object(this_player(),this_object()->name()+"突然從你身上飛出，漸漸消失在遠方。\n");
 		this_player()->delete("club");
 		destruct(this_object());
 		return;
 	}
 }
 switch(level)
 {
  case 6:
		add_action("do_handover","handover");
		add_action("do_lockleave","lockleave");
  case 5:
		add_action("no_suicide","suicide"); //防止自殺
  case 4:
		add_action("do_givepower","givepower");
		add_action("do_listmember","listmember");
  case 3:
  		add_action("do_accept","accept");
		add_action("do_kickout","kickout");
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 2:
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  default:
   		add_action("do_help","help");
   		add_action("do_about","about");
   		add_action("do_members","members");
   		add_action("do_leaveclub","leaveclub");
 }
}

int filter_members(object ppl,string *list)
{
        if( !environment(ppl) ) return 0;
        if( member_array(getuid(ppl),list)!=-1 ) return 1;
        return 0;
}

string show_level(object user)
{
 int level,rank;
 mapping info;
 string str;
 if(wizardp(user)) return "【榮譽會員】狂龍幫特級顧問  ";
 level=user->query("level");
 if(level>100) 	str = "【????????】";
 else if(level<11)	str = "【第 "+chinese_number(level)+" 級】";
 else if(level<21) 	str = "【第"+chinese_number(level)+"級】";
 else if(level%10==0)   str = "【第"+chinese_number(level)+"級】";
 else str = "【"+chinese_number(level)+"級】";
 info=CLUB_D->query_member_info(CLUB_ID,getuid(user));
 rank=info["level"];
 switch(rank)
 {
 	case 6: str+="狂龍幫龍頭老大  "; break;
 	case 5: str+="狂龍幫副幫主    "; break;
 	case 4: str+="狂龍幫長老      "; break;
 	case 3: str+="狂龍幫超級護法  "; break;
 	case 2: str+=info["info1"]+"分堂主    "; break;
 	default: 
 		if(info["info1"]!="無")
 		{
 			str+=info["info1"]+"堂員      "; break;
 		} else str+="狂龍幫一般幫眾  ";
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
	int lv1,lv2;
	lv1=CLUB_D->check_member(CLUB_ID,getuid(ob1));
	lv2=CLUB_D->check_member(CLUB_ID,getuid(ob2));
	if(lv1 == lv2) return (int)ob1->query("level") - (int)ob2->query("level");
	else return (lv1 - lv2);
}

int do_members(string arg)
{
	object *users,me;
	string str,*list;
	int i,ppl_cnt,idle;
	me=this_player();
//	list=CLUB_D->club_members(CLUB_ID);
//	users = filter_array( users(), "filter_members", this_object(),list );
	users = CLUB_D->find_online_members(CLUB_ID);
	str = "◎ "+CLUB_NAME+": \n";
	str += "─────────────────────────────────────\n";

	users = sort_array(users, "sort_member", this_object());

	ppl_cnt = 0;
	i = sizeof(users);
	while( i-- )
	{
			// Skip those users in login limbo.
			if(!me->visible(users[i]) && wizardp(users[i]) ) continue;
			str = sprintf("%s%12s%-16s %s(%s)",
				str,
				show_level(users[i]),
				RANK_D->query_level(users[i]),
				users[i]->name(1),
				users[i]->query("id"),
			);
			if(users[i]->query_temp("killer")) str+=HIR" [殺人犯]"NOR;
			idle=query_idle(users[i]);
			if(users[i]->query_temp("invis")) str+=HIB"(隱形)"NOR;
			if(users[i]->query_temp("hide")) str+=HBK"(躲藏)"NOR;
			if(users[i]->query_temp("netdead")) str+=HIG"<斷線中>"NOR;
			if(idle>60) str +=sprintf(HIY" (發呆%d分鐘)"NOR,idle/60);
			str +=sprintf("\n"NOR);
			ppl_cnt++;
	}
	str += "─────────────────────────────────────\n";
	str = sprintf("%s目前共有 %d 位成員在線上.\n", str, ppl_cnt);
	this_player()->start_more(str);
	return 1;
}

int do_include(string arg)
{
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("include <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
			if(me_info["level"] != 2 ) return notify_fail("只有分堂主能將幫眾收入分堂。\n");
			if(!stringp(sub=me_info["info1"])) return notify_fail("只有分堂主能將幫眾收入分堂。\n");
			if(ob_info["level"] != 1 || ob_info["info1"]!="無")
				return notify_fail("只有一般幫眾可以收入你的分堂。\n");
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N將$n收入"+sub+", 並拍拍$n的肩膀說: 今後就看你的表現了。\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_dismiss(string arg)
{
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("dismiss <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));		
		if(sizeof(ob_info))
		{
			if(!sub=me_info["info1"] || me_info["level"]!=2 ) return notify_fail("只有分堂主能免除堂員職務\n");
			if(ob_info["level"] != 1 ) return notify_fail("你不夠資格解除對方的職務。\n");
			if(ob_info["info1"] != sub) return notify_fail("對方並不屬於你的分堂。\n");
			ob_info["info1"]="無";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N解除了$n在"+sub+"的職務, 搖搖頭說: 又少了一個人才...真是可惜啊。\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}
//收人
int do_accept(string arg)
{
	string *clubs;
	object ob,mark,me;
	mapping info;
	me=this_player();
        if(!arg) return notify_fail("你要讓誰加入"+CLUB_NAME+"﹖\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("這裡有這個人嗎﹖\n");
	        if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");
		if(ob->query_temp("joinclub") != me->query("id") )
		{
			return notify_fail("對方並沒有向你申請入幫(joinclub).\n");
		}
		clubs=CLUB_D->find_player_club(getuid(ob));
		if(sizeof(clubs)>0)
		{
			if(clubs[0]==CLUB_ID) return notify_fail("對方已經是"+CLUB_NAME+"的一份子了。\n");
			else return notify_fail("對方已經加入了別的幫派。\n");
		}
		 else
		{
		 mark=new(base_name(this_object()));
		 if(!mark) return notify_fail("幫會信物取得失敗。\n");
		 if( !mark->can_move(ob) ) return notify_fail(ob->name(1)+"拿不動"+mark->query("name")+"。\n");
		 message_vision("$N給了$n一"+mark->query("unit")+mark->query("name")+", 並隆重的迎接$n成為"+CLUB_NAME+"的一份子。\n",me,ob);
		 info = ([
		 "level": 1,
		 "title": "狂龍幫一般幫眾",
		 "info1": "無",
		 "info2": ctime(time()),
		 "info3": me->name_id(1)
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
		 mark->move(ob);
		 ob->add("channels", ({"dragon"}));
		 ob->save();
		}
	}
	return 1;
}

int do_kickout(string arg)
{
	string *tuned_ch;
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("你要將誰踢出"+CLUB_NAME+"﹖\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob)
	        {
	        	if(!CLUB_D->is_club_leader(me))	return notify_fail("這裡有這個人嗎﹖\n");
	        	else {
	        		write("[離線開除]:");
	        		if(ob=find_player(arg)) return notify_fail("對方還在線上。\n");
	        		if( CLUB_D->remove_member(CLUB_ID,arg) )
	        		{
	        			write("成功\開除了"+arg+"。\n");
	        			return 1;
	        		}
	        		else return 0;
	        	}
	        }
	        if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");
				
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"])
				return notify_fail("你不夠資格將對方踢出"+CLUB_NAME+"。\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
				return notify_fail("你不夠資格將對方踢出"+CLUB_NAME+"。\n");
			tuned_ch = ob->query("channels");
			if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
			{
				tuned_ch -= ({ CLUB_CHANNEL });
				ob->set("channels", tuned_ch);
			}
			//ob->delete("club");
			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
 				message_vision("$N沒收了$n的"+mark->query("name")+", 並強制$n退出"+CLUB_NAME+"。\n",me,ob);
 				destruct(mark);
 			}
 			CLUB_D->remove_member(CLUB_ID,getuid(ob));
 			ob->save();
 			return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_subleader(string arg)
{
	string id,sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("subleader <人名> to <分堂名>\n");
        else
        {
        	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <人名> to <分堂名>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 1)
				return notify_fail("只有一般幫眾可以成為分堂主。\n");
			if( (int) member_array(sub, query("sub_club"))<0 )
				return notify_fail("目前可用的分隊為 <神龍堂> <狂龍堂> <猛龍堂> <火龍堂> \n");
			ob_info["level"]=2;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
	 			message_vision("$N將$n提昇為"+sub+"分堂主, 並和$n握手勉勵一番。\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_retire(string arg)
{
	string sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("retire <人名> \n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me) return notify_fail("這裡有這個人嗎﹖\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 2) return notify_fail("對象並不是分堂主。\n");
			sub=ob_info["info1"];

			ob_info["level"]=1;
			ob_info["info1"]="無";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);

			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
	 			message_vision("$N免除了$n的"+sub+"分堂主職務。\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_givepower(string arg)
{
	string id,type,res;
	int level;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("givepower <人名> to <等級>\n");
        else
        {
        	if( sscanf(arg, "%s to %d", id, level)!=2 ) return notify_fail("givepower <人名> to <等級>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me) return notify_fail("這裡有這個人嗎﹖\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"]) return notify_fail("你沒有資格改變對方的職務等級。\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
					return notify_fail("你沒有資格改變對方的職務等級。\n");
			if(level >= me_info["level"])
				return notify_fail("你沒有資格提昇對方的職務等級到這個等級。\n");
			if(level == ob_info["level"])
				return notify_fail("對方已經是"+(string)members_level[level]+"了。\n");
			if(level > 5 || level < 1 )
				return notify_fail("目前等級分為 <1:幫眾> <2:堂主> <3:護法> <4:長老> <5:副幫主> <6:幫主> \n");
			if( level > ob_info["level"] )
			{
				type="提昇";
				res ="並和$n握手勉勵一番";
			}
			else
			{
				type = "降";
				res ="並拍拍$n的肩膀期勉$n能將功\折罪";
			}
			switch(level)
			{
				case 1:
					ob_info["level"]=1;
					ob_info["info1"]="無";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 2:
					return notify_fail("請用subleader指令來指定一個分旗。\n");
					break;
				case 3:
					ob_info["level"]=3;
					ob_info["info1"]="無";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 4:
					ob_info["level"]=4;
					ob_info["info1"]="無";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 5:
					ob_info["level"]=5;
					ob_info["info1"]="無";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 6:
					return notify_fail("請用handover指令做指揮權移交。\n");
					break;
				default: return notify_fail("參數錯誤。\n");
				
			}
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
				message_vision("$N將$n的職位等級"+type+"為"+(string)members_level[level]+"(等級"+(string)level+"), "+res+"。\n",me,ob);
				mark->move(ob);
			}
			ob->save();
			return 1;
		}
		 else return notify_fail("對方並沒有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_handover(string arg)
{
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
        if(!arg) return notify_fail("你要將大權移交給誰﹖\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me) return notify_fail("這裡有這個人嗎﹖\n");
		
		if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(me)) return notify_fail("你不是真正的幫會領導人。\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
		 	CLUB_D->set_club_leader(CLUB_ID,getuid(ob));
		 	
		 	ob_info["level"]=6;
		 	ob_info["info1"]="無";
		 	ob_info["info2"]=ctime(time());
		 	ob_info["info3"]=me->name_id(1);
		 	CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			
			me_info["level"]=4;
		 	me_info["info1"]="無";
		 	me_info["info2"]=ctime(time());
		 	me_info["info3"]=me->name_id(1);
			CLUB_D->set_member(CLUB_ID,getuid(me),me_info);
		 	
		 	mark=present(CLUB_MARK, me);
		 	if(!mark)
		 	{
		 		write("幫會信物取得失敗。\n");
			}
			else
			{
				mark->move(me);
			}
			mark=present(CLUB_MARK, ob);
		 	if(!mark)
		 	{
		 		write("幫會信物取得失敗。\n");
			}
			else
			{
				mark->move(ob);
			}
			message_vision("$N將"+CLUB_NAME+"的總指揮權移交給$n。\n",me,ob);
			message( "channel:dragon",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")將"+CLUB_NAME+"指揮權移交給"+ob->name(1)+"("+capitalize(ob->query("id"))+")。\n"NOR, users() );
			ob->save();
			me->save();
			return 1;
		}
		 else return notify_fail("對方並不是"+CLUB_NAME+"的一份子。\n");
	}
	return 1;
}

int do_leaveclub(string arg)
{
	string *tuned_ch;
	object mark,me;
	me=this_player();
	
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(me))
		return notify_fail("你必須先將大權轉移才能離開"+CLUB_NAME+"。\n");
	CLUB_D->remove_member(CLUB_ID,getuid(me));
	message_vision("$N主動退出了"+CLUB_NAME+"。\n",me);
	message( "channel:dragon",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")主動退出了"+CLUB_NAME+"。\n"NOR, users() );
	tuned_ch = me->query("channels");
	if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
	{
			tuned_ch -= ({ CLUB_CHANNEL });
			me->set("channels", tuned_ch);
	}
	me->delete("club");
	if(!mark=present(CLUB_MARK,me))
	{
		write("幫會信物取得失敗。\n");
	} else destruct(mark);
	me->save();
	return 1;
}
int do_lockleave(string arg)
{
	if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(this_player())) return notify_fail("你不是真正的幫會領導人。\n");
	if(arg=="on")
	{
		if(CLUB_D->query_lockleave(CLUB_ID)==1) return notify_fail("退幫限制已經開啟。\n");
		CLUB_D->set_lockleave(CLUB_ID,1);
		write("你將"+CLUB_NAME+"設定為不可退幫。\n");
		return 1;
	}
	if(arg=="off")
	{
		if(CLUB_D->query_lockleave(CLUB_ID)==0) return notify_fail("退幫限制已經關閉。\n");
		CLUB_D->set_lockleave(CLUB_ID,0);
		write("你將"+CLUB_NAME+"設定為可以退幫。\n");
		return 1;
	}
	return notify_fail("lockleave <on/off> \n");
}
int no_suicide(string arg)
{
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(this_player()))
	{
		write("身為"+CLUB_NAME+"高級長官, 交出指揮權之前不可輕生, 以免後繼無人。\n");
		return 1;
	}
	return 0;
}

int do_listmember(string arg)
{
	string *list,*members,temp,output;
	int i,j;
	mapping club;
	list=CLUB_D->club_members(CLUB_ID);
	club=CLUB_D->query_club_record(CLUB_ID);
	members=keys(club);
	output="\n目前"+CLUB_NAME+"登記有案的成員有:\n";
	if(arg=="long")
	{
		for(i=this_object()->query("club_max_level");i>0;i--)
		{
			for(j=0;j<sizeof(members);j++)
			{
				if(club[members[j]]["level"]==i) output=sprintf("%s %12s 幫會等級: %d\n",output,members[j],i);
			}
		}
		output=sprintf("%s \n目前%s共計有: %d 名成員。\n",output,CLUB_NAME,sizeof(members));
		write(output);
		return 1;
	}
	temp=CLUB_D->query_club_leader(CLUB_ID);
	output=sprintf("%s 領導人: %12s\n",output,temp);
	list-=({temp});
	output=sprintf("%s 其他:\n",output,temp);
	output+=CLUB_D->show_club_members(CLUB_ID);
	output=sprintf("%s目前%s共計有: %d 名成員。\n",output,CLUB_NAME,sizeof(members));
	write(output);
	return 1;
}


int do_help(string arg)
{
 if(arg=="dragon")
 {
  write(@HELP

       �翦�����������������������������������������������������������������
       │                      幫會信物的輔助說明                        │
       ├───────────────┬─────────┬──────┤
       │  指令格式                    │說明              │權限        │
       ├───────────────┼─────────┼──────┤
       │  help plate                  │本輔助訊息        │幫眾        │
       │  dragon <你的訊息>           │幫會專用頻道      │幫眾        │
       │  members                     │列出線上幫會成員  │幫眾        │
       │  leaveclub                   │主動退出幫會      │幫眾        │
       │  include <人名>              │將某人收入分堂    │堂主專用    │
       │  dismiss <人名>              │取消某人分堂職務  │堂主專用    │
       │  accept <人名>               │讓某人加入幫會    │護法以上    │
       │  kickout <人名>              │將某人逐出幫會    │護法以上    │
       │  subleader <人名> to <分堂名>│升級某人為分堂主  │護法以上    │
       │  retire <人名>               │撤除某人分堂主職位│護法以上    │
       │  givepower <人名> to <等級>  │改變某人的職位    │長老以上    │
       │  lockleave <on> <off>        │限制自行退幫      │幫主        │
       │  handover <人名>             │掌門職務交接      │幫主        │
       │  listmember                  │幫會名冊          │長老以上    │
       └───────────────┴─────────┴──────┘
	 ◎ 使用 accept 指令必須對方先用 joinclub 指令申請才能生效。
         ◎ 狂龍幫目前有四個分堂: 【神龍堂】、【狂龍堂】、【猛龍堂】、【火龍堂】。
         ◎ 等級分為: <1:幫眾> <2:堂主> <3:護法> <4:長老> <5:副幫主> <6:幫主>。

HELP
  );
  return 1;
 }
 return 0;
}
int do_about(string arg)
{
 if(arg=="dragon")
 {
  write(@ABOUT
●狂龍幫信物－狂龍令

    話說神話時代，九天之外有一月之石墜入了凡間，導致當時在凡
  間非常興盛的龍族遭到毀滅。

    光陰似箭，日月如疏....

    而在此災難之後，經過時間的磨練....人類憑著天賦的本能慢慢
  地成長．而神話時代的故事，還間接流傳在這個世界．

    其中一個最令江故人士聞之心動的，就是神話時代曾興盛一時，
  龍族族人的《龍牙》而這寶物相傳不是普通龍族族人之牙，而是他
  們皇者之牙．傳聞說，龍的牙具有很大的靈气，而最內部的牙更藏
  有太古之力，能令人功力大增但用法就不得而知了...

    相傳當龍族毀滅時，月之石所帶來的沖擊，引起大量熱能，令大
  部分龍族人的骸骨灰飛煙滅，但其中有一小部分龍族族人，因預知
  了月之石將會墜落，所以在墜落前到達地底，想避開這場災難..不
  幸地，月之石的力量太厲害了，致令他們也被月之石所帶來的沖擊
  殺死，所不同的是，地面那地獄般熱力傳不到地底，令其骸骨得以
  保存而傳聞當時這批龍族的地下避難所，就是現今西方的地下大墓
  園了．所以，江湖上有許多奇能異士都想得到這寶物，但到達地下
  大墓園的人，都只有進入，從沒有人能生還著回來..
  
    好事之徒就說�媄鉿陬蛜媞婻鬊�..也有人說是咀咒..所以令大墓
  園這一帶沒人敢接近..而這個傳說亦一代，一代的流傳下去....

    本幫幫主志狼(ttoopp), 在孩童時代已經練就一身好功夫．他在
  小時就常聽長輩說故事, 當他聽到這故事是，就被它吸引了當志狼
  長大成人, 他就急不及待去地下大墓園探險..他..不理會父母的反
  對..昂然踏進他人身的轉折點，後來..江湖傳聞..有一名年青俠士
  ，戴著由《龍牙》鑲成的項鍊，領導各方奇能異士，組成江湖上鼎
  鼎大名，令江湖上黑道聞之喪膽的【狂龍幫】
  
    莫非，志狼(ttoopp)真的成功拿到《龍牙》？
    
    他如何拿的到？那又是另一個故事了...

ABOUT
  );
  return 1;
 }
 return 0;
}
