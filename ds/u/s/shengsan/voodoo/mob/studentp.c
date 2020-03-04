#include <path.h>
inherit NPC;

void create()
{
	set_name("入門新生", ({"student"}) );
	set("race", "人類");
	set("gender", "女性");
	set("level",40);
	set("age", 16);
	set("long", "她是一個剛入門的教徒\n");

        set("chat_chance",50);
	set("chat_msg",({
	   (:command,"east":),
	   (:command,"west":),
	   (:command,"south":),
	   (:command,"north":),
	   (:command,"up":),
	   (:command,"down":)
           }));

	setup();
	
    carry_object(SHENGSAN+"item/potion");
}
