#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("寶儀娃娃",({"bowie death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",
HIY"   　◢◣◢◣　"NOR+CYN"草原上有對獅子母子　                              "NOR+YEL"◢◣◢◣\n"NOR+
HIY" 　◥◤　　◥◤"NOR+CYN"小獅子問母獅子           母獅子說：             "NOR+YEL"◥◤　　◥◤\n"NOR+
HIY" 　◢　"HIR"∩∩　"HIY"◣"NOR+CYN"「媽媽，"HIM"幸福"NOR+CYN"在哪裡？」  「"HIM"幸福"NOR+CYN"就在你的尾巴上阿」"NOR+YEL"◢　"HIR"︿︿ "NOR+YEL" ◣\n"NOR+
HIY"   ◥"HIG"＞ "HIM"。 "HIG"＜"HIY"◤"NOR+CYN"於是，小獅子不斷地追著尾巴跑......但始終咬不到。"NOR+YEL"◥"HIG"≧ "HIM"。 "HIG"≦"HIY"◤\n"NOR+
HIR"●╮"HIY" ◤◥◤◥"NOR+CYN"  母獅子笑道：傻瓜，"HIM"幸福"NOR+CYN"不是這樣得到的。           "NOR+YEL" ◤◥◤◥ "HIR"╭○\n"NOR+
HIR"  ╰"HIY"(◢◣◢◣)"NOR+CYN" 只要你昂首向前走，"HIM"幸福"NOR+CYN"就會一直跟隨著你          "NOR+YEL"（◢◣◢◣)"HIR"╯\n"NOR
"[2008/08/18 birthday]\n"
               );
                set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n突然衝出擋住了這致命一擊!!\n\n"NOR);


        setup();
}

int query_autoload() { return 1; }
