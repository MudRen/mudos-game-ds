#include <ansi.h>
inherit NPC;
void create()
{
	set_name("雲嶽",({"yuen yuo","yuo","yuen"}));
	set("long" ,
    "你眼前見到的此人身材高大, 面貌俊朗, 眼神內殮, 他就是向雲堂堂主\n"
    "雲天翔的大兒子, 武功\在向雲堂中名列前矛, 僅次於雲天翔及盧賢兩人, 最近\n"
    "為了武林大會的事正忙得不可開交....\n"
    );
	set("attitude", "friendly"); 
	set("level",30);
	set("age", 21);
	set("title",HIC"向雲堂"NOR"大少堂主");
	set("class1","向雲堂");
	create_family("向雲堂",1,"大少堂主");
	set("chat_chance",4);
	set("chat_msg",({"雲嶽從衣中拿出一本很厚很厚類似名冊之類的簿子, 翻開慢慢檢視.\n",
			 (:command,"think":),
			 (:command,"exert cloudsteps":),
			 (:command,"exert cloudblade":),
			 (:command,"exert cloudfist":),
			 "雲嶽似乎太忙了, 因此沒有注意到你的存在.\n",
                         "雲嶽望了你幾眼, 向你打了個招乎, 然後又低頭忙去了.\n",}));
	set("chat_chance_combat",100);
	set("chat_msg_combat",({(:command,"exert cloudblade":),
				(:command,"exert cloudforce refresh":)}));
	set_skill("unarmed",55);
	set_skill("blade",70);
	set_skill("dodge",70);
	set_skill("force",45);
	set_skill("parry",65);
	set_skill("cloudblade",70);
	set_skill("cloudfist",55);
	set_skill("cloudforce",55);
	set_skill("cloudsteps",70);
	set("guild_gifts",({3,4,6,7}));
	setup();
	carry_object(__DIR__"eq/boots")->wear();
	carry_object(__DIR__"eq/broadblade")->wield();
	carry_object(__DIR__"eq/goodcloth")->wear();
	carry_object(__DIR__"eq/belt")->wear();
}

