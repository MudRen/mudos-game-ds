inherit BULLETIN_BOARD;

string *arch = ({ "cominging","acme","morral","tmr", "wilfred" });
void create()
{
        set_name("�Т�կd���O", ({ "board" }) );
        set("location", "/open/world2/anfernee/start/bug");
        set("board_id", "bug_b");
          set("long","��A�J��DS���̱j�����~..BUG��, �N�ӳo��post. �n���Ův���A�����e�C\n" );
        setup();
        set("master", arch);
          set("capacity", 1000);
}

