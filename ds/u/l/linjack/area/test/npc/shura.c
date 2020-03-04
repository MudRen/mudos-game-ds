#include <ansi.h>
inherit NPC;
void create()
{
	set_name( HIC"四靈劍王"NOR,({"shura sword master","master","shura"}));
	set("long" ,
	"他的形體若有若無, 如實似幻, 你根本無從判辨他真正的身體在哪裡,\n"
	"聽說他本是古劍亭上的修劍人, 但是數年之前就已經消聲匿跡了.....\n"
        "傳說他習得一套曠世劍法, 曾在古劍會之上力挫六大劍派的高手。\n"
	);
	        set("attitude", "friendly"); 
	set("level",100);
	set("age", 52);
	set("nickname", " 狂 雷 動 驚 " );
	set("combat_exp", 300000+random(77777));
    set("chat_chance",5);
	set("chat_msg",({(:command,"say 唉, 為什麼總是有最後一道關卡突不開.":),
			 (:command,"sigh":),
			 (:command,"say 我自知大限將至....天啊..給我一點機會吧.":)}));
	set("chat_chance_combat",18);
        set("chat_msg_combat",({(:command,"say 嘿, 別小覷我老人家.....":),
                                (:command,"say 哼, 我是不想枉開殺戒, 你納命來吧....":),
				(:command,"exert thundersword":)}));
	set_skill("unarmed",70);
	set_skill("sword",90);
	set_skill("dodge",80);
	set_skill("force",90);
	set_skill("parry",90);
        set_skill("thundersword",120);
	setup();
	carry_object(__DIR__"eq/d_boots")->wear();
	carry_object(__DIR__"eq/shurasword")->wield();
	carry_object(__DIR__"eq/d_cloth")->wear();
}

