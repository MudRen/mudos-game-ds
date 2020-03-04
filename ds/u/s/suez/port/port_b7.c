#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",GRN"地下遺跡"NOR);
	set("long",@LONG
地下河流經這裡形成了一道地下瀑布，在黑暗中閃耀著光輝的狂想曲
，巨大的水流奔洩著，怒吼著這地底的廣大及神秘。往瀑布四週的岩壁上
看去，可以發現這裡的岩壁似乎是由石塊堆砌而成的，再仔細一看，原來
瀑布其實是由一個巨大的遺跡上流洩而下。被水流沖蝕著的遺跡，已經無
法再訴說那輝煌的歷史，只剩空虛的身軀讓我們這些人去想像而已。
LONG 
);	
	set("light",0);
	set("world","world1");
	setup();
	replace_program(ROOM);

}