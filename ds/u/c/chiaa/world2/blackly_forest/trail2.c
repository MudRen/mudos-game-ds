//u/c/chiaa/world2/blackly_forest/trail2.c

#include <path.h>    
inherit ROOM;

void create()
{
        set("short", "幽徑");
        set("long", @LONG
這是一條森林中的幽徑,四周林木參天,高聳入雲,盡遮光線,
顯得陰暗之極,在白晝行走,就像在黑夜般伸手不見,加上四週陰森
寒冷,似有鬼魅妖魔居伏,膽子小的人恐怕無法再行走了!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "north"   : __DIR__"causeway2",      //石子路2
    
]));
       
            setup();
replace_program(ROOM);
}

