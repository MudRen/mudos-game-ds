#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"天靈石室"NOR);

 set("long",@LONG
你一走到這間石室, 就被人們給圍繞, 這裡的教徒不分男女, 或坐或
立, 俱都穿著採藥的衣服, 看來剛才在大廳看到的藥材, 就是他們努力的
結果了, 這裡人有的高談闊論, 有的小聲而語, 有的互頃心聲, 有的談天
說地, 無話不說, 也無話不吵, 不過, 大部份是在討論剛才採藥所發生的
趣事, 如果受的了他們身上的藥味的話, 倒是可以坐下來聽一聽.
LONG
    );
 set("exits",([ "south":__DIR__"guild1", 
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

