inherit NPC;
varargs void drool(string msg, string who);
void create()
{
//名稱
set_name("小狗", ({ "dog" }), );
set("long","一隻可愛的小狗。");
set("title","狗狗");
set("class","worker");
//屬性
set("age",5);
set("level",10);
set("chat_chance", 5);
set("chat_msg", ({
"狗狗高興的在你身旁繞來繞去∼∼∼\n",
"狗狗大吼：ㄚ∼∼∼∼∼∼嗚∼∼∼∼\n",
"狗狗用腳在地上無聊地畫著圈圈．．．．\n",
"狗狗伸手一指，變出了一堆食物．．．開始躲在一旁大快朵頤　：Ｄ~~\n",
"狗狗依偎在你腳邊撒嬌。\n",
"狗狗很累地打了一個哈欠．．ｚｚＺＺ\n",
 (: drool :),
 (: drool :),
 (: drool :),
 (: drool :),
}));
set("inquiry/name", @LONG
  我的名字是安安,你叫什麼勒?.
LONG );

setup();
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
        case "sob":
                command("pat " + ob->query("id") );
                command("comfort " + ob->query("id") );
                break;
        default:
                command("idiot " + ob->query("id"));
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

        switch(random(20)) {
                case 0: command("jump"); break;
                case 1: command("hoho"); break;
                case 2: command("idle"); break;
                case 3: command("sing"); break;
                case 4: command("say 嗨!!冒險者!!"); break;
                case 5: command("say " + who + "好久不見!"); break;
                }
}

void reset()
{
        delete("memory");
}
