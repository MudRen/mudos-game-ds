#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("沒熟的魚娃娃",({"wowdream death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",
HIW"    ◢　　　"HIB"    ◢"NOR+HIW"　　　  ◢▇◣    \n"NOR+
YEL"◢"HIY+BYEL"●"NOR+WHT"█"NOR+YEL"◣◢　"BLU"◢"CYN+BBLU"●"HIB+BBLK"█"NOR+BLU"◣"HIB"◢"HIW"　◢◤█◤    "YEL"ο\n"NOR+
YEL"██"HIW"█"NOR+YEL"██　"BLU"██"HIB"█"NOR+BLU"█"HIB"█"HIW"　█████"YEL"ο\n"NOR+
HIY"◥██◤◥　"HIC"◥██◤◥　"HIC+HBBLU"█▆█▆█"NOR+HIY"   ο\n"NOR+
HIW"    ◥　　　"HIB"    ◥　　　"HIC+HBBLU"█▆█▆█"NOR+HIY"   。\n"NOR+
HIC+HBBLU"[2008/08/27 birthday]   ●◥◣◣◣　　　\n"NOR
                );
                set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n突然衝出擋住了這致命一擊!!\n\n"NOR);

        setup();
}


int query_autoload() { return 1; }

