#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name( "野人大頭目", ({ "redhair captain","captain","wildman","man"}) );
        set("long",@long
    野人大頭目長的非常的高大，滿頭的紅髮雜亂無章，不時地的往你這
兒望來，似乎隨時都會攻擊你似的，瞧他身材略有點肥胖，不似其它紅髮
族人般那麼勇健。
long
);
        set_race("human");
        set("title","紅髮");
        set("age", 42 );
        set_attr( "dex" , 30 );
        set_skill("whip" , 140);                  // 鞭法
        set_skill("parry", 100 );
        set_skill("dodge", 100);
        setup();
        set_level(20);
        advance_stat("hp" , 500);
        advance_stat("nina" , 300);
        do_heal();
        carry_object(__DIR__"obj/creeper-whip")->wield();
		carry_object(__DIR__"obj/monster_pants")->wear();
		carry_object(__DIR__"obj/bone-earring")->wear();
}

void init()
{
    ::init();
/*
    add_action("intercept", "go");
    add_action("intercept2", "north");
*/
}

int intercept(string arg)
{
    if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "將你攔了下來。\n");
    do_chat((: command, "say 你這外人去去去，不要來我們這兒鬧事。":) );
    return 1;
}

int intercept2()
{
    if(!this_player()->visible(this_object()) ) return 0;
    write( name() + "將你攔了下來。\n");
    do_chat((: command, "say 你這外人去去去，不要來我們這兒鬧事。":) );
    return 1;
}

