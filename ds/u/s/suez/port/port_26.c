#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","普爾商會");
        set("long",@LONG
普爾是著了名什麼都賣什麼都收的商人，但是他不是為了金錢，單純
只是對事物充滿好奇而已，如果說他的身體不是那麼虛弱，他一定會成為
冒險家而不是商人。最近他正前往東方大陸進行一宗貿易，所以在店裡見
不到他，這對來買東西的男性是好事，因為這樣就可以見到普爾的妹妹了
。不過對女性顧客就不太好了....
LONG 
);
        set("exits",([
            "west":__DIR__"port_25",
                ]));
        set("objects",([
            __DIR__"npc/cecily":1,
                ]));


        set("world","world1");
        set("light",1);
        setup();
        replace_program(ROOM);

}
