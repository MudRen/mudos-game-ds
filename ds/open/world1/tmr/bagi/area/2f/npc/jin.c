#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "石百斤", ({ "shi bai-jin","shi","jin"}) );
        set("level",40);
        set("long",@long
    石百斤是二十年前赫赫有名的大將軍，渾身是膽、孔武有力，能徒手
博虎殺獅，在戰場上更是威武無敵，履立戰功，特蒙皇上賜「擒獸將軍」
名號，正值官場得意時，竟忽然從江湖上消失的無影無蹤，不知為何會出
現在在這裡。
long
           );
        set_skill("dodge",75);
        set_skill("parry",75);
        set_skill("sword",80);
        set("age",54);
        set("title","擒獸將軍"NOR);
        set("chat_chance", 8);
        set("chat_msg", ({
                (:command("sigh"):),
                "石百斤嘆道：都怪當年財迷心竅，落得被困在此二十年...\n",
        }) );
        setup();
        carry_object(__DIR__"wp/sword")->wield();
        carry_object(__DIR__"eq/armor")->wear();
        carry_object(__DIR__"eq/shield")->wear();
        carry_object(__DIR__"eq/boots")->wear();
	carry_object(__DIR__"obj/key");
}

