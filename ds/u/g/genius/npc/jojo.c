#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIB"啾啾"NOR, ({"jojo"}) );
	set("long", "一隻會說話的猴子\n");
	set("race", "人類");
        set("evil",30);
        set("title",HIM"魔人"NOR);
	set("age", 5);
	set("level", 100);

	setup();

}
int talk_action()
{
command("ccc");
command("say 我是又善良又可愛的啾啾!!");
command("say 泡泡最可愛ㄌ~~~~");
command("pat jojo");
return 1;
}
