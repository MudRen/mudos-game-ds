#include <room.h>
inherit ROOM;
void create()
{
 set("short","堂主寢室");
 set("long",@LONG
這就是向雲堂老堂主的寢室了, 裡面的擺設, 以堂主
的身份來說還算頗為簡樸, 只看的到幾本古典和幾個古董,
牆上掛的是已死的夫人畫像, 據說是他親手所畫的. 這邊
擺設的簡單, 可能是追憶剛死一年多的夫人吧. 你可以看
到堂主正在裡面悶悶不樂的休息著.
LONG
    );
 set("exits",([
               "east":__DIR__"inroom1",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
