#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟大廚",({"cooker",}));
 set("long","             你看了一看眼前的廚師, 只見他手中煎鏟翻動, 身前的大鍋
                    劈哩啪啦的響著, 你不禁對眼前的這位廚師感到欽佩, 也卓實感到廚藝
                    也是一門高深的學問."
     );
 set("attitude","peaceful"); 
 set("age",42);
 set("gender","男性");
 set("level",10);
 set_skill("unarmed",50);
 set("chat_chance",10);
 set("chat_msg", ({"天梟大廚自言自語的說: 奇怪了....怎地會不見? \n",
                        "天梟大廚又喃喃自語的說: 那條"HIY"蟲"NOR"到底在哪?\n" 
}));
 set("chat_chance_combat",60);
                         (:command,"say 哇啊 ~~~":),
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
int accept_object(object who, object ob)
{
        if( 
ob->id("worm") ) {
                message("vision", name() + "楞了一楞, 隨即高興的跳了起來!\n", 

environment());
                return 1;       //傳回1就表示可接受東西
        }
}
