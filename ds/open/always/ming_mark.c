// 幫會信物
// "level": 玩家在幫會中的等級(1~?)
// 1: 教徒
// 2: 堂員 
// 3: 護法 
// 4: 堂主(can enter box)
// 5: 光明聖使(can enter box)
// 6: 幫主 (2名)(can enter box)
//北門吹風說﹕風雷*2 闇燄*2 天樞*1 青木*1
// "title": 幫會頭銜
// "info1": 備用區1 (分堂名稱)
// "info2": 備用區2
// "info3": 備用區3
//

#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "明教"
#define CLUB_ID "ming"
#define CLUB_CHANNEL "ming"
#define CLUB_MARK "Plate of Holy Fire"
#define CLUB_ENTER_FILE "/open/world1/tmr/bagi/rift1"
#define CLUB_OUT_FILE "/open/world1/baal/ming_club/lighttop"
inherit FINGER;

private string *members_level = ({
        "族客", //0
        "教徒", //1
        "堂員", //2
        "護法", //3
        "堂主", //4
        "光明聖使", //5
        "幫主", //6
});

void create()
{
        set_name(HIR"聖─火─令"NOR,({"Plate of Holy Fire","plate","club_mark"}));
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
這是用精剛練成的紅色令牌，上面透著紅光是教中鎮教之寶
由奇巧匠人所製，只要出示令牌，大江南北暢行無阻(show plate)。
[關於明教的其他說明請用<help ming>指令查詢。]
LONG
                );
        }
        set("club_id",CLUB_ID);
        set("club",CLUB_NAME);
        set("sub_club",({"風雷堂","闇燄堂","天樞堂","青木堂"}));
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
                 "title": "明教特級顧問  ",
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
                add_action("do_givepower","givepower");
                add_action("no_suicide","suicide"); //防止自殺
                add_action("do_subleader","subleader");
                add_action("do_retire","retire");
  case 5:
                add_action("do_listmember","listmember");
  case 4:
                add_action("do_include","include");
                add_action("do_dismiss","dismiss");
  case 3:
                add_action("do_accept","accept");
                add_action("do_kickout","kickout");
  case 2:
  default:
                add_action("do_help","help");
                add_action("do_members","members");
//                add_action("do_leaveclub","leaveclub");  bug emote by alick
                add_action("do_enter_club","enter");
 }
}

int do_enter_club(string arg)
{
        object env,me;
        if(arg!="ring") return 0;
        me=this_player();
        env=environment(me);
        if(!env) return 0;
        if(env->query("ming_club_enter"))
        {
                if(me->query_temp("killer")) return notify_fail("天上傳來一個幽幽的聲音: 你, 因為你剛剛殺了人所以暫時不能進入幫會。\n");
        if(me->query_temp("invader")) return notify_fail("天上傳來一個幽幽的聲音: 因為你剛剛傷了人, 所以暫時不能進入幫會。\n");
                message_vision("$N高舉$n大喊：「當今武林誰人能比，唯我明教獨步江湖。」\n",me,this_object());
                if(!me->can_move(CLUB_ENTER_FILE))
                {
                        message_vision("由光明頂上放下一台纜車將你載上去。\n",me);
                        return 1;
                }
                else
                {
                        tell_room(env,me->name()+"坐上纜車，被載了上去。\n",({ me }));
                        me->move(CLUB_ENTER_FILE);
                        tell_room(environment(me),me->name()+"緩緩的給纜車載了上來。\n",({ me }));
                        write("纜車緩緩的停住了，你發現自己已經來到了─光明頂。\n");
                        me->add_busy(1);
                        return 1;
                }
        }
        else if(env->query("ming_club_out"))
        {
                message_vision("$N高舉$n著跳上了纜車，被纜車載了下去。\n",me,this_object());
                if(!me->can_move(CLUB_OUT_FILE))
                {
                        message_vision("纜車緩緩的被吊了上去，只見$N不知所措的呆站在原地。\n",me);
                        return 1;
                }
                else
                {
                        tell_room(env,me->name()+"隨著纜車向下離開。\n",({ me }));
                        me->move(CLUB_OUT_FILE);
                        tell_room(environment(me),me->name()+"被纜車載了下來。\n",({ me }));
                        write("纜車被吊了上去，你又再度踏在"+environment(me)->query("short")+"的土地上。\n");
                        me->add_busy(1);
                        return 1;
                }
        }
        else return notify_fail("你將"+this_object()->name()+"高高舉起大喊：「當今武林誰人能比，唯我明教獨步江湖。」，但是什麼事情都沒發生。\n");
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
 if(wizardp(user)) return "【榮譽會員】明教特級顧問    ";
 level=user->query("level");
 if(level>100)  str = "【????????】";
 else if(level<11)      str = "【第 "+chinese_number(level)+" 級】";
 else if(level<21)      str = "【第"+chinese_number(level)+"級】";
 else if(level%10==0)   str = "【第"+chinese_number(level)+"級】";
 else str = "【"+chinese_number(level)+"級】";
 info=CLUB_D->query_member_info(CLUB_ID,getuid(user));
 rank=info["level"];
 switch(rank)
 {
        case 6: str+="明教教主"; break;
        case 5: str+="明教光明聖使"; break;
        case 4: str+="明教"+info["info1"]+"堂主"; break;
        case 3: str+="明教"+info["info1"]+"護法"; break;
        case 2: str+="明教"+info["info1"]+"堂員"; break;
        default: str+="明教教徒    ";
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
//      list=CLUB_D->club_members(CLUB_ID);
//      users = filter_array( users(), "filter_members", this_object() ,list);
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
                        str = sprintf("%s%12s %-16s %s(%s)",
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
                        if(me_info["level"] != 4 ) return notify_fail("只有堂主能將族人收入分堂。\n");
                        if(!stringp(sub=me_info["info1"])) return notify_fail("只有堂主能將族人收入分堂。\n");
                        if(ob_info["level"] != 1 || ob_info["info1"]!="無" )
                                return notify_fail("只有一般教徒可以收入你的分堂。\n");
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
                if(sizeof(ob_info) )
                {
                        if(!sub=me_info["info1"] || me_info["level"]!=4 ) return notify_fail("只有堂主能免除分堂下成員職務。\n");
                        if(ob_info["level"] != 1 ) return notify_fail("對方並不屬於你的管轄。\n");
                        if(ob_info["info1"] != sub) return notify_fail("對方並不屬於你的管轄。\n");
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
                 "title": "明教教徒",
                 "info1": "無",
                 "info2": ctime(time()),
                 "info3": me->name_id(1)
                 ]);
                 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
                 mark->move(ob);
                 ob->add("channels", ({"ming"}));
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
                        if(!CLUB_D->is_club_leader(me)) return notify_fail("這裡有這個人嗎﹖\n");
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
                                return notify_fail("只有一般教徒可以成為堂主。\n");
                        if( (int) member_array(sub, query("sub_club"))<0 )
                                return notify_fail("目前可用的分旗為【風雷堂】、【闇燄堂】、【天樞堂】、【青木堂】。\n");
                        ob_info["level"]=4;
                        ob_info["info1"]=sub;
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                        if(!mark=present(CLUB_MARK,ob))
                        {
                                write("幫會信物取得失敗。\n");
                        }
                        else
                        {
                                message_vision("$N將$n提昇為"+sub+"堂主, 並和$n握手勉勵一番。\n",me,ob);
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
                        if(ob_info["level"] != 4) return notify_fail("對象並不是堂主。\n");
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
                                message_vision("$N免除了$n的"+sub+"堂主職務。\n",me,ob);
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
                        if( wiz_level(ob) > wiz_level(me) && wizardp(ob) )
                                        return notify_fail("你沒有資格改變對方的職務等級。\n");
                        if(level >= me_info["level"] )
                                return notify_fail("你沒有資格提昇對方的職務等級到這個等級。\n");
                        if(level == ob_info["level"] )
                                return notify_fail("對方已經是"+(string)members_level[level]+"了。\n");
                        if(level > 5 || level < 1 )
                                return notify_fail("目前等級分為 <1:教徒> <2:堂員> <3:護法> <4:堂主> <5:光明聖使><6:教主> \n");
                        if( level > ob_info["level"]  )
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
                                        return notify_fail("堂主專用。\n");
                                        break;
                                case 3:
                                        ob_info["level"]=3;
                                        ob_info["info1"]="無";
                                        ob_info["info2"]=ctime(time());
                                        ob_info["info3"]=me->name_id(1);
                                        break;
                                case 4:
                                        return notify_fail("請用subleader指令來指定一個分旗。\n");
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
                       
                        me_info["level"]=5;
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
                        message( "channel:ming",YEL"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")將"+CLUB_NAME+"指揮權移交給"+ob->name(1)+"("+capitalize(ob->query("id"))+")。\n"NOR, users() );
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
        message( "channel:ming",YEL"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")主動退出了"+CLUB_NAME+"。\n"NOR, users() );
        tuned_ch = me->query("channels");
        if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 );
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
 if(arg=="ming")
 {
  write(@HELP

       �翦�����������������������������������������������������������������
       │                      幫會信物的輔助說明                        │
       ├───────────────┬─────────┬──────┤
       │  指令格式                    │說明              │權限        │
       ├───────────────┼─────────┼──────┤
       │  help ming                   │本輔助訊息        │教徒        │
       │  ming <你的訊息>             │幫會專用頻道      │教徒        │
       │  members                     │列出線上幫會成員  │教徒        │
       │  leaveclub                   │主動退出幫會      │教徒        │
       │  include <人名>              │將某人收入分堂    │堂主專用    │
       │  dismiss <人名>              │取消某人分堂職務  │堂主專用    │
       │  accept <人名>               │讓某人加入幫會    │光明護法以上│
       │  kickout <人名>              │將某人逐出幫會    │光明護法以上│
       │  lockleave <on> <off>        │限制自行退幫      │教主        │
       │  subleader <人名> to <分堂名>│升級某人為堂主    │教主        │
       │  retire <人名>               │撤除某人堂主職位  │教主        │
       │  givepower <人名> to <等級>  │改變某人的職位    │教主        │
       │  handover <人名>             │掌門職務交接      │教主        │
       │  listmember                  │幫會名冊          │光明聖使以上│
       └───────────────┴─────────┴──────┘
         ◎ 使用 accept 指令必須對方先用 joinclub 指令申請才能生效。
         ◎ 明教目前有四個分堂:【風雷堂】、【闇燄堂】、【天樞堂】、【青木堂】。
         ◎ 等級分為: <1:教徒> <2:堂員> <3:護法> <4:堂主> <5:光明聖使><6:教主> 。
         ◎ 其他明教的事務: <help ming_rule> , <help ming_group> 。
        
HELP
  );
  return 1;
  }
  if(arg=="ming_rule")
  {
   this_player()->start_more(@RULE

       CCKK,RICHAN等人尚未提供,未建立
                       
                             BAAL@DS

RULE
);
return 1;
  }
  if(arg=="ming_group")
  {
  this_player()->start_more(@MING_PART

    在滄縣的疾風門內，一群人正練著劍，當一人身法遲鈍，劍
舞乏力，在大家休息時他還努力的練著劍，旁邊的階梯上站著一
為中年男子，向他招了招手，兩人走到後院，楊雙亟提劍運氣使
出索極劍法與迷幻七步訣，只見白光閃閃，身影飄渺，突然楊雙
亟飛身而起，向一旁的大樹砍去，只見大樹一分為二。他跪下來
痛哭大喊：「為什麼？！為什麼？！我為什麼學不會？。」楊雙
亟拍拍他說：「不要灰心....！」他站起來堅決的說：「我要離
開這裡！」
      十      年      後   •  •  •  •  •  •
    一位青年站在天池的大石上，盤腿修練殘月心法，他雙眼張
開，右手一揮，劍隨及而出，他縱身上劍御劍而去。原來他在十
年中走遍天下，尋訪名師，練成一身本領，現拜軒轅烈門下。
    
    在孟村的八極門內，一群村人正練著拳，之中一位小男孩打
起拳來虎虎生風，一點也不輸給大人，石板屋門口站著就是名震
江湖的李書文。李書文看了之後，暗自下定要把全身絕學傳給他
。他天天練拳從不懈怠，幾年的功夫就成了李書文的得意門生，
一天他到後山去練拳，無意間發現山壁間有一條隙縫，他好奇的
鑽了進去，沒想到裡面別有洞天，原來是座山谷，他在裡面遇見
一隻白毛大猿，和牠成為好朋友，天天與牠練拳，功力竟然突飛
猛進，幾年後的一點，李書文把他叫進來說：「孩子，我沒什麼
可以教你了，是該讓你走了。」他拜別李書文出去闖蕩江湖。
      數      年      後   •  •  •  •  •  •
    一位青年聚精會神盯著冷月獸，冷月獸露出月牙，血紅的雙
眼怒視著他，冷月獸身上的傷口不斷的冒出鮮血，月牙也因血而
染紅，冷月獸準備發出致命一擊，冷月獸衝向青年，青年雙手反
扣住冷月獸，翻身向冷月獸發出「猛虎硬爬山」，冷月獸吐了幾
口鮮血而亡。他離開之後，碰巧遇見吳鐘，吳鐘見他天資聰敏
就收他為徒，他現在就是武林中響叮噹的人物  ------Richa
    多年前的一個夜晚，兩人因為講話很投機而結拜成兄弟，下
定決心要成立【明教】，於是兩人開始網羅人才，也因這些創幫
的人才，和天地會的培養，才有【明教】。這天這一群正在為幫
會要設在那而傷腦筋，突然Richan說要帶大家去一個地方，大夥
來到白毛大猿的山谷，看到一面懸崖，眾人使出上乘輕功向上縱
去，只見崖頂，一片光亮，向外望去萬里無雲，於是命名為「光
明頂」，大家看了看四周，覺得好像少了什麼， Ccr不知去那搬
一塊千斤石，Richan提起紫金槍躍向巨石提道：「當今武林誰人
能比，唯我明教獨步江湖。」大家努力的賺錢加上Baal和Luky的
協助終於成立今天的明教。

                                       Richan@DS
MING_PART
);
  return 1;    
  }
 return 0;
}       
