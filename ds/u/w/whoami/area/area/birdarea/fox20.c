#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"狐穴"BLK"－"NOR"深處");

 set("long",@LONG 
一來到這, 你赫見地上有許多屍骸, 看來是有不少的人在此
送命了. 當你還滿懷疑問的同時, 你身邊的小女孩似乎有點詭異
LONG);
 set("no_clean_up", 0);
 setup();
}           

