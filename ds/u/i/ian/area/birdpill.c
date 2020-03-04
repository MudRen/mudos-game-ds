#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"山洞前"NOR);

 set("long",@LONG
在你眼前, 是一個山洞的洞口, 裡面黑漆漆的, 看起來陰森而可怕
, 不知道裡面有沒有野獸居住, 如果讓牠衝出來攻擊你, 可不是鬧著玩
的, 想著想著, 你似乎已經可以看到那張牙舞爪的野獸朝你狂奔而來, 
你不禁想趕快離開此地...
LONG
    );
 set("exits",([ "enter":__DIR__"birdpill2", 
    ]));
 setup();
 replace_program(ROOM);
}
