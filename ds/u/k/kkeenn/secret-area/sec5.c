#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城正中央");
        set("long", @LONG
天空的白雲被強力的磁場強迫排成 Secret City的告示版....

東方: 居民的工作地點[ [0;1;35m�[1mq[1m�[1m|[1m�[1m�[1m�[1m�[0m ]      旅客的休閒地點[ [0;1;35m�[1mQ[1m�[1mG[1m�[1mH[1m�[1m�[1m�[1m�[1m [0m] 
西方: 防衛守護者最愛[[0;1m [1;35m�[1m�[1m�[1m�[1m�[1m�[1m [0m]        流浪旅行者之處[ [0;1;35m�[1ma[1m�[1mU[1m�[1m�[1m�[1m�[0m ]
南方: 商人貨物集中地[ [0;1;35m�[1m�[1m�[1m~[1m�[1m�[1m�[1my[1m�[1mB[0m ]    大家的防守工具[ [0;1;35m�[1mx[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[0m ]
北方: 旅人的最愛地點[ [0;1;35m�[1mS[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[0m ]  唯一留守的老人[ [0;1;35m�[1m�[1m�[1mD[1m�[1m�[1m�[1ma[0m ]
上方: 市民外界聯絡地[ [0;1;35m�[1mq[1m�[1mi[1m�[1ml[1m�[1m�[0m ] 
下方: 孩童老人休息所[ [0;1;35m�[1mW[1m�[1m�[1mK[1mT[1mV[0m ] 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec4.c",
     "north":__DIR__"sec10.c",
     "east":__DIR__"sec6.c",
     "up":__DIR__"mail.c",
     "west":__DIR__"sec8.c",
     "down":__DIR__"sec13.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
