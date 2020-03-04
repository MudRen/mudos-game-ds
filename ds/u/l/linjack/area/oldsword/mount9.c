#include <room.h>
inherit ROOM;
void create()
{
 set("short","登山陡徑");
 set("long",@LONG
山坡上的花草到這邊已經漸漸消失了, 此地風勢也漸漸轉大,
腳下的巨大石階讓你走起這段路頗為輕鬆, 不過你越往高處望去
, 就越覺得這段路沒那麼好走. 高處的山壁聳入雲端, 你十分懷
疑那邊到底是哪裡?
LONG
    );
 set("exits",([
               "eastdown":__DIR__"mount10",
               "westup":__DIR__"mount8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
