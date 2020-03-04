inherit NPC;
void create()
{
//名稱設定
set_name( "波費特", ({ "chief perfect","perfect",}));
set("level",70);
set("title","院長");
set("race", "人類");
set("age", 35);
set("evil",-350);
set("coin",random(300));
set("long", @LONG

一個和藹的院長，正坐在書桌後面看書。
LONG
        );
set("chat_chance", 5 );
set("chat_msg", ({
(:command("sigh"):),
 }) );
set("inquiry/name", @LONG
  我的名字是波費特, 您好。
LONG );

set("inquiry/word", @LONG
嗯..  你這麼有興趣嗎? 那我就告訴你好了....
最近院裡晚上常常聽見奇怪的聲音, 那似乎是痛苦的呻吟..
恐怕是惡靈已經潛入了這裡, 我正在看前任院長的修道手記,
看看有沒有辦法驅趕惡靈。

    根據上面的記載, 本院以前也曾經有過這個情況, 因為
修道院正是蓋在極陰之地上以鎮壓不祥之物。上面說, 要收
妖物必須先開地門再通天路..可惜偏偏缺了一頁, 要怎麼開
地門的那頁不知道是誰撕走了!? 唉~~ 其他的部分是:
 
 [????????]: ???????
 [六時三分]: 天堂之路開
 [十二時整]: 萬物皆生

這是賽拉(sala)留下的筆記, 或許要打聽一下有關他的事情.
如果你能幫我解開這個難題就好了... 

LONG );

set("inquiry/password", @LONG
  密碼??我怎麼知道? 

LONG );
set("inquiry/密碼", @LONG
  密碼??我怎麼知道? 

LONG );
      setup();
      carry_object(__DIR__"item/red_key");
}

void init()
{
 int expp;
 object me;
 me=this_player();
 if(me->query("quest/oten")) return;
 if(me->query("killoten"))
 {
  me->delete("killoten");
  command("say 謝謝你幫我解決了這個難題!!");
  expp=(100-me->query("level"))*10000+random(20000);
  write	("恭喜你完成了[修道院之謎]的任務!!\n"+
         "你獲得了 "+expp+" 點經驗值!\n");
  me->add("exp",expp);
  me->set("quest/oten",1);
  me->save();
 }
}
void relay_say(object ob, string msg)
{
        string who, phrase;
        if( !userp(ob) ) return;
        who = ob->query("name");
// Don't process our own speech.
        if( ob == this_object() ) return;

}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("? "+ ob->query("id") );
//              command("say 嗚~~" + ob->query("id") +"欺負我!!!");
                break;
        default:
                command("smile");
                break;
        }
}

void reset()
{
// delete("memory");
}
