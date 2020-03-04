#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "光明頂");
        set("long",@LONG
這理是光明頂，環顧四周，原來這裡就是揚名江湖以久的明教，身
旁豎立一塊碩大的石碑，上面刻道：【當今武林誰人能比，唯我
明教獨步江湖。】前方有一座富麗堂皇的宮殿，上面寫著【聖明宮
】三個大字，明教創立至今已有二十多年，手下十幾萬教徒遍布各
地是武林中數一數二的大幫，想必明教定是臥虎藏龍，高手雲集之
地。
LONG
        );
        set("light",1);
        set("exits",([
  "east": __DIR__"saintming",
]));
        set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
        set("ming_club_out",1); //明教出口
        setup();
}

