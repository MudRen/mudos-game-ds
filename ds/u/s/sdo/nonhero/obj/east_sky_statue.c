#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name(HIC"東方持國天天王雕像"NOR,({"east sky statue","statue" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long",@LONG
此天為護世四天王之一，專守護東勝神洲地域，其梵名為提頭賴吒，
譯作持國，或安民。常住天宮，是須彌山的第四層，在東勝神洲的黃
金埵，為乾達婆眾之部主。以其能護持國土，亦能令人民悉得安穩，
故名持國天。身顏白色微綠，雙手抱琵琶而彈，身穿鎧甲天衣。此天
本誓為善賞、惡罰、護持國土，此其持國安民尊名之由來，即在此。
在諸佛淨土壇城中，司守護東門之職，主司息災之責。
LONG
                );
                set("no_get",1);
                set("no_drop",1);
                set("value", 100000);
                set("unit","座");
        }
        setup();
}