// 神族幫會信物
// "level": 玩家在幫會中的等級(1~?)
// 1: 一般幫眾 
// 2: 護法 
// 3: 堂主 
// 4: 長老 
// 5: 副聖主 (限1名)
// 6: 聖主 (限1名)
// "title": 幫會頭銜
// "info1": 備用區1 (分堂名稱)
// "info2": 備用區2
// "info3": 備用區3
// 【好友】西門吹雪(Aoo)﹕
// 聖主:無上聖主
// 副聖主:創世創神
// 第三職稱:四界神王
// 第四職稱:神魔上人
// 第五職稱:伏魔神使
// 第六職稱:降世神族
// 親愛ㄉ小豬, 聖主 創神 天神 魔神 神使 天兵 <--

#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "神族"
#define CLUB_ID "god"
#define CLUB_CHANNEL "god"
#define CLUB_MARK "god crown"
#define CLUB_ENTER_FILE "/open/world1/god_club/entrance"
#define CLUB_OUT_FILE "/open/world1/cominging/area/survey"
#define SUB_UNIT "界"
#define SUB_LEADER "界神"
#define CLUB_UNIT "族人"
inherit HEAD;

private string *members_level = ({
  "天兵", // 0
  "神使", // 1
  "魔神", // 2
  "天神", // 3
  "創神", // 4
  "聖主", // 5
});

void create()
{
	set_name(HIY"桂冠"NOR,({"god crown", "crown", "club_mark"}));
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else {
		set("material","steel");
		set("club_id",CLUB_ID);
		set("club",CLUB_NAME);
		set("sub_club",({ "天界", "仙界", "冥界", "魔界" }));
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","頂");
		set("long",@LONG

這是由月桂樹樹葉編織成的頭冠，只有心地純潔的人才能擁有，具有
神秘的除魔力量。此桂冠乃神族信物，表凡我神族子民需肩負著維持
和平的重責大任。
聽說回族內的方法，是在步靈城中心的樓上，對著桂冠說出神奇的話
(miracle crown)，似乎就可以回到族內了？！

[關於神族的其他說明請用<help god>指令查詢。]
LONG
		);
		set("value",0);
		set("club_max_level",sizeof(members_level)-1);
		set("armor_prop/shield", 1);
                set("wear_msg", HIC"$N套上$n"HIC"之後面泛紅光，充滿了春意，彷彿在跟大家說：「我戀愛了！」\n"NOR);
                set("unequip_msg", HIC"$N卸下$n"HIC"後，$N覺得世界真是美好，每樣東西都值得妳擁抱。\n"NOR);
	}
	setup();
}

int query_autoload() { return 1; } //save_item

void init()
{
 mapping info;
 int level;
 if(environment(this_object())!=this_player()) return;
 level=CLUB_D->check_member(CLUB_ID, getuid(this_player()));
 if(level==0)
 {
	if(wizardp(this_player()))
	{
		 info = ([
		 "level": wiz_level(this_player()),
		 "title": CLUB_NAME+"特級顧問",
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
  case 6:
		add_action("do_handover","handover");
		add_action("do_lockleave","lockleave");
		add_action("no_suicide","suicide"); //防止自殺
		add_action("do_kickout","kickout");
  case 5:
		add_action("do_givepower","givepower");
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 4:
                add_action("do_leaveclub","leaveclub");
 		add_action("do_accept","accept");
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  case 3:
                add_action("do_listmember","listmember");
  default:
  		add_action("do_help","help");
  		add_action("do_members","members");
  		add_action("do_enter_club","miracle");
 }
}

int do_enter_club(string arg)
{
	object env,me;
	me=this_player();
	env=environment(me);
	if( !env || arg != "crown" ) return 0;
	if( me->is_busy() ) return notify_fail("你還在忙喔。\n");
	if( env->query("god_club_enter") )
	{
		if(me->query_temp("killer")) return notify_fail("天上傳來一個幽幽的聲音: 你, 因為你剛剛殺了人所以暫時不能進入幫會。\n");;
		if(me->query_temp("invader")) return notify_fail("天上傳來一個幽幽的聲音: 因為你剛剛傷了人, 所以暫時不能進入幫會。\n");
		message_vision("$N大聲的對$n說道：我的老天爺啊！這實在是太神奇了！！。\n",me,this_object());
		if(!me->can_move(CLUB_ENTER_FILE))
		{
			message_vision("$n突然覺得好冷。\n", me, this_object());
			return 1;
		}
		else
		{
			message_vision("$n"HIG"對著$N大喊：哇 勒！..你是 豕者 豆頁 喔？....\n", me, this_object());
			message_vision(HIM"只見$n"HIM"抖地發出極大的聲響，$N快速地往上竄升。\n"NOR, me, this_object());
			me->move(CLUB_ENTER_FILE);
			message_vision("$N隨著光芒上升至此處。\n", me);
//me->add_busy(1)
			return 1;
		}
	}
	else if(env->query("god_club_out"))
	{
		message_vision("$n附在$N的耳邊大聲地說的對著$N說：「"HIG"死老百姓，混。還不快讀書，等下被當又要跑回家偷哭了厚∼"NOR"」。\n",me,this_object());
		if(!me->can_move(CLUB_OUT_FILE))
		{
			message_vision("$n突然覺得好冷。\n", me, this_object());
			return 1;
		}
		else
		{
			message_vision("$N"NOR+RED"的光芒突然似被吞噬一般，彈指間化成了暗金色..。\n", this_object());
			write(HIY" 你已重入了滾滾紅塵...。 \n"NOR);
			me->move(CLUB_OUT_FILE);
			if( objectp(present("wandering geisha", load_object(CLUB_OUT_FILE))) )
				message_vision("$N突然跌落在青樓女子的身旁，她趕緊將$N給扶了起來..。\n", me);
			else
			{
message_vision("$N倏地從天而墜，在落地之時瞬間點地而起，毫髮無傷。\n", me);


//更改成沒有青樓女子也不會busy
//me->add_busy(1);
//這是因神族人反應才改的
//2003.8.20 by Iamtheking
			}
			return 1;
		}
	}
	else {
		message_vision("$n突然覺得好冷。\n", me, this_object());
		return 1;
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
 if(wizardp(user)) return "【榮譽會員】"+CLUB_NAME+"特級顧問  ";
 level=user->query("level");
 if(level>100)	str = "【????????】";
 else if(level<11)	str = "【第 "+chinese_number(level)+" 級】";
 else if(level<21)	str = "【第"+chinese_number(level)+"級】";
 else if(level%10==0)   str = "【第"+chinese_number(level)+"級】";
 else str = "【"+chinese_number(level)+"級】";
 info=CLUB_D->query_member_info(CLUB_ID,getuid(user));
 rank=info["level"];

 switch(rank)
 {
	case 6: str+="神族之無上聖主　"; break;
	case 5: str+="神族之創世聖神　"; break;
	case 4: str+="神族之四界神王　"; break;
	default:
	{
		if(info["info1"]!="無")
			str+= info["info1"];
		else str+="神族";
		switch(rank)
		{
			case 3:
				str+="之神魔上人　"; break;
			case 2:
				str+="之伏魔神使　"; break;
			default:
				str+="之降世神族　"; break;
		}
	}
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
	int lv1,lv2;
	lv1=CLUB_D->check_member(CLUB_ID,getuid(ob1));
	lv2=CLUB_D->check_member(CLUB_ID,getuid(ob2));
        if(lv1 == lv2) return (int)ob1->query("level") - (int)ob2->query("level");
            else return (lv1-lv2);
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
                        if(me_info["level"] != 4 ) return notify_fail("只有"SUB_LEADER"能將"CLUB_UNIT"收入"SUB_UNIT"。\n"); //應該是4吧..add by whoami
			if(!stringp(sub=me_info["info1"])) return notify_fail("只有"SUB_LEADER"能將"CLUB_UNIT"收入"SUB_UNIT"。\n");
			if(ob_info["level"] != 1 || ob_info["info1"]!="無")
				return notify_fail("只有一般"CLUB_UNIT"可以收入你的"SUB_UNIT"。\n");
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
			if(!sub=me_info["info1"] || me_info["level"] != 4 ) return notify_fail("只有"+SUB_LEADER+"能免除"SUB_UNIT"員職務\n");
			if(ob_info["level"] > 3) return notify_fail("你不夠資格解除對方的職務。\n");
			if(ob_info["info1"] != sub) return notify_fail("對方並不屬於你的"+SUB_UNIT+"。\n");
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
		 if( !mark) return notify_fail("幫會信物取得失敗。\n");
		 if( !mark->can_move(ob) ) return notify_fail(ob->name(1)+"拿不動"+mark->query("name")+"。\n");
		 message_vision("$N給了$n一"+mark->query("unit")+mark->query("name")+", 並隆重的迎接$n成為"+CLUB_NAME+"的一份子。\n",me,ob);
		 info = ([
		 "level": 1,
		 "title": "神族之降世神族  ",
		 "info1": "無",
		 "info2": ctime(time()),
		 "info3": me->name_id(1)
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
		 mark->move(ob);
		 ob->add("channels", ({"god"}));
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
	
        if(!arg) return notify_fail("subleader <人名> to <"SUB_UNIT"名>\n");
        else
        {
       	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <人名> to <"SUB_UNIT"名>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("這裡有這個人嗎﹖\n");
		if(!userp(ob) || ob==me ) return notify_fail("這裡有這個人嗎﹖\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 3)
				return notify_fail("只有魔神才可以成為"SUB_LEADER"。\n");
			if( (int) member_array(sub, query("sub_club"))<0 )
				return notify_fail("目前可用的分界為 <天界> <仙界> <冥界> <魔界>。\n");
			ob_info["level"]=4;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
				message_vision("$N將$n提昇為"+sub+SUB_LEADER+", 並和$n握手勉勵一番。\n",me,ob);
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
			if(ob_info["level"] != 4) return notify_fail("對象並不是"SUB_LEADER"。\n");
			sub=ob_info["info1"];

			ob_info["level"]=3;
			ob_info["info1"]="無";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);

			if(!mark=present(CLUB_MARK,ob))
			{
				write("幫會信物取得失敗。\n");
			}
			else
			{
				message_vision("$N免除了$n的"+sub+SUB_LEADER+"職務。\n",me,ob);
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
				return notify_fail("對方已經是"+(string)members_level[level-1]+"了。\n");
			if(level > 5 || level < 1 )
				return notify_fail("目前等級分為 <1.天兵> <2:神使> <3.魔神> <4.天神> <5.創神> <6.聖主> \n");
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
					ob_info["level"]=2;
					ob_info["info1"]="無";
					ob_info["info2"]=ctime(time());
					ob_info["info3"]=me->name_id(1);
					break;
				case 3:
					ob_info["level"]=3;
					ob_info["info1"]="無";
					ob_info["info2"]=ctime(time());
					ob_info["info3"]=me->name_id(1);
					break;
				case 4:
					return notify_fail("請用subleader指令來指定一個分界。\n");
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
				message_vision("$N將$n的職位等級"+type+"為"+(string)members_level[level-1]+"(等級"+(string)level+"), "+res+"。\n",me,ob);
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
			message( "channel:god",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")將"+CLUB_NAME+"指揮權移交給"+ob->name(1)+"("+capitalize(ob->query("id"))+")。\n"NOR, users() );
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
	if(CLUB_D->query_lockleave(CLUB_ID)==1)
		return notify_fail("聖主有旨: 現在無法自行退幫！\n");
	CLUB_D->remove_member(CLUB_ID,getuid(me));
	message_vision("$N主動退出了"+CLUB_NAME+"。\n",me);
	message( "channel:god",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")主動退出了"+CLUB_NAME+"。\n"NOR, users() );
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
 if(arg=="god")
 {
  write(@HELP

       �翦�����������������������������������������������������������������
       │                      幫會信物的輔助說明                        │
       ├───────────────┬─────────┬──────┤
       │  指令格式                    │說明              │權限        │
       ├───────────────┼─────────┼──────┤
       │  help god                    │本輔助訊息        │天兵        │
       │  god <你的訊息>              │幫會專用頻道      │天兵        │
       │  members                     │列出線上幫會成員  │天兵        │
       │  leaveclub                   │主動退出幫會      │天神以上    │
       │  include <人名>              │將某人收入界      │天神專用    │
       │  dismiss <人名>              │取消某人分堂職務  │天神專用    │
       │  accept <人名>               │讓某人加入幫會    │天神以上    │
       │  kickout <人名>              │將某人逐出幫會    │聖主　　    │
       │  subleader <人名> to <分堂名>│升級某人為界神    │創神以上    │
       │  retire <人名>               │撤除某人分堂主職位│創神以上    │
       │  givepower <人名> to <等級>  │改變某人的職位    │創神以上    │
       │  lockleave <on> <off>        │限制自行退幫      │聖主        │
       │  handover <人名>             │掌門職務交接      │聖主        │
       │  listmember                  │幫會名冊          │天神以上    │
       └───────────────┴─────────┴──────┘
	 ◎ 使用 accept 指令必須對方先用 joinclub 指令申請才能生效。
         ◎ 神族目前有分四個界:  《天界》、《仙界》、《冥界》、《魔界》。
         ◎ 等級分為: <1.天兵> <2:神使> <3.魔神> <4.天神> <5.創神> <6.聖主>。

HELP
  );
  return 1;
 }
 return 0;
}
int do_about(string arg)
{
 if(arg=="god")
 {
  write(@ABOUT
● 神族信物 ─ 桂冠 ○

    相傳天神宙斯獎賞有功之神時，便是用月桂樹樹葉編織成的頭冠
來當作獎勵，能拿到桂冠的神，莫不受到其他眾神所尊敬。

　　在天地未開，大地渾沌之時，相傳就有這座諸神塔存在世間，作
為天上眾神與地上人類的聯繫。在當時，就有許多神靈借由此塔自由
進出天上與人間，也有許多惡魔由諸神塔出入，剛開始天神，惡魔與
人類還相處的不錯，但到後來惡魔想脫離地獄，統治人間，便和天神
與人類發生了一場大戰，大天使長 ─ 米迦勒率領眾天使與地獄大魔
王 ─ 撒旦所率領的魔兵在人間展開長達數個世紀的戰爭，就連原本
是大天使的路西法，也墮落成為墮天使，與眾天神為敵，就可知道當
時戰役之盛大。

　　但終究邪不勝正，魔王撒旦不敵眾天神的圍攻，節節退敗，只好
回到地獄，墮天使 ─ 路西法也被天使長 ─ 米迦勒所降服，這一場
歷史上著名的神魔大戰才終告結束。米迦勒為防止撒旦與路西法再次
危害人間，便將諸神塔與地獄的通路封住，還將自己與路西法封印成
諸神塔外的兩尊雕像，這便是宣告撒旦，不可有侵犯人間之野心，同
時也是警惕世人，若有人想破壞和平，他一定會為了人世間的和平，
破除封印，再次懲奸除惡。

　　在米迦勒封印自己與路西法之前，將自己的桂冠放在諸神塔內，
希望後世有能人能夠進入諸神塔內，繼承他的遺志。過了數百個世紀
之後，終於有一個人，突破塔內重重機關與陷阱，走到放置桂冠的房
間，拿起桂冠，宣示繼承米迦勒的遺願，繼續維持人間的和平，那個
人就是神族第一代聖主，而流傳至今，桂冠已經變成神族共通的標誌
了，神族上下每個人都是頭戴桂冠，代表神族肩負著維持和平的重責
大任。

ABOUT
  );
  return 1;
 }
 return 0;
}
