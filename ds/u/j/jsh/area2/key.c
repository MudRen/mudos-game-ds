#include <ansi.h>
inherit ITEM;  
inherit F_UNIQUE;

void create()
{
        set_name(HIW"白光之鑰"NOR,({"white-light key","key"}));
        set("long",@long
楊過極為保存的東西，不知道有什麼作用，只看見鑰匙
背面刻著幾個微小的字，『只門若開，邪物併出』，不
知蘊藏著什麼意思？
long
                );

        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "支");
                set("volume",5);
                set("value", 5000); 
                set("door","whitekey");
        }
        setup();
}


