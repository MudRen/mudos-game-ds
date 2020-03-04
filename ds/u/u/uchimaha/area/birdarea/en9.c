#include <ansi.h>
inherit MOBROOM;
void create()
{
set("short","東北澤林");

set("long",@LONG
你繼續往北前進, 一陣陣的風撲面而來, 原來樹
上有一堆的蟬正在那嘰嘰的叫著, 但是到了這裡, 卻連
一隻蟬都沒有, 一陣陣的血腥味隨著風飄散過來, 氣氛
中帶了一點恐怖, 在路旁有一個沾滿血的木牌(sign)。 
LONG
    );
 set("item_desc",([
        "sign":"你朝這木牌看了看, 發現上面有幾個大字,

        "HIR"前方有  殺  人  狐!!!"NOR".\n",

        ]));
        set("exits",(["northwest":__DIR__"en10",
                      "south":__DIR__"en8",
              ]));
 
 
        set("chance",80);
        set("mob_amount",3);    
        set("mob_max",15);
        set("mob_object",({     
            __DIR__"npc/fox2",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
}
