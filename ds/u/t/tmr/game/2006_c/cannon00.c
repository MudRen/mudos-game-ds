// 2006/12/14

#include <ansi.h>
inherit __DIR__"cannon_base.c";

int do_wehre();

void create()
{
        set_name(HIY"洲際彈道"HIR"飛彈"NOR,({"ballistic cannon","cannon"}) );
        set("long",@long
夢幻七域２００６聖誕節活動－獵殺聖誕老人之洲際彈道飛彈。
你可以使用ignite的指令來點燃發射沖天炮。
long
);
        set_weight(10);
        set("unit","根");
        set("value", 100000);
          set("min", 100);
          set("max", 120);

        setup();
}

