#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Item Recover Shop");
        set("long", @LONG
這裡就是 Secret City唯一的商店了，看到堆積如山的礦物，和出入
這邊來自各地的貨品，你知道，這裡一定曾經是繁榮過的都市，只是在向
旁邊一看，我勒！又是一台骨灰級的超級機器人....旁邊還貼著童叟無欺
的牌子，現在是西元幾年了阿！還在用這種標語？
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "west":__DIR__"sec3.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/seller.c"   :1,
]));

        setup();
        replace_program(ROOM);

}


