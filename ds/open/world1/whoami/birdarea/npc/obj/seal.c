#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("召喚符",({"summon seal","seal","_SUMMON_SEAL_"}) );
        set("long",@LONG 
一張用來召喚封印怪獸的符•這符佈滿了密密麻麻的文字，你看
來看去卻也看不出個理所然來•你注意到了這符的背面似乎寫著
你熟悉的文字：
             封•••人間•••
                                  後面的就什麼也沒有了•         
LONG);
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","張");
                set("value",0);
        }
        setup();
}

