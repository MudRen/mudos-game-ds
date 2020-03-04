
#include <ansi.h>
inherit __DIR__"boat.c";

void create()
{
    set_name(HIG "獅頭鷹展王船" NOR, ({ "pudu boat","boat" }) );
    set_weight(600);
        set("long",@LONG
王船是中元節普渡最重要的儀式，你可以在王船上放置祭品及香燭，
當放置夠多的祭品之後，就能找個河湖地帶，焚燒(burn)王船進行醮
典，以普渡受難的孤魂野鬼。
獅頭鷹展王船上的空間比較大，可以放置三千件物品。

你可以使用「inspect」指令來檢視王船上已經放了多少東西。
你可以打「 help 中元節」獲取更詳細的資訊。
LONG
);
    set_max_capacity(3000);
    set_max_encumbrance(3000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "個");
        set("value", 100);
    }
    setup();
}

