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

                add_action("do_subleader","subleader");
                add_action("do_retire","retire");
                add_action("do_listmember","listmember");
                add_action("do_kickout","kickout");
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
//                        if(ob_info["level"] >= me_info["level"])
//                                return notify_fail("你不夠資格將對方踢出"+CLUB_NAME+"。\n");
//                        if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
//                                return notify_fail("你不夠資格將對方踢出"+CLUB_NAME+"。\n");
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

