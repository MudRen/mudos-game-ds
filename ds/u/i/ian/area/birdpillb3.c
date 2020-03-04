#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"山洞內"NOR);

 set("long",@LONG
一成不變的石壁混淆了你, 你開始覺得心慌意亂, 你開始在這裡隨便
亂走, 想要尋找出出路, 可是只是不斷的面對似乎完全一樣的石壁, 你的
呼吸開始粗重, 心跳開始加快, 你覺得這裡處處充滿危機, 而每一個黑暗
的角落都有人在看著你, 你不禁後悔自己為什麼要到這個山洞來, 現在你
唯一的希望就是頭頂上那那點微弱的光芒不要在此時消失...
LONG
    );
 set("exits",([ "north":__DIR__"birdpillb1",
                "south":__DIR__"birdpillb5",
                "east":__DIR__"birdpillb2",
                "west":__DIR__"birdpillb3",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

