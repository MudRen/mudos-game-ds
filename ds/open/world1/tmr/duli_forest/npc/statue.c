inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("避邪神像", ({ "repel-evil statue", "statue" }));
        set_weight(99999);
        if( !clonep() ) {
                set("unit", "個");
                set("no_get",1);
                set("container_unit", "尊");
                set("long",@long
這是一尊形相威猛的神像，圓睜的雙眼似乎正瞧著過往的一切事物，
附近的人民將此神像放置在這，就是為了抵擋北邊「血腥荒野」邪惡的妖
魔鬼怪。這神像擺放在此似乎有近百年的歷史了。
long
        );
        }
        setup();
}
void init()
{
        object me=this_player();
        if(me->id("_DULI_FIELD_NPC_") )
                me->force_me("go north");
}

