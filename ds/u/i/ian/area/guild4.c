#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"神隼聖廊"NOR);

 set("long",@LONG
你慢慢的走到這些兇猛鳥類的地盤中, 你感覺到自己的雙腿開始發軟,
雖然你已經盡量放慢你的腳步, 但還是有不少小隼在你的驚擾下驚飛而起,
並且用嚴厲的眼光看著你, 好像你是一個做錯事的小孩一般, 如果不是牠們
『鳥』多勢眾, 你一定會狠狠的痛扁這隻小不嚨咚的小不點, 你注意到兩旁
都有洞口, 可以讓隼通過, 讓他們出去覓食, 而且這裡相當乾燥, 提供了良
好的生活環境, 這也難怪這裡會有那麼多隻隼了, 可是, 教徒們如何採集到
藥草, 還是個謎.
LONG
    );
 set("exits",([ "south":__DIR__"guild3",
                "north":__DIR__"guild5",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

