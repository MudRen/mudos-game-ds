#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"東迴廊"NOR);

 set("long",@LONG
這是一條一望無際的迴廊, 似乎沒有盡頭, 你注意到迴廊兩
側都是精美的浮雕, 使你不自禁的讚嘆起來, 你仔細一看, 浮雕
都是一些鳥的圖樣, 顯然尉遲妄雖然痛恨天梟的利益爭奪, 但是
還是沒有忘本, 你不禁對尉遲妄又更深一層的尊敬, 感嘆歸感嘆
倒是這條迴廊什麼時候才能走到盡頭呢?
LONG
    );
 set("exits",([ "east":__DIR__"eastroad2",
                "west":__DIR__"bird5",
    ]));
set("light",1);
set("no_clean_up",0);
 setup();
 replace_program(ROOM);
}
