#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me);

int query_pan();

void create()
{
        set_name(HIG"牧神之眼" NOR ,({"pan's eye","eye", "_PAN_EYE_"}) );
        set_weight(10);
        set("long",@LONG
這是一粒雪白的石眼，但是仔細一看卻不像是人類的眼睛，反而
比較像是羊眼。這粒石眼上有不少龜裂的痕跡，看樣子已經存在
超過幾百年了，不知道是從何處的石像上掉落下來的。
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","粒");
                set("value", 10);
        }
        setup();
}