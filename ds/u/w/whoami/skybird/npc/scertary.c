
#include <ansi.h>
inherit NPC;
void create()
{
 set_name("女秘書",({"scertary",}));
 set("long","你第一眼見到她, 哇! 那一瀑金髮使你呆了....
             而她的工作能力也顯然很強.....\n"
            ",\n"
    );
 set("attitude","peaceful"); 
 set("age",20);
 set("gender","女性");
 set("combat_exp",124753+random(38358));
 set("level",10);
 set("title","變臉的");
 set_skill("unarmed",55);
 set_skill("force",85);
 set_skill("parry",70);
 set("guild_gifts",({10,4,0,6}));
 set("chat_chance",20);
 set("chat_msg", ({"女秘書嘴裡喃喃念著: 星期一要下午的約會也很重要.....\n",
                   "女秘書抬起頭來說: 請問你有什麼事嗎..? .\n",
                   (:command("sweat"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert slash-wood cross-slash":),
                         (:command,"exert slash-wood all-slash":),
                         (:command,"exer
t cloudmove ghostmove":),
                         (:command,"say 欺負女性!! 犯法耶!! ":),
 }));
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}