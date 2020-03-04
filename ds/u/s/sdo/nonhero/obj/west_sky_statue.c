#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name(HIC"西方廣目天天王雕像"NOR,({"west sky statue","statue" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long",@LONG
廣目天王梵名為毗樓拔叉，譯作雜語、非好報、惡眼、廣目及醜眼雜
色等。彼亦為護世四天王之一，專守護西方，即受持西牛賀洲，常住
須彌山之第四層的白銀埵，為龍族、鬼神之部主。此天王以種種雜色
莊嚴諸根，其本誓為懲罰罪人，使之遇到辛苦後，能起道心。廣目天
身紅色，一面二臂，目圓而外凸，頭戴龍盔，身穿鎧甲，右手捉龍，
左手托塔，於諸佛淨土壇城中，守護西門之職，主懷愛。因其為金翅
鳥所化，能鎮伏龍王，故右手捉龍，表風調雨順。
LONG
                );
                set("no_get",1);
                set("no_drop",1);
                set("value", 100000);
                set("unit","座");
        }
        setup();
}