#include <room.h>
inherit ROOM;
void create()
{
 set("short","秘室中");
 set("long",@LONG
你經過千辛萬苦的過程, 總算開啟了鎖住這裡的秘門, 可是一走
下來你就感到一股強大無比的氣勢迎面襲來, 把你壓得險險無法呼吸
, 這個秘室看起來應該是個練功房. 你眼前竟然有一名已經滿頭白髮
面容蒼老的神秘人士, 他身上所散發出來的真氣佈滿整個秘室, 難道
他就是.........!?
LONG
    );
 set("exits",([ "up":__DIR__":secret2_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
