#include <ansi.h>
inherit NPC;
string *rnd_say = ({
        "嗨 !",
        "hello !",
        "嗯....",
        "哇....",
        "等等....",
});

varargs void drool(string msg, string who);

void create()
{

//名稱設定
        set_name( "搞怪巫師", ({ "luky","npc","Luky",}));
        set("level",20);
        set("title","[1;36m【實習巫師】[m");
        set("race", "人類");
        set("age", 25);
        set("long", @LONG

     .--,       .--,
    ( (  \.---./  ) )
     '.__/o   o\__.'
        {=  ^  =}
         >  -  <
        /       \
       //  NPC  \\
      //|   .   |\\
      "'\       /'"_.-~^`'-.
         \  _  /--'         `
       ___)( )(___
      (((__) (__)))


LONG
        );

//屬性設定
        set("str", 7)�;
        set("dex", 12);
        set("int", 15);
        set("con", 6);
        set("attitude", "friendly");
        set("welcome_msg", "搞怪巫師說道: 歡迎來到 海底秘境. 可不可以幫我想點敘述啊?\n" );
        set("chat_chance", 5 );
        set("chat_msg", ({
"搞怪巫師很有興致地注視著你, 眼神中似乎帶有一點俏皮.\n",
"搞怪巫師拿起一枝筆, 順手在紙上塗起鴉來.\n",
"搞怪巫師伸手凌空一指﹐變出一包小餅乾, 開始吃起餅乾來.\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );

        set("inquiry/name", @LONG
  我的名字是阿光,你叫什麼勒?.
LONG );
        set("inquiry/job", @LONG
  我負責解答一些你們常見的問題. 可是....這份工作我也是剛來不久,
所以有些地方我也不清楚耶. 想知道有哪些問題可以詢問, 可以
ask joan about faq.
LONG );
        set("inquiry/clc", @LONG
  啊 ?  龍神 ?  我們的老大是隻「巨大」的龍, 不算角的話, 有
17 公尺高喔, 當初我看到他就怕, 不過看久了就習慣了....要是你遇
上龍神的「本尊」, 小心他會耍寶.
LONG );
        set("inquiry/eq", @LONG
  打 i  看看自己身上吧, 你身上穿的就是啊.
LONG );
        setup();
/*
//      set_skill("literature", 40);
//      add_money("coin", 1000 );
//      carry_object(__DIR__"obj/female_uniform_coat")->wear();
//      carry_object(__DIR__"obj/female_uniform_skirt")->wear();
//      carry_object(__DIR__"obj/uniform_cap")->wear();
//      carry_object(__DIR__"obj/leather_belt")->wear();
        carry_object(__DIR__"obj/white_shoes")->wear();
        carry_object(__DIR__"obj/white_gloves")->wear();
        carry_object(__DIR__"obj/pearl_earring")->wear();
        */
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "﹖", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "??", "");
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
                msg = replace_string(msg, "為什麼你", "我");
                msg = replace_string(msg, "為什麼妳", "我");
                switch(random(6)) {
                case 0: command("say " + who + "﹐你是在問我嗎﹖"); break;
                case 1: command("say 關於" + msg + " ... "); break;
                case 2: command("say 笨!! 因為" + msg + "呀!!"); drool(); break;
                case 3: command("say 這個問題嘛 ...."); break;
                case 4: command("say " + msg + "﹖"); break;
                case 5: command("say " + who + "你能不能說清楚一點﹖"); break;
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
                case 0: command("say " + who + "﹐你說" + msg + " ﹖");      break;
                case 2: command("say " + msg + "跟你有什麼關係﹖");     break;
                case 3: command("say 嗯 ... " + who + "說得好"); break;
                case 4: command("say " + who + "你對" + msg + "好像很有興趣喔.."); break;
                case 5: command("say 為什麼你認為" + msg + "﹖"); break;
                case 6: command("say 換個話題吧"); drool(); break;
                case 8: command("say 不一定吧﹖"); break;
                }
        }
         else              
                if((strsrch(msg, "我") >= 0) ){
                if (strsrch(msg, "我叫") >= 0 ) command("say "+who+", 你好!!");
                if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
                msg = replace_string(msg, "我", "你");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("say 你是說.." + msg + " 嗯.."); break;
                case 2: command("say 如果" + msg + "﹐我能幫你什麼忙嗎﹖");     break;
                case 3: command("hmm"); break;
                case 4: command("say 你認為" + msg + "﹖"); break;
                case 7: command("say 有關「" + msg + "」的話題到此為止好嗎﹖"); break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say 為什麼說" + msg + "?"); break;
                        case 2: command("say 「" + msg + "」是什麼意思﹖"); break;
                        case 4: command("flop"); break;
                        case 6: command("jump"); break;
                        case 8: command("smile"); break;
                        case 10: command("?"); break;
                        case 12: command("hmm"); break;
                        case 14: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 16: command("say " + who + "是從哪裡來的啊?"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}
