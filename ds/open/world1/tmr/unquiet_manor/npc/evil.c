#include <ansi.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
    set_name("精魅", ({ "evil spirit", "spirit", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
精魅，即精怪，傳說物老則成魅，而且還會加害於人。常見的的精魅
有木魅或山鬼，也有野鼠或狐狸等年老也會成精。
LONG);

    set("age", 500);
    set("level",35+random(5));
	set("title",HIG"無寧莊園"NOR);
    set("race","celestial");
    set("attitude", "aggressive");

    /* 人物動作 */
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }) );

    /* 戰鬥動作 */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_issue :),        
    }) );


    setup();
    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 30 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 30 ) carry_object(__DIR__"obj/q_stone");
    if( random(100) < 50 )	carry_object(__DIR__"obj/blood_meat");
	if(random(100)<50)
		carry_object(__DIR__"obj/yellow-staff")->wield();
	else
		carry_object(__DIR__"obj/yellow-whip")->wield();
}

