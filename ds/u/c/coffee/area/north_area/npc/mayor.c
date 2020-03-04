#include <ansi.h>
inherit NPC;

void create()
{
        set_name("李村長",({ "mayor lee","mayor","lee" }) );
        set("long","這個村子的村長，平時喜歡做善事，所以得到許\多人的誇獎。\n");
        set("race","人類");
        set("age",60);
        set("level",10);
        set("attitude","friendly");
        set("no_fight", 1);
        set("chat_chance",10);
        set("chat_msg",({
        "李村長嘆道：唉..不知那個印記跑去哪了...\n",
        "李村長很煩惱地走來走去...\n",
        "李村長道：只記得那一天的夜晚，出現一個奇怪的蹤影..早上印記就不見了...\n",
        }) );
     set("inquiry/印記","一個當時我當上村長時拿到的印記，很重要的..\n"NOR);       
     set("inquiry/蹤影","我也看不太清楚，不過聽村民說好像有蹤影跑進古洞...\n"NOR);       
        setup();                
}
