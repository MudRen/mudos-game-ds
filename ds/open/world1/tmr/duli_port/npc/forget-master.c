#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("夢遺大師", ({ "forget master", "master"}) );
        set_race("human");
        set("age", 80);
        set("long",@long
這是一位德高望重的大師，其在佛學上的造詣無人可以匹敵。
具說他已看透生死，可以得知過去，預言未來。
long
);
        set("title","方丈");
        set("chat_chance", 5);
        set("chat_msg", ({
                 "夢遺大師從你面前滑了過去，但又從你背後滑了出來，真是詭異莫測...\n",
                 "夢遺大師對著你說道：「這位施主對於過去有什麼煩惱嗎？可以跟老納我談談心喔...」\n",
                  "夢遺大師對著你說道：「我瞧這位施主滿嘴油膩，想必一定家財萬貫吧，要不要捐點香油錢呢？(exchange)」\n",
         }));
        setup();
}

void init()
{
        ::init();
        add_action("do_exchange","exchange");
}

int do_exchange(string arg)
{
        object me,card;
        me = this_player();
    
        if( me->query("bank_money") < 10000000 )
                return notify_fail("你雖然想要捐錢，但是你發現你的銀行存款不夠。\n");
        me->add("bank_money", -10000000 );
        card = new("/d/cards/card-02.c");
        card->move( me );
        log_file( "CARD", sprintf("[%s] %s exchange 「記不住的過去」。\n" , ctime(time()), geteuid(me) ) );
        message_vision( "$N捐獻了筆香油錢給夢遺大師，也獲得了一張卡片做為獎賞。\n" , me);
        return 1;
}


