inherit BULLETIN_BOARD;

string *arch = ({ "cominging","acme","morral","tmr", "wilfred" });
void create()
{
        set_name("ＢＵＧ留言板", ({ "board" }) );
        set("location", "/open/world2/anfernee/start/bug");
        set("board_id", "bug_b");
          set("long","當你遇到DS中最強的怪獸..BUG時, 就來這裡post. 好讓巫師幫你除掉牠。\n" );
        setup();
        set("master", arch);
          set("capacity", 1000);
}

