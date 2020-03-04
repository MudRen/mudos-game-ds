#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"狂龍幫"HIM"－"HIY"狂龍堂"NOR);
	set("long", @LONG
    這�堿O狂龍四堂的首堂 －【狂龍堂】
雖然狂龍幫在江湖有很大的名氣，但亦有不少人膽敢挑戰狂龍幫，
所以本堂就是負責狂龍幫四周的安全。又因常有各幫各派的高手
來挑戰，所以本堂亦是四堂�堙A最多高手的地方。
你看到四周牆上掛滿了各類兵器，還有寥寥數張石椅。
除此之外，沒什麼特別之處。
LONG
	);
	set("exits",([
  "southwest" : __DIR__"dragon.c",
	"down" : __DIR__"bank",
]));
	set("item_desc",([
  "石椅" : "用石雕成的一張椅子，你看到旁邊的龍紋千變萬化，那雕刻的師傅可真是厲害呀！\n",
]));
	set("light",1);
set("no_goto",1);
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
	setup();
}
