#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"狐穴"BLK"－"NOR"深處");

 set("long",@LONG 
深入狐穴數丈內發現一頭九尾狐狸。你赫見地上有許多屍骸
，看來是許多勇士挑戰失敗的下場。九尾狐正在用那鮮紅眼睛，
充滿殺氣的盯著你，慢慢的靠近....
LONG);
 
 set("no_clean_up", 0);
 setup();
}           

