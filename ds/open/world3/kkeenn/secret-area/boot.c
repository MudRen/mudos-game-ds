#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Train Station");
        set("long", @LONG
四周的人群十分擁擠，在旁邊的高架上有一個身穿藍色電車制服的公
務員這在販售車票，在正前方有一塊電字公佈欄，在上面打著：
《       [35m [0;1m�[1mn[1m�[1mR[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mA[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m[[1;36m�[1ma[1m�[1mU[1m�[1m�[1m-[1m>[1m�[1mD[1m�[1m�[1;35m][0m  [0m        》

( 提示: 買票請用Buy Ticket )
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "out":__DIR__"sec8.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/trainman.c" :1,
]));

        setup();
        replace_program(ROOM);

}
