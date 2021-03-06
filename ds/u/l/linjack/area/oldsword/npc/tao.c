#include <ansi.h>
inherit NPC;
void create()
{
	set_name("雲濤",({"yuen tao","tao","yuen"}));
	set("long" ,
    "你眼前這人看起來因為喝酒有點過多, 因而有點醉了, 說話有點胡言亂語, \n"
    "不過你從他的面貌看來可以知道此人絕非普通人物, 他就是向雲堂的二少堂主\n"
    "------雲濤.\n"
    );
	set("attitude", "friendly"); 
	set("level",27);
	set("age", 19);
	set("title",HIC"向雲堂"NOR"二少堂主");
	set("class1","向雲堂");
	create_family("向雲堂",1,"二少堂主");
	set("chat_chance",4);
	set("chat_msg",({"雲濤不知從何處拿出一壺酒, 開始喝起酒來.\n",
			 (:command,"zzz":),
			 (:command,"exert cloudfist":),
			 (:command,"exert cloudblade":),
			 (:command,"exert cloudsteps":),
			 "雲濤有點站不太穩, 醉醺醺的樣子.\n",
                         }));
	set("chat_chance_combat",100);
	set("chat_msg_combat",({(:command,"exert cloudblade":),
				(:command,"exert cloudforce refresh":)}));
	set_skill("unarmed",60);
	set_skill("blade",75);
	set_skill("dodge",75);
	set_skill("force",50);
	set_skill("parry",60);
	set_skill("cloudblade",70);
	set_skill("cloudfist",60);
	set_skill("cloudforce",50);
	set_skill("cloudsteps",70);
	set("guild_gifts",({3,4,6,7}));
	setup();
	carry_object(__DIR__"eq/boots")->wear();
	carry_object(__DIR__"eq/longblade")->wield();
	carry_object(__DIR__"eq/goodrobe")->wear();
	carry_object(__DIR__"eq/belt")->wear();
}

