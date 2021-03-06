#include <ansi.h>
inherit NPC;
void create()
{
 set_name("老樵夫",({"special woodcutter","woodcutter"}));
 set("long","這樵夫雖然都已經六十好幾了, 可是運起斧來蒼勁有力\n"
            "而且眼神內斂、炯炯有神, 不像是個一般在砍柴的樵夫,\n"
            "你倒覺得他可能是早已退隱江湖的老前輩.\n");
 set("attitude","peaceful"); 
 set("age",67);
 set("gender","男性");
 set("combat_exp",124753+random(38358));
 set("level",45);
 set("title","鬼斧神樵");
 set_skill("unarmed",55);
 set_skill("axe",85);
 set_skill("blade",65);
 set_skill("force",85);
 set_skill("parry",70);
 set_skill("cloudmove",90);
 set_skill("slash-wood",85);
 map_skill("dodge","cloudmove");
 map_skill("blade","slash-wood");
 map_skill("axe","slash-wood");
 // 設定屬性分配表, 每一項的值在負9至正10之間
 // 而且四項的總和要剛好等於 20			by shengsan
 set("guild_gifts",({10,4,0,6}));
 set("chat_chance",20);
 set("chat_msg", ({"老樵夫拿起手中的斧頭, 往樹上砍去.\n",
                   "老樵夫拿著手中斧頭, 不知道在比畫什麼.\n",
                   (:command("sweat"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert slash-wood cross-slash":),
                         (:command,"exert slash-wood all-slash":),
                         (:command,"exert cloudmove ghostmove":),
                         (:command,"say 休要以為老朽好欺!!":),
 }));
 set("inquiry/name","哈--哈--哈, 老夫早以在山林多年, 眾人都叫我鬼斧神樵! 我連自己姓什麼都忘了...\n");
 set("inquiry/axe","這把斧頭, 跟了老朽四十多年....算了, "HIY"那些事"NOR"就不要再提了...\n");
 set("inquiry/那些事","不是告訴你不要再提了嗎?");
 set("inquiry/where are you come from","老朽是這裡人! 我在這住了四十年, 不然是哪裡人?");
 set("inquiry/你是哪裡人","老朽是這裡人! 我在這住了四十年, 不然是哪裡人?");
 setup();
 carry_object(__DIR__"eq/lumber_axe")->wield();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/sandels")->wear();
}
