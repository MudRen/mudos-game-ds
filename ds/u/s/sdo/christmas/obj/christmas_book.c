#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("堆雪人活動入門手冊", ({"christmas book","book" }) );
        set("long", 
"這本書是活動單位免費贈送的。裡面寫著基本步驟和小秘訣：\n\n"
"1.首先，堆雪人最基本的就是先做出頭(build head)和身體(build body)。\n"
"2.反覆滾動雪球(roll snowball)和壓實雪球(compress snowball)這兩個動作。\n"
"  這樣雪球才會大，做出來的雪人才會高。至於滾動和壓實這兩個動作的次數請\n"
"  各位參考經驗。\n"
"3.最後就是看各位想什麼時候組合成雪人(build snowman)囉。\n"
"4.基本上，人有失手馬有失蹄，猴子偶爾也會從樹上摔下來。因此失敗時請不要\n"
"  灰心，幾續努力吧。\n"
"5.最後，祝各位佳節愉快。\n"
"                                                          活動單位敬上\n"
	);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "本");
        }
        setup(); 
}