#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIM "點液" NOR,({"dab aqua dragon","dragon"}) );
      set("title",HIM "狡龍" NOR);
        set("long",@LONG
「狡龍  點液」為一太古生物，性喜花香，居於江、湖之中，通長二
十四尺，身略作淡紅色，瞧其兩目如炬，渾身散有淡淡不知名香味。
LONG    
        );
        set("race", "野獸");    
        set("unit","隻");
        set("age",300);
          set("level",40);
        set("attitude", "heroism");    
        set("limbs", ({ "頭部", "腹部","胸部","巨爪","龍尾","背鱗" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_armor",90);
        add("addition_damage",80);
        set("chat_chance_combat",50);
        set("chat_chance", 10);
        setup();
}

