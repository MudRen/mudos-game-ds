#include <ansi.h>
inherit NPC;
void create()
{
 set_name("貧農",({"farmer",}));
 set("long",@LONG
一個十萬大山中常見的農夫.
LONG
    );
 set("attitude", "peaceful");
 set("age",40);
 set("gender","男性");
 set("level",15);
 set("chat_chance",10);
set("chat_msg", ({"貧農唱道:三年大旱三年災, 十里種田十里哀. \n",
		  "貧農唱道:缸無粒米怎完稅, 債主日日逼債來. \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
