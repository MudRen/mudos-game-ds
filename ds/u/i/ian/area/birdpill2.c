#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"山洞內"NOR);

 set("long",@LONG
在你好奇心的引誘下, 你亦步亦趨的走到山洞中, 山洞中除了洞口
及山洞斜頂上的小洞外透入的微微亮光外, 沒有其他的光源, 你只能靠
這一點點微弱的光源在山洞中艱難的走著, 你可以感到在你每踏出一步
[B, 都在山洞黑暗處造成一陣騷動, 你可以感覺到石壁不尋常的粗糙, 在
這裡, 時間是那麼的長, 感覺上, 黑暗中好像有一雙雙的眼睛正在偷偷
的看著你...
LONG
    );
 set("exits",([ "out":__DIR__"birdpill",
                "north":__DIR__"birdpill3",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

