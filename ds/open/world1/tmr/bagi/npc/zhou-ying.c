#include <ansi.h>

inherit NPC;

void do_attack();

void create()
{
        set_name("周瑛",({"zhou ying", "zhou","ying"}) );
        set("long",@long
    周瑛是萬斧莊莊主的獨生女，長的清秀可愛，一直是萬斧莊眾人
的掌上明珠。只見她正著急走來走去，似乎在等什麼人一樣。
long
);
        set("age",18);
        set("race","人類");
        set("level",25);
        set("attitude", "peaceful");
        set("title","萬斧莊第十三代弟子");
        set("gender", "女性" );
        set("chat_chance",6);
        set("chat_msg",({
                "周瑛說：人傑跟英傑兩位哥哥怎這麼久都還沒有出來，真是急死人了。\n",
                (: command("sob") :),
        }) );

        setup();
}


