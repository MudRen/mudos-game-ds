inherit ROOM;

void create()
{
        set("short", "�{�N�p�շ|ĳ��");
        set("long", @LONG
�{�N�p�էŮv�̰Q�ת��a��.........
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
