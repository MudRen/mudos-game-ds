#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"石室"NOR);

 set("long",@LONG
你來到這個巨大的石室, 石室中央放著一個寬大的石桌, 石桌上有各
式各樣的藥材, 散發出濃厚的藥味, 看來是剛剛才採集下來的, 各種藥草
所散發出的味道在石室裡混合成一種奇異的味道, 令人有在夢中, 輕飄飄
的感覺, 有幾個天梟教的教徒在石桌前對藥材做分類, 對你的來到毫無感
覺, 看來經過傳言的重大變故後, 給他們所帶來的創傷至今還深深影響著
他們吧.
LONG
    );
 set("exits",([ "east":__DIR__"guild1",
                "west":__DIR__"guilda",
                "south":__DIR__"birdpilla8",
    ]));
 set("item_desc",(["石桌":"
                這是一張巨大的石桌, 上面光滑而平整, 石桌\n
                上有剛剛才採集下來的藥材, 你不禁奇怪在這\n
                山洞中, 怎麼能採集到如此新鮮的藥材呢?\n",
  ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

