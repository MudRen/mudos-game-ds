inherit NPC;


void create()

{

        set_name("小水雲",({ "watermoontoo" }));

        set("long","她叫小水雲。\n"

);

        set("age", 16);

        set_skill("unarmed", 200);

        set_skill("dodge", 200);

 

        set_temp("apply/dodge", 20);

        set_temp("apply/armor", 20);

 

        set("chat_chance",60);

        set("chat_msg",({

        (: command, "say 你好。" :),

        (: command, "smirk" :),

        (: command, "say 銀嵐花蝶女是我的老師ㄛ！！" :),

        (: command, "wink" :),



}));

setup();

        add_money("coin", 100);

}

