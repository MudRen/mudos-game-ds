#include <ansi.h>
inherit BULLETIN_BOARD;

string *wiz = ({ "cominging","acme","tmr", "wilfred", "alickyuen", "faceoff", "uchimaha", "nye" });
void create()
{
        set_name("��������O", ({ "board" }) );
        set("location", "/open/world2/anfernee/start/award");
        set("board_id", "award_b");
        set("long",HIR"�ЧŮv�b���ध��@�w�n"HIC"����"HIR"�w���઺�峹, ����. \n" );
        setup();
        set("master", wiz);
        set("capacity", 50);
}

