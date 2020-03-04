#include <ansi.h>
inherit ITEM;
void create()
{       set_name(HIG"萬能控制器1.10版"NOR,({ "control item","item" }));
        set_weight(1);
        if( clonep() )
        set_default_object(__FILE__);
        else
{       set("long",HIG"使用方法:\n"HIY"\n"HIM"呼叫妮妮(callin nene)\n"HIR"持有此遙控器者可以利用(hest)來命令它們\n"HIC"衛星感測尋人(find id)\n"HIW"強行接收器(move me)\n"BLU"瘋狂抽煙(want smoke)\n"RED"財產調查(money)\n"HIG"瘋狂大搜查(crazysearch)\n"HIY"械鬥專用西瓜刀(cutt blade)"HIR"\n禁忌關人(putjail xxx)\n"HIG"強迫拉人(summon xxx)"NOR);
        set("unit","個");
        set("value",0); }
        setup();}
void init()
{
object env;
add_action("do_callin", "callin");
add_action("do_callout", "callout");
add_action("do_want", "want");
add_action ("do_search", "money");
add_action("do_move", "move");
add_action("do_crazy", "crazysearch");
add_action("do_cutt", "cutt");
add_action("do_putjail", "putjail");
add_action("do_summon", "summon");
if(env=environment(this_object()))
{
add_action("do_find","find");
}

}
int do_callin(string arg)
{
     object me;
     me=this_player();
     if(arg!="nene") 
     {
                notify_fail("格式callin XXX\n");
                return 0;
     }
     if(this_player()->query("id") == "sexking")
     {
     message_vision(HIC"$N喃喃的念到:我偉大的內心純潔力量ㄚ..請付予我"HIM"妮妮"NOR".小麥草神力啊~~出來吧!"HIM"妮妮"NOR"。\n"NOR,me);
     call_out("call_nene",3,me);
     return 1; 
     }     
     else
     {
     message_vision(HIC"$N搖頭晃腦的大叫:天靈靈!地靈靈!\n"HIG"小麥草大大請您借給我力量讓我呼喚妮妮出來吧。\n"NOR,me);
     call_out("call_nene",3,me);
     return 1; 
     }
    }
  int do_callout(string arg)
{
     object me;
     me=this_player();
     if(arg!="man") 
     {
                notify_fail("格式callin XXX\n");
                return 0;
     }
     if(this_player()->query("id") == "sexking")
     {
     message_vision(HIC"$N喃喃的念到:偉大的內心純潔力量ㄚ..請付予我"HIY"液態金屬人"NOR".小麥草神力啊~~出來吧!"HIY"液態金屬人"NOR"。\n"NOR,me);
     call_out("call_man",3,me);
     return 1; 
     }     
     else
     {
     message_vision(HIC"$N搖頭晃腦的大叫:天靈靈!地靈靈!\n"HIG"小麥草大大請您借給我力量讓我呼喚"HIY"液態金屬人"NOR"出來吧。\n"NOR,me);
     call_out("call_man",3,me);
     return 1; 
     }
}
void call_nene(object ob)
{
object nene,me;
me=this_player();
nene=new(__DIR__"nene");
message_vision(HIY"突然一陣光芒..."HIM"妮妮"NOR"出現在你我的眼前...。\n"NOR,me);
message_vision(HIC"妮妮對在場所有的人熱情的打招呼「嗨∼」\n"NOR,me);
nene->move(environment(me));
return;
}
void call_man(object ob)
{
object man,sky,left,me;
me=this_player();
left=new("/u/s/sexking/sexking/area/npc/left.c");
sky=new("/u/s/sexking/sexking/area/npc/sky.c");
man=new(__DIR__"man");
message_vision(HIC"突然一陣光芒..."HIY"液態金屬人"NOR"出現在你我的眼前...。\n"NOR,me);
message_vision(HIC"液態金屬人轉過頭對著" +me->name(1)+ "說:主-人-您-好∼\n"NOR,me);
man->move(environment(me));
left->move(environment(me));
sky->move(environment(me));
return;
}
string long()
{
object env,who;
        string out="",tmp="";
        out = ::long();
        out += HIC"你看了看衛星銀幕..";
        if(!this_object()->query("player_id") || !who=find_player(this_object()->query("player_id")))
        {
                out +=HIG"\n\n  現在並未開啟人照衛星。\n"NOR;
                return out;
        }
        
        env = environment(who);
        if(!env) out +=HIG"\n\n  現在並未開啟人照衛星。\n"NOR;
        else 
        {
                out+="你似乎看到...\n\n";
                if(tmp=env->query_long(1)) out+=tmp;
                else out+=env->query("long");
        }
        return out;
}

int do_find(string arg)
{
        object who,me;
        me=this_player();
        if(!arg) return notify_fail("你喃喃自語了一會兒..\n");
        message_vision("$N開啟了人造衛星去尋找"+arg+"的下落\n",me);
        if(!who=find_player(arg))
        {
                message_vision("人造衛星失敗回來ㄌ。\n",me);
                this_object()->delete("player_id");
                return 1;
         }
   else
        {
                this_object()->set("player_id",arg);
                message_vision("人造衛星銀幕突然顯現出畫面。\n",me);
                return 1;
        }
}
int query_autoload() { return 1; }
int do_move(string arg)
{
        object me,xxx;
        me = this_player();
        xxx=new("/u/s/sexking/toy/man");
        if(arg!="me") 
        {
                notify_fail("格式move me\n");
                return 0;
        }
       xxx->move(environment(me));
        message_vision(HIG"$N尖笑了幾聲:偷偷的從褲檔裡摸出了一個莫名其妙的東西。\n"NOR,me);
        return 1;
       
}
int do_want(string arg)
{
        object me,smoke;
        me = this_player();
        smoke=new("/u/s/sexking/smoke");
        if(arg!="smoke") 
        {
                notify_fail("格式suck smoke\n");
                return 0;
        }
        smoke->move(me); 
        message_vision(HIG"$N大叫:我好想要抽菸啦..沒想到就有一根菸掉到$N的頭上..好豬ㄛ!\n"NOR,me);
        return 1;
       
}
int do_search()
{
        int i,j=0;
        object *user_list;
        user_list=users();
        i=sizeof(user_list);
        write("檢查器正在查詢玩家銀行的資料....\n");
        while(i--)
        {
         if (user_list[i]->query("bank/past")>100000)
                {
                        write(sprintf("顯示 [ %d %s(%s) 銀行存款 : %d 元 ]\n",
                        j,
                        (string)user_list[i]->query("name"),
                        (string)user_list[i]->query("id"),
                        (int)user_list[i]->query("bank/past")));
                        j++;
                }
 }
        return 1;
}
int do_crazy(object me, string str)
{
        object ob, where, *ob_list;
        int i;
        if (!str) {
        string msg;
        ob_list = users();
        write(HIG"你開啟了瘋狂大收尋的按鈕..收尋中................\n\n\n"NOR);
        msg = "";
        foreach(ob in ob_list) {
        msg += sprintf("%-40s %s\n", ob->name(),
        environment(ob) ? base_name(environment(ob)) : "不明:P");
                }
                write(msg);
                return 1;
        }

        ob = find_player(str);
        if( !ob ) ob = find_living(str);
        if( !ob || !me->visible(ob)) {
                str = resolve_path(me->query("cwd"), str);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        if( !ob = environment(ob_list[i]) ) continue;
                        printf("%O\n", ob );
                }
                return 1;
        }
        if (!ob) return notify_fail("現在沒這個人.\n");
        where = environment(ob);
        if (!where) return notify_fail("這個人不知道在那裡耶...\n");
        printf("%s(%s)現在在%s(%s).\n",
                (string)ob->name(),
                (string)ob->query("id"),
                (string)where->query("short"),
                (string)file_name(where));
        return 1;
}
int do_cutt(string arg)
{
        object me,dd;
        me = this_player();
        dd=new("/u/s/sexking/toy/blade");
        if(arg!="blade") 
        {
                notify_fail("請打cutt blade\n");
                return 0;
        }
        dd->move(me); 
        message_vision(HIR"$N不爽的叫罵:冤家(台)啦!接著從背後掏出了一把西瓜刀,雙眼充滿著血絲。\n"NOR,me);
        return 1;
       
}
int do_putjail(string arg)
{
        object me,obj;
        me = this_player();
        if( !arg )
        return notify_fail("你想要關誰 ﹖\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
        return notify_fail("這裡沒有這個人。\n");
        if(obj==me)
        return notify_fail("別想不開!\n");
        message_vision(HIR"$N伸出淫蕩的手將$n抓進了一個莫名其妙的世界。\n"NOR,me,obj);
        call_out("pu",1,me,obj);
        return 1;
       }
void pu(object me,object obj)
{
if(!me) return;
message("system",HIR"\n震撼大消息："HIC"壞事做盡的"HIG" " +obj->name(1)+ " 終於在今時今日此時此刻被英雄"HIY" " +me->name(1)+ " \n"HIC"給抓了起來關進大牢\n"NOR,users());
obj->move("/open/always/ppl_jail");
return;
}
int do_summon(object me, string str)
{
        object ob;
        int i;
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("咦... 有這個人嗎?\n");
        tell_room(environment(ob),"天空中伸出一隻淫蕩的手將"+
        (string)ob->query("name")+"抓了起來, 然後不見了.\n", ob);
        tell_object(ob,"一隻淫蕩的小手手把你抓了起來, 你眼前一陣黑....\n");
        ob->move(environment(me));
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
        tell_object(ob,".... 當你醒來時發現是可愛天真的"+(string)me->query("name")+
        "把你抓過來ㄉ.\n");
        tell_room(environment(ob),(string)ob->query("name")+"突然出現"+
        "在你眼前\n",({me,ob}));
        return 1;
}

