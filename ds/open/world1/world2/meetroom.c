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
	"up"     :       "/u/e/eeman/workroom",
        ]));
        setup();
      call_other("/obj/board/now_b","???");
}
