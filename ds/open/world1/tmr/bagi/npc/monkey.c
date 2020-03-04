#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW "白毛大猿" NOR,({"white monkey","monkey"}) );
        set("long",@LONG
一隻白毛大猿，獨居在此山谷，得天地之靈氣，雖已年過八十，仍蹦
跳自如，不見老樣。其眼神深邃中透露著一股靈性。
LONG    
        );
        set("race", "野獸");    
        set("unit","隻");
        set("age",80);
        set("level",30);
        set("chat_chance",10);
        set("chat_msg",({
        "白毛大猿一屁股坐在地上，望著一株野花發起呆來...\n",
        "白毛大猿大眼汪汪地望了你一眼。\n",
        "白毛大猿對著你叫了聲：「吱∼」\n",
        }) );

        set("attitude", "heroism");    
        set("limbs", ({ "頭部", "腹部","胸部","腳","尾巴" }) ); 
        set("verbs", ({ "bite","claw" }) );
        setup();
         carry_object(__DIR__"obj/paper");
}

