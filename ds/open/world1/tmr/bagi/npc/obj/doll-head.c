#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name("不知名的人頭",({"unknown head","head","DOLL_HEAD"}));
        set_weight(100);
        set("unit","顆");
        set("long",@LONG
這是一顆栩栩如生的假人頭，留著一頭烏黑的長髮，柳葉眉、櫻桃嘴，
一張瓜子臉蛋兒上點著二粒鮮靈活動的眼睛，活脫是個難得一見的美人樣，
但白嫩的臉頰上給人少了一份生氣的感覺。
LONG
                );
        set("replica_ob",__DIR__"left-leg");
        setup();
}

