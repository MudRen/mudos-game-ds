// sun.c 孫婆婆

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("孫婆婆", ({"sun popo", "sun"}));
        set("gender", "女性");
        set("age", 55);
        set("long",
                "這是一位慈祥的老婆婆，正看著你微微一笑。\n"
        );
        set("attitude", "friendly");
        set("level",20);
        set_skill("whip", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("unarmed",60);
        set_skill("literate",60);


        set("inquiry", ([
                "小龍女" : "龍姑娘是我一手帶大的，她從小沒了父母，現在又獨個兒住在這古墓里，唉..\n",
        ]) );

        setup();
        carry_object(__DIR__"obj/yinsuo.c")->wield();
        carry_object(__DIR__"../obj/goldkey.c");
}


