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
        set_name( HIC"藍天級帥哥"NOR, ({ "handsome" }));
        set("level",200);
        set("title",HIY"【藍天秘書的情人】"NOR);
        set("race", "人類");
	set("gender","男性");
        set("age", 23);
        set("long",
@LONG
他是一位絕世美男子。《自畫像尚未出爐》
LONG
        );

        set("attitude", "friendly");

        set("welcome_msg", "藍天級帥哥說道: 歡迎來到 藍藍的天休憩庭院。\n" );

        set("chat_chance", 5 );
        set("chat_msg", ({
"藍天級帥哥伸手凌空一指，變出一本小說, 開始閱\讀起來。\n",
"藍天級帥哥拿起杯子走到飲水機之前倒了些水。\n",
"藍天級帥哥拿起杯子喝了些水。\n",
"藍天級帥哥很有興致地注視著你, 眼神中似乎帶有一點俏皮。\n",
"藍天級帥哥拿起一枝筆，順手在紙上塗起鴉來。\n",
"藍天級帥哥把桌上的紙張整理了一下，裝進一個紙袋子裡。\n",
"藍天級帥哥伸手凌空一指，變出一包小餅乾, 開始吃起餅乾來。\n",
"藍天級帥哥拿著他的性感內褲，在你的面前晃來晃去。\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );

        set("inquiry/name", @LONG
  我的名字是超級帥哥，你叫什麼勒？
LONG );
	set("inquiry/shengsan",@LONG
哦？你是在說全魔法門我最崇拜的偶像嗎？......告訴你一個小秘密...
...他的內褲是藍色的耶...而且內褲上還有『我愛藍天級美女』的刺繡喔。
LONG );
        set("inquiry/eq", @LONG
  打 i 看看自己身上吧，你身上穿的就是啊。
LONG );

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
