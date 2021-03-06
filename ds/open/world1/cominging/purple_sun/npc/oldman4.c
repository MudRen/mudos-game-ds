// 老人 4 : 殘左腳的老人 ( 周進山 )

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( "周進山", ({"jinn-shan jou", "jou", "shan", "jinn", "jinn-shan" }) );
	set("long", @LONG
一位身形憔悴的老人，他的左腳似乎被某個高人所擊，致現在已廢。
LONG	);

	set("title", HIY"紫陽四隱 - 周"NOR);
	set("gender", "男姓");
	set("race", "人類");
	set("age", 80+random(30));
	set("level",40);
	set("evil",20+random(20));
	set("attitude", "heroism" );

	set_skill("dodge", 70+random(10));
	set_skill("parry", 50+random(20));
	set_skill("unarmed", 65+random(30));
	set_skill("sword", 78);
	set_skill("force", 100);
	set_skill("sorgi_sword", 75);
	set_skill("moon_force", 70);

	map_skill("force","moon_force");
	map_skill("sword","sorgi_sword");

	set("chat_chance", 3);
	set("chat_msg", ({
  (: command,"sigh" :),
}));
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
  (: command,"exert moon_force recover" :),
  (: command,"angry" :),
  (: command,"say 真他奶奶的, 連老人都趕欺負..":),
}));
	set("inquiry", ([
  "惡捕快" : "這個捕快可真是可惡... 欺善怕惡, 專門欺負咱們這種老頭子, 下手還很狠, 不讓人有反擊的機會, \n            幸好,.. 在之後, 聽說有個刺客把他給暗殺了, 真是大快人心. \n",
  "刺客" : "這名刺客聽說後來躲到了西域去了, 也無後續了... ",
]));

	setup();
	carry_object(__DIR__"wp/old_long_sword.c")->wield();
	carry_object(__DIR__"eq/slipshod_cloth.c")->wear();
	carry_object(__DIR__"eq/slipshod_boots.c")->wear();
}
