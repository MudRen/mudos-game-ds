#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG "某人" NOR,({"somebody","somebody"}) );
        set("long",@LONG
 傳說當自身武功練至某一境界後，便可以深厚之內力將肉體所隱藏 自古以來從沒人練至境界，但相傳噬(Demon)以達此境界，[37m『[0m來無影去無蹤[37m！』。[0m
LONG    
        );
        set("race", "野獸");    
        set("unit","隻");
        set("age",1);
        set("level",25);
        set("chat_chance",10);
        set("chat_msg",({
        "某人一屁股坐在地上望著一株野花發起呆來...\n",
        "某人大眼汪汪地望了你一眼。\n",
        "某人口中喃喃的唸道：「你看不到我∼你看不到我∼」\n",
        }) );

        set("attitude", "heroism");    
        set("limbs", ({ "頭部", "腹部","胸部","腳","尾巴" }) ); 
        set("verbs", ({ "bite","claw" }) );
        setup();
//暫關        carry_object(__DIR__"obj/paper");
}

