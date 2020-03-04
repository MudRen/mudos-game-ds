#include <room.h>
inherit ROOM;
void create()
{
 set("short","佛門齋舍");
 set("long",@LONG
你一進來這裡就聽到幾個佛門中人唸唸有詞的誦著佛經, 桌上有
些飯菜還沒吃完, 不過有幾隻蚊子在上面飛, 大概是菜已經發酸了吧.
四周都被掛上佛經和佛像, 原來的擺飾品全都不見了, 而你眼前的這
幾名法師, 穿著不同於中土, 大概是塞外過來的吧.
LONG
    );
 set("exits",(["south":__DIR__"inroom16",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
