#include <ansi.h>
inherit NPC;
void create()
{
        set_name("施亦歡", ({ "yi huan shi","shi" }) );
        set("gender", "女性" );
        set("long",
            "她是施迅的女兒，皮膚相當白皙，但卻愁眉苦臉，不知有何煩惱。\n"
           );
        set("age",17);
        set("level",10);
        set("chat_chance", 2);
        set("chat_msg", ({
             (:command("sigh"):),
        }));
        set("talk_reply","唉！！這幾天很多人來找爹爹，看來不是什麼好事。\n");
        set("inquiry", ([
            "煩惱": "唉！！這幾天很多人來找爹爹，看來不是什麼好事。\n",
            "象棋": "這是爹爹和別人下的棋，因爹爹有事所以叫我先看著，你可別亂動啊。\n",
        ]) );

        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                "施亦歡叫道：救命啊！救命啊！有人要殺死我了啊！\n",
               (:command("help!"):),
         }) );
        setup();
}
void init()
{
       ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{

        if( (arg!= "down") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
      command("inn");
           say("施亦歡說道："HIB"爹爹說不可以進去，說裡頭有會吃人的魔鬼哦。\n"NOR);
        return 1;
}
