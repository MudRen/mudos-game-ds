inherit BULLETIN_BOARD;

void create()
{
        set_name("ＢＵＧ留言板", ({ "board" }) );
        set("location", "/open/world2/anfernee/start/bug");
        set("board_id", "bug_b");
        set("long","當你遇到DS中最強的怪獸..BUG時, 就來這裡post. 好讓巫師幫你除掉牠。\n" );
        set("master", ({ "shengsan", "luky", "linjack", "tmr", "acme", "cominging" }));
        setup();
        set("capacity", 200);

}

