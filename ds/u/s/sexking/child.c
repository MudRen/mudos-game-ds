#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"抓狂的小孩"NOR,({ "The crzay child","child"}));
        set("long",@LONG
一位超級抓狂的小孩,活蹦亂跳的好抓狂,但是他好像為
了些事很著急的樣子。
LONG
);
        set("level", 1);
        set("age",5);
        set("chat_chance", 10);
        set("chat_msg", ({
 "抓狂的小孩抓狂的說:不見了!真的不見了!"
 "抓狂的小孩抓狂的說:完蛋了!sexking會打我屁屁的啦~~"
}));
        set("inquiry",([
  "shit" : "是一個很漂亮的便便ㄛ~黃金做的ㄝ...\n",
  "黃金便便" : "是一個很漂亮的便便ㄛ~黃金做的ㄝ...\n",
  "gold-shit" : "是一個很漂亮的便便ㄛ~黃金做的ㄝ...\n",
  "sexking" : "我是他的朋友ㄛ~~我們都很抓狂說...\n",
]));

        setup();
        add_money("coin",150);
        carry_object(__DIR__"sk3");
}

int talk_action(object me)
{
        object ob;
        message_vision(HIC"抓狂的小孩對$N說:完蛋了~~我把sexking心愛的黃金便便(gold shit)給弄丟了。\n"NOR,me);
        return 1;
}

int accept_object(object who, object ob)
{
        object sex,a,sk3;
        sex = this_object();
        sk3 =new(__DIR__"sk3");
        if( ob->query("id")!="gold-shit" || query_temp("gold-shit") ) return 0;
        command("say 哇~~這不是黃金便便嗎?我找到了！我找到了！\n");
        command("say 謝謝啦!");
        command("say 來~送你一個女人最愛的化妝品~sk3~當作我的謝禮..^^");
        sk3->move(who);
        set_temp("gold-shit",1);
        tell_object(who,HIR"你突然覺得好有成就感,哈哈哈的笑了起來。\n"NOR);
        call_out("delay",600,this_object());
        set("long",HIC"一個開開心心聞著便便的小孩\n"NOR);
        set_name(HIC"抓狂的聞便便的小孩"NOR,({ "The shit child","child"}));
        set("chat_chance", 10);
        set("chat_msg", ({
    "抓狂的小孩開心說:這下找到了黃金便便就不會被sexking罵了."
     }));
return 1;
}
void delay(object sex)
{
delete_temp("gold-shit");
             set("long",@LONG
一位超級抓狂的小孩,活蹦亂跳的好抓狂,但是他好像為
了些事很著急的樣子。
LONG
);
        return;
}

        
