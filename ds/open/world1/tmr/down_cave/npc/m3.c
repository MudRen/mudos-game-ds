#include <ansi.h>
#include <npc.h>

void create()
{
        set_name(HIY"石室守護者"NOR , ({ "gold guard monster","monster" }) );
        set("long",@long
    石室守護者為硬幫幫中極為強大的怪獸，對於組織非常的忠心，您可
以抬頭望見牠駭人的獠牙，上頭正滴著惡臭的流涎，深綠色的眼球好像正
瞪視著您。
long
);
        set("title","硬幫幫");
        set_race("strength");
        set("age", 80);
        set_skill("parry",120);
        set_skill("unarmed",150);
        set_skill("psychical",100);
        set_skill("twohanded blunt",150);
        set("attitude", "aggressive");
        set("froce_ratio",10);        
        set("bounty",([
                "reputation": 30, 
        ]) );
        
        setup();
        set_level(35);
        set_attr("strength",100);
        carry_money("gold", 2);
        carry_object(__DIR__"obj/boots")->wear();
        carry_object(__DIR__"obj/armor")->wear();
        carry_object(__DIR__"obj/belt")->wear();
        carry_object(__DIR__"obj/ring")->wear();
        carry_object("/d/obj/big-blunt.c")->wield();
}

void init()
{
    ::init();
    add_action("intercept", "go");
    add_action("intercept2", "north");
}
int intercept(string arg)
{
        
    if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "一伸掌把你擋了下來。\n");
    return 1;
}

int intercept2()
{
        
    if( !this_player()->visible(this_object()) ) return 0;
    write( name() + "一伸掌把你擋了下來。\n");
    return 1;
}

