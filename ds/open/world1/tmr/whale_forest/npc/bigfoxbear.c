// big fox bear.c

#include <npc.h>

void create()
{
        set_name("狐熊", ({ "big fox bear","bear" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw" }) );
        set("age", 12);
        set("long", @long
在你眼前的是一隻正趴在地休息的白色狐熊，瞧它身長約有兩尺左右，
站起來的話，大概還比你高二個頭。
long
        );
        setup();
          set_attr("str",30);        
          set_attr("cor",30);        
        set_stat_maximum("hp",300);
        set_stat_maximum("gin",300);
        heal_stat("gin",300);
        heal_stat("hp",300);
}


