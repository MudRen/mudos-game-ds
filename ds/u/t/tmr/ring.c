#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name(HIW "蒂芬妮鑽戒" NOR,({"tiffany ring","ring"}) );
        set("long",@LONG
這是Tiffany中頂級的六爪鑽戒，使用六爪鉑金設計，將十克位鑽石鑲在
戒環上，最大限度設地襯托出了鑽石，使得光芒得以美方位折射。這枚高貴
的蒂芬妮鑽戒，象徵了 Tmr 對 Rurumi 永�琱�變的愛情。
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");       
                set("value",999999999);          
                set("volume", 2);           
                set("material", "gold");   
        }
        setup();
}

int query_autoload() { return 1; }

