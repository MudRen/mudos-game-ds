#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIG "旱地魃蔥" NOR, ({ "fire-devil onion", "onion", "_FIRE_ONION_" }) );
        set("long", "這是一株從旱魃怪身上取得的蔥條，其味猛烈，是一種神奇的藥草。");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "株");
        }
        set("heal",([
         "ap" : 1000,
         "hp" : 1000,
         "mp" : 1000,
        ]));
        set("value", 2500);
        setup();
}

