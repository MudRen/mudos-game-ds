#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","泊浪村漁會");
set("long",@LONG
這裡掛著各式各樣的魚類標本，這裡也是村裡青年成年後所必定要
來的地方，因為所有的漁夫剛開始一定要經過漁會的的訓練後，才有可
能成為獨當一面的老練漁夫，而此地的人們都十分熱愛他們的工作，因
此也沒有什麼人口外流的危機，而目前的漁會頭目是易海，因為它在村
中聲望極隆。
LONG
    );
 set("exits",([
"east":__DIR__"po5",
"north" : __DIR__"po5w-n",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             




