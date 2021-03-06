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
// 大草原 - /open/world1/acme/area/lea3
//燕赤霞說﹕ 可以在這個房間的long 加上你發現這裡的天空有一比平常大的月亮?? :P
// 【閒聊】燕赤霞(Jawei)﹕族長 副族長 長老 旗主 族人
// 【閒聊】龍蝦(Luky)﹕長老以上或是旗主以上
// 【閒聊】燕赤霞(Jawei)﹕幹部我希望是都只有族長能升降...
// 新月 滿月 闇月 半月

#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "月族"
#define CLUB_ID "moon"
#define CLUB_CHANNEL "moon"
#define CLUB_MARK "ring of moon-soul"
#define CLUB_ENTER_FILE "/open/world1/acme/area/moon/room1"
#define CLUB_OUT_FILE "/open/world1/acme/area/lea3"
inherit FINGER;
private string *members_level = ({
	"族客", //0
	"族人", //1
	"旗主", //2
	"長老", //3
	"副族長", //4
	"族長", //5
});
void create()
{
	set_name(HIC"月魂之戒"NOR,({"ring of moon-soul","ring","club_mark"}));
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",0);
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","只");
		set("long",@LONG
	
相傳在神話時代，有一枚月亮的碎片墜入了凡間，導致了當時在
凡間相當興盛的龍族遭到毀滅。首任族長燕赤霞(Jawei) 在其年
少闖蕩江湖之時，一日不經意的發現了碎片的存在，於是遍尋巧
匠打造了這枚雪白晶瑩的月魂之戒，藉由它的神秘力量可以使佩
帶之人來到月族的根據地--廣寒宮。

[關於月族的其他說明請用<help moon>指令查詢。]
LONG
		);
	}
	set("club_id",CLUB_ID);
	set("club",CLUB_NAME);
	set("sub_club",({"新月旗","滿月旗","闇月旗","半月旗"}));
	set("club_max_level",sizeof(members_level)-1);
	set("armor_prop/shield", 1);
	setup();
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
		 "title": "月族特級顧問  ",
		 "info1": "無",
		 "info2": ctime(time()),
		 "info3": this_player()->name_id(1)
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
  case 5:
		add_action("do_handover","handover");
		add_action("do_lockleave","lockleave");
		add_action("do_givepower","givepower");
		add_action("no_suicide","suicide"); //防止自殺
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 4:
  		add_action("do_listmember","listmember");
  case 3:
  		add_action("do_accept","accept");
		add_action("do_kickout","kickout");
  case 2:
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  default:
   		add_action("do_help","help");
   		add_action("do_members","members");
   		add_action("do_leaveclub","leaveclub");
   		add_action("do_enter_club","lift");
 }
}

int do_enter_club(string arg)
{
	object env,me;
	if(arg!="ring") return 0;
	me=this_player();
	env=environment(me);
	if(!env) return 0;
	if(env->query("moon_club_enter"))
	{
		if(me->query_temp("killer")) return notify_fail("天上傳來一個幽幽的聲音: 你, 因為你剛剛殺了人所以暫時不能進入幫會。\n");;
	if(me->query_temp("invader")) return notify_fail("天上傳來一個幽幽的聲音: 因為你剛剛傷了人, 所以暫時不能進入幫會。\n");
		message_vision("$N將$n舉向空中，突然$N被一陣光芒包圍了。\n",me,this_object());
		if(!me->can_move(CLUB_ENTER_FILE))
		{
			message_vision("光芒漸漸消失了，只見$N不知所措的呆站在原地。\n",me);
			return 1;
		}
		else
		{
			tell_room(env,me->name()+"突然隨著光芒消失了。\n",({ me }));
			me->move(CLUB_ENTER_FILE);
			tell_room(environment(me),me->name()+"突然出現在一陣光芒之中。\n",({ me }));
			write("在光芒散去之後，你發現自己已經來到了廣寒宮的門口。\n");
			me->add_busy(1);
			return 1;
		}
	}
	else if(env->query("moon_club_out"))
	{
		message_vision("$N將$n舉向空中，突然$N被一陣光芒包圍了。\n",me,this_object());
		if(!me->can_move(CLUB_OUT_FILE))
		{
			message_vision("光芒漸漸消失了，只見$N不知所措的呆站在原地。\n",me);
			return 1;
		}
		else
		{
			tell_room(env,me->name()+"突然隨著光芒消失了。\n",({ me }));
			me->move(CLUB_OUT_FILE);
			tell_room(environment(me),me->name()+"突然出現在一陣光芒之中。\n",({ me }));
			write("在光芒散去之後，你發現自己又回到了"+environment(me)->query("short")+"。\n");
			me->add_busy(1);
			return 1;
		}
	}
	else return notify_fail("你將"+this_object()->name()+"高高舉起，但是什麼事情都沒發生。\n");
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
 if(wizardp(user)) return "【榮譽會員】月族特級顧問    ";
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
 	case 5: str+="月之一族大族長  "; break;
 	case 4: str+="月之一族副族長  "; break;
 	case 3: str+="月之一族長老    "; break;
  	case 2: str+=info["info1"]+"旗主      "; break;
 	default: 
 		if(info["info1"]!="無")
 		{
 			str+="月族"+info["info1"]+"成員  "; break;
 		} else str+="月之一族族人    ";
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
//	users = filter_array( users(), "filter_members", this_object() ,list);
	users = CLUB_D->find_online_members(CLUB_ID);
	str = "◎ "+CLUB_NAME+": \n";
	str += "─────────────────────────────────────\n";

	users = sort_array(users, "sort_member", this_object());

	ppl_cnt = 0;
	i = sizeof(users);
	while( i-- )
	{
			// Skip those users in login limbo.
			if(!me->visible(users[i]) && wizardp(users[i])) continue;
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
			if(me_info["level"] != 2 ) return notify_fail("只有旗主能將族人收入分旗。\n");
			if(!stringp(sub=me_info["info1"])) return notify_fail("只有旗主能將族人收入分旗。\n");
			if(ob_info["level"] != 1 || ob_info["info1"]!="無")
				return notify_fail("只有一般族人可以收入你的分堂。\n");
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
			if(!sub=me_info["info1"] || me_info["level"]!=2 ) return notify_fail("只有旗主能免除旗下成員職務。\n");
			if(ob_info["level"] != 1 ) return notify_fail("對方並不屬於你的旗下。\n");
			if(ob_info["info1"] != sub) return notify_fail("對方並不屬於你的旗下。\n");
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
		 ob->add("channels", ({"moon"}));
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
	
        if(!arg) return notify_fail("subleader <人名> to <分旗名>\n");
        else
        {
        	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <人名> to <分旗名>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 1)
				return notify_fail("只有一般族人可以成為旗主。\n");
			if( (int) member_array(sub, query("sub_club"))<0 )
				return notify_fail("目前可用的分旗為【新月旗】、【滿月旗】、【闇月旗】、【半月旗】。\n");
			ob_info["level"]=2;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
	 			message_vision("$N將$n提昇為"+sub+"旗主, 並和$n握手勉勵一番。\n",me,ob);
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
			if(ob_info["level"] != 2) return notify_fail("對象並不是旗主。\n");
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
	 			message_vision("$N免除了$n的"+sub+"旗主職務。\n",me,ob);
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
				return notify_fail("目前等級分為 <1:族人> <2:旗主> <3:長老> <4:副族長> <5:族長> \n");
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
		 	
		 	ob_info["level"]=5;
		 	ob_info["info1"]="無";
		 	ob_info["info2"]=ctime(time());
		 	ob_info["info3"]=me->name_id(1);
		 	CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			
			me_info["level"]=3;
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
			message( "channel:moon",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")將"+CLUB_NAME+"指揮權移交給"+ob->name(1)+"("+capitalize(ob->query("id"))+")。\n"NOR, users() );
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
	message( "channel:moon",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")主動退出了"+CLUB_NAME+"。\n"NOR, users() );
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
 if(arg=="moon")
 {
  write(@HELP

       �翦�����������������������������������������������������������������
       │                      幫會信物的輔助說明                        │
       ├───────────────┬─────────┬──────┤
       │  指令格式                    │說明              │權限        │
       ├───────────────┼─────────┼──────┤
       │  help moon                   │本輔助訊息        │族人        │
       │  moon <你的訊息>             │幫會專用頻道      │族人        │
       │  members                     │列出線上幫會成員  │族人        │
       │  leaveclub                   │主動退出幫會      │族人        │
       │  include <人名>              │將某人收入分旗    │旗主專用    │
       │  dismiss <人名>              │取消某人分旗職務  │旗主專用    │
       │  accept <人名>               │讓某人加入幫會    │長老以上    │
       │  kickout <人名>              │將某人逐出幫會    │長老以上    │
       │  lockleave <on> <off>        │限制自行退幫      │族長        │
       │  subleader <人名> to <分堂名>│升級某人為旗主    │族長        │
       │  retire <人名>               │撤除某人旗主職位  │族長        │
       │  givepower <人名> to <等級>  │改變某人的職位    │族長        │
       │  handover <人名>             │掌門職務交接      │族長        │
       │  listmember                  │幫會名冊          │長老以上    │
       └───────────────┴─────────┴──────┘
	 ◎ 使用 accept 指令必須對方先用 joinclub 指令申請才能生效。
         ◎ 月族目前有四個分旗:【新月旗】、【滿月旗】、【闇月旗】、【半月旗】。
         ◎ 等級分為: <1:族人> <2:旗主> <3:長老> <4:副族長> <5:族長> 。
         ◎ 其他月族的事務: <help moon_rule> , <help moon_group> 。
     	
HELP
  );
  return 1;
  }
  if(arg=="moon_rule")
  {
   this_player()->start_more(@RULE
 ●月族三大戒律                           

一、  嚴格禁止跨幫

      本族族人所擁有之CHAR鼓勵但不強制必須全部加入本族，但是嚴格禁
      止有CHAR加入其他幫派。
      同時也禁止將月族的CHAR借給他人使用。要把CHAR送給他人時，必須
      POST在MOON BOARD公告之，由長老以上逐出本族之後始可送給他人。
      若受贈者為本族族人，則只需POST公告之即可。
      另外禁止任意脫離月族，要脫離時必須POST在MOON BOARD經幹部會議
      通過准許，始可離族。
      違反上述規定者，將逐出族，並視情況決定是否加以通緝。

二、  嚴格禁止主動PK其他玩家
 
      本族族人禁止PK其他玩家，但遭本族通緝者以及PK我族人之現行犯不
      在禁止之列。
      所謂PK我族之現行犯為我族人遭受PK時，線上有幹部為證人，將情況
      POST在MOON BOARD，POST內容必須包括PKER ID、被PK者 ID，則即刻
      將PKER列入通緝名單，我族人皆可除之。若被PK時，無幹部可為之作
      證，則由被PK者自行POST過程，事後經長老以上查證，亦將PKER列入
      通緝名單。

      除遭受PK以外，本族族人與他人的其他糾紛，必須POST在CHAT BOARD
      由幹部會議決定處理方法，不可自行PK對方。
      違反上述規定者，將逐出本族，並視情況決定是否加以通緝。 
      
三、  禁止盜賣本族裝備

      放置於幫會內之裝備為全族人所共有，不得私自加以變賣。族人可任意
      加以取用，但必須於離線前放回原位。
      但在WIZ宣佈REBOOT TIME之後，則不禁止變賣裝備。
      私自變賣裝備者，將逐出本族並予以通緝。      
      放置裝備時，必須依照類別正確放置。若有緊急事情需馬上離線，則必
      須託一族人代為整理。違反本條規定者，將罰整理裝備一個星期，累犯
      屢勸不聽者則由幹部會議另行決定處分。


      以上為我月族之三大戒律，望全族族人嚴格遵守。


  欲入我月族之人，需向月族長老以上提出申請。
  必須有長老以上一名，旗主兩名同意或長老以上兩名同意。
  並需尋得我族人一名擔任保證人，始得以入本月族。
  入本族一個月內若有犯錯，則保證人連帶遭受處份。
  同一族人在同一時間內只可為一人擔任保證人。
  被保證人在一個月內不得為他人之保證人，並不得申請加入其他ID。

  加入之後需至MOON BOARD POST一篇加入聲明包括：
  加入者ID
  同意之幹部ID
  收你入族者之幹部ID
  保證人ID
  及自我介紹

  並需閱讀族內中之POST，熟悉本族規定。


                              	月族族長 燕赤霞(jawei)(Fri Oct 15)
   
RULE
);
return 1;
  }
  if(arg=="moon_group")
  {
  this_player()->start_more(@MOON_PART

●月族四旗的分工                         
 
一、  新月旗：
      主要負責族內的事務。包括整理族人名單、對族人犯錯處分之監督執行、
      教導新人等等。

二、  闇月旗：
      主要負責對外的事物。包括整理通緝名單、執行通緝任務、為族人解決對
      外糾紛等等。

三、  滿月旗：
      主要負責資料的收集。包括研究任務解法、繪製地圖、整理族內重要之公
      告、研究各公會特性與練功方法等等。 

四、  半月旗
      主要負責族內的裝備。包括收集各種裝備、研究裝備的特性與限制、研究
      MOB 的特性、整理族內裝備等等。


  本族的所有族人，除幹部以外必須從以上四旗選擇一旗加入。
  請族人慎重考慮之後再加入，因為將來所有入族之ID必須加入同一個旗。
  也就是同一個人的所有CHAR必須加入同一旗，這是為了分工的目的。
  如果後來想換旗，必須徵得原旗主與想加入的那旗旗主的同意，
  並且要一次把所有CHAR都換旗才行。
  旗主在收人入旗後，必須在MOON BOARD公告，並自行整理各旗名單，
  定期把名單給新月旗做統整。
  另外，將來下一任的各旗主，將規定由各旗之中分別挑選。


                                                           月族族長  燕赤霞

MOON_PART
);
  return 1;	
 }
 return 0;
}
