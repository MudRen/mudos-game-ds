//u/c/chiaa/world2/little flower_island/ocean.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HIB"海邊"NOR);
        set("long",@LONG
一片汪洋無際的大海,海中波浪翻騰雲湧,激起疊疊的浪花,
拍打著沿岸,你不覺感嘆大自然的偉大與人類的渺小,
看著這樣的景色,似乎把你的雄心壯志都磨掉了!!


LONG
        );
        set("exits", ([ /* sizeof() == 1 */
      
        "southwest"   : __DIR__"sand1",      //沙灘1
  
       
    ]));
       
            setup();
replace_program(ROOM);
}
