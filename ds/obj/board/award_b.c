#include <ansi.h>
inherit BULLETIN_BOARD;

string *wiz = ({ "cominging","acme","tmr", "wilfred", "alickyuen", "faceoff", "uchimaha", "nye" });
void create()
{
        set_name("獎賞紀錄板", ({ "board" }) );
        set("location", "/open/world2/anfernee/start/award");
        set("board_id", "award_b");
        set("long",HIR"請巫師在獎賞之後一定要"HIC"註解"HIR"已獎賞的文章, 謝謝. \n" );
        setup();
        set("master", wiz);
        set("capacity", 50);
}

