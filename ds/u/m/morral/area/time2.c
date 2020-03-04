#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIC"時空導覽室---A.D 2015"NOR);
set("long",@LONG
你一走進這裡，發現自己正浮在半空中！而腳底下是一群人，
衣著華麗，正在大聲歡呼中！這是怎麼回事呢？只見旁邊浮現了
一行字，也許看看那些字(look word)可以了解前因後果。
LONG);
set("item_desc", ([
"word":@NOTE
Ａ•Ｄ ２０１５年 世界政府的產生

所謂的第一世界(first world)-北美，歐洲，亞洲地區的
高度工業國家，經過10年來的努力，終於將龐大的貿易體
系合併，成立了所謂的GB，Golbal Market，全球市場。
並且，利用當時一位哲學家-馬特•漢斯(Matt Hans)的"
社會自治"理論，想要完成維護人權，推動社會計畫，和健
全法律基礎的目標。而整個計畫，便由這位漢斯博士來擔
任。
透過對聯合國(UN，United Nation)中體制重新歸畫，並對
所謂的第二世界強權國家-蘇聯，中國有效的議事控制(縮
減否決權之類)，世界的新秩序來臨了。


NOTE
 ]) );
set("exits",([
"north":__DIR__"time3",
"south":__DIR__"time1",
]));
set("light",1);
setup();
replace_program(ROOM);
}

