// info_lady.c
// Modified from ES 2 drooler.c
// By Annihilator@Celestial.Empire (09/15/95)
// Last modified by Spock @ FF  97.Oct.30.

#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "嗨 !",
        "hello !",
        "嗯....",
        "哇....",
        "等等....",
        "啊....",
});

varargs void drool(string msg, string who);

void create()
{
        set_name( HIC"菲列特利加"NOR, ({ "phliterica" }));
        set("level",300);
        set("title",CYN"楊夫人"NOR);
        set("race", "人類");

        set("age", 23);
   set("gender",女性);
        set("long",
@LONG
她就是傳說中楊威利的副官，有些事可以問她ㄡ。
(ask phliterica about morral,linjack,shengsan,luky,
eeman,aiwa,anfernee,armor,weapon)
LONG
        );

        set("attitude", "friendly");

        set("welcome_msg", "菲列特利加說道: 歡迎來到 楊威利的家。\n" );

        set("chat_chance", 5 );
        set("chat_msg", ({
"菲列特利加伸手凌空一指，變出一本小說, 開始閱讀起來。\n",
"菲列特利加拿起杯子走到飲水機之前倒了些水。\n",
"菲列特利加拿起杯子喝了些水。\n",
"菲列特利加很有興致地注視著楊的照片，眼神充滿溫暖。\n",
"菲列特利加跑進廚房，要練習做菜。\n",
"菲列特利加把桌上的紙張整理了一下，裝進一個紙袋子裡。\n",
"菲列特利加伸手凌空一指，變出一包小餅乾, 開始吃起餅乾來。\n",
"菲列特利加看著資料，要幫小楊做簡報。\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );

        set("inquiry/name", @LONG
  我的名字是菲列特利加，你叫什麼勒？
LONG );
        set("inquiry/linjack", @LONG
   他的名字雖然叫老林，但是看起來一點都不老ㄡ，沒是還會耍
一下寶說.... 
LONG );
        set("inquiry/luky", @LONG
  這是在ＤＳ中能力僅次於我的小楊的人了，他長的...粉奇特ㄚ。
LONG );
        set("inquiry/shengsan", @LONG
  他長的還不錯ㄡ，但是內涵就不知道了。你可以問問看我的姐妹
藍天美女看看。
LONG );
        set("inquiry/morral", @LONG
  我的小楊是最帥的，如果要消去我有關他的記憶，就只有消去我
所有的記憶。
LONG );
        set("inquiry/anfernee", @LONG
  我每次看到他他都不茍言笑，好像姆萊中將。
LONG );
        set("inquiry/aiwa", @LONG
  他很有特色ㄡ，就是每天在他旁邊的女的都不一樣。
LONG );
        set("inquiry/eeman", @LONG
  每次看到他，他就對我露出邪惡的微笑。不過沒關係，我的小楊會
保護我。
LONG );

        set("inquiry/armor", @LONG
  你問我armor？好吧，給你一個範例。

#include <armor.h>

inherit FINGER;

void create()
{
set_name("雲之戒",({"ring"}) );
set("long"," 這戒子有股神秘的力量令人感到安詳,且使人的頭腦清新。\n");
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "gem");
set("unit", "隻");
                set("value", 3000);
set("armor_prop/armor",32);
set("armor_prop/defense",5);
set("armor_prop/parry",0);
set("level",15);
}
setup();
}
LONG );
        set("inquiry/weapon", @LONG
  你問我weapon？好吧，給你一個範例。

#include <ansi.h>
#include <weapon.h>

inherit AXE;
int do_wield(object me, object ob);
void create()
{
 set_name(HIC"冰•風暴戰斧"NOR,({"ice storm axe","axe"}));
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
  set("long","這把斧頭看來平平無奇，就像一般鐵斧一樣，但是
    外面結了一層不溶的冰，並發出神和冰的氣。大概是掉落在
    神山上的斧頭，受到經年累月神光的保護，才得已擁有如此大的
     力量吧。\n");
set("value",4500);
                set("material", "steel");
        }
 init_axe(855);	
 
// These properties are optional, if you don't set them, it will use the
// default values.   
set("wield_msg", "$N將$n握在手中，$N登時充滿力量，但$N身旁的人卻冷的直打顫。\n");
set("unwield_msg", "$N將$n掛回腰邊，冷氣終於停止了。\n");  
        setup();
}int fail_eq(object me)  
{
if(me->query("level") <35) {
message_vision("$N的等級不夠，無法駕馭這把神斧。\n",me);
}
       return 1;

}


void attack(object me,object victim)
{
int damage,str,dex;

if( random(100)>70)
    {
        /*   COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),2);*/
str = me->query("str");
dex=me->query("dex");
damage=(dex+str)*(1+random(5));
        victim->receive_damage("hp", damage, me );
message_vision("                  冰•風暴戰斧突然發出強大的光芒 

                       從天上召喚來一陣冰雹
          
              向$N擊去！！！造成$N"+damage+"點的傷害！！！！\n",victim);
                             
         return;    

        }
    return;
}              
}

LONG);

        setup();

}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "﹖", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "！", "");
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "嗎", "");
        msg = replace_string(msg, "耶", "");
        msg = replace_string(msg, "吧", "");

        if( msg != "" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

void relay_say(object ob, string msg)
{
        string who, phrase;

        if( !userp(ob) ) return;
        who = ob->query("name");

// Don't process our own speech.
        if( ob == this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                command("angry " + ob->query("id") );
                command("say 踢的好!! 看我的!!");
                command("chair " + ob->query("id") );
                break;
        default:
                command("smirk " + ob->query("id"));
                break;
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "為什麼") >= 0) ) {
                if( sscanf(msg, "%*s為什麼%s", msg)==2 ) msg = "為什麼" + msg;
                switch(random(8)) {
                case 0: command("say " + who + "﹐你是在問我嗎﹖"); break;
                case 1: command("say 關於" + msg + " ... "); break;
                case 2: command("say 呃 ... "); drool(); break;
                case 3: command("say 這個問題嘛 ...."); break;
                case 4: command("say " + who + "﹐知道這個問題的答案對你那麼重要嗎﹖"); break;
                case 5: command("say " + msg + "﹖"); break;
                case 6: command("say " + who + "你能不能說清楚一點﹖"); break;
                case 7: command("say " + who + "﹐我不懂你問的問題"); break;
                }
        }
        else if( (strsrch(msg, "你") >= 0)
        ||      (strsrch(msg, "妳") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
                msg = replace_string(msg, "你", "我");
                msg = replace_string(msg, "妳", "我");
                switch(random(10)) {
                case 0: command("say " + who + "﹐你是說" + msg + "嗎﹖");      break;
                case 1: command("say 你確定" + msg + "﹖");     break;
                case 2: command("say " + msg + "跟你有什麼關係﹖");     break;
                case 3: command("say 嗯 ... " + who + "說得好"); break;
                case 4: command("say " + who + "你為什麼對" + msg + "這麼有興趣﹖"); break;
                case 5: command("say 為什麼你認為" + msg + "﹖"); break;
                case 6: command("say 換個話題吧"); drool(); break;
                case 7: command("say 才怪"); break;
                case 8: command("say 不一定吧﹖"); break;
                case 9: command("say 有這個可能 ...."); break;
                }
        }
         else              
                if((strsrch(msg, "我") >= 0) ){
                if (strsrch(msg, "我叫") >= 0 ) command("say "+who+", 你好!!");
                if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
                msg = replace_string(msg, "我", "你");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("say 你是說" + msg + "嗎﹖"); break;
                case 1: command("say 真的﹖" + msg + "﹖");     break;
                case 2: command("say 如果" + msg + "﹐我能幫你什麼忙嗎﹖");     break;
                case 3: command("hmm"); break;
                case 4: command("say 你認為" + msg + "﹖"); break;
                case 5: command("say 我有同感"); break;
                case 6: command("say 你說的「" + msg + "」我不能苟同"); break;
                case 7: command("say 有關「" + msg + "」的話題到此為止好嗎﹖"); break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say 為什麼說" + msg + "?"); break;
                        case 1: command("say 「" + msg + "」是什麼意思﹖"); break;
                        case 2: command("say " + msg + "﹖"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("say ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 9: command("say 你怎麼知道" + msg + "?"); break;
                        case 10: command("say 剛剛" + who + "不是說了﹐" + msg); break;
                        case 11: command("say 我當然知道﹐" + msg); break;
                        case 12: command("say 然後呢﹖"); break;
                        case 13: command("say 真的嗎﹖"); break;
                        case 14: command("say 我不這麼認為。"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}
