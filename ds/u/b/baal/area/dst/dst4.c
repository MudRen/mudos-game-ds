#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"暗斯德塔"NOR);
        set("long", @LONG
這裡是暗斯德塔圍牆外, 你可以透過圍牆隱隱約約看到
暗斯德塔的上部, 牆上長滿青苔, 圍牆內便是法師們學習與
研究魔法的處所, 裡面所散發的強大魔法能量使得凡人都能
感受到其強大的力量

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "southeast": __DIR__"dst3",
            "northwest": __DIR__"dst5",
            ]));
 set("item_desc",([
           "圍牆":"暗斯德塔的圍牆, 是藉由強大的魔法力量以黑曜石組合而成的, 上面刻滿了蘊藏著強大力
量的魔法咒語, 使得任何意圖對這座塔進行攻擊的人都會遭到難以想像的強大反擊.\n",
"暗斯德塔":"一座高聳入雲的魔法高塔, 魔法師們在此學習並接受試煉, 暗斯德塔是古代魔法師們以其
強大的力量將這世上最具魔力的黑曜石組合而成, 整座塔擁有強大的魔力, 保護著住在裡
面的魔法師們, 相傳有位擁有強大魔力的黑暗司祭意圖以其強大的黑魔法摧毀整座高塔, 
但他的咒語尚未唸完即被智慧之神英特瑟(God of Wisdom-Interser)的降雷給霹成焦灰, 
看見這座高塔同時也受到至少一位神祇的保護.\n",
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
