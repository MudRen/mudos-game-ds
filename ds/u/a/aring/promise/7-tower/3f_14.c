#include <ansi.h>
inherit ROOM;

string *exitss = ({
__DIR__"3f_1",__DIR__"3f_2",__DIR__"3f_3",__DIR__"3f_4",__DIR__"3f_5",
__DIR__"3f_6",__DIR__"3f_7",__DIR__"3f_8",__DIR__"3f_9",__DIR__"3f_10",
__DIR__"3f_11",__DIR__"3f_12",__DIR__"3f_13",});

void create()
{
        set("short", HIY"沙龍土屋"NOR);
        set("long", 
"這是一處都無的破屋，裡頭一些單調的擺\設，在旁有些許\神像，
看每尊神像上都有許\多的灰塵，不知道要不要幫它們擦乾淨。
"); 
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"statue" : 1,
        ]));
       set("light",1);
       set("exits", ([ 
                "south" : exitss[random(sizeof(exitss))],
]));
        setup();
}

