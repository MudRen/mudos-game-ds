#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(GRN"草綠鑰匙"NOR,({"grass green key","green","key"}));
        set_weight(50);
        set("unit", "把");
        set("long","這把鑰匙全都是綠色的, 如果掉在草叢間真不知道該怎麼找才找得到!。\n");
        set("door","greenkey");
        set("value",1);
}