inherit ROOM;

void create()
{
        set("short", "現代小組會議室");
        set("long", @LONG
現代小組巫師們討論的地方.........
LONG
        );
        set("light",1);
        set("exits", ([
     "hall"  :  "/d/wiz/hall1",
	"up"     :       __DIR__"workroom",
        ]));
        setup();
      call_other("/u/e/eeman/now_b","???");
}
