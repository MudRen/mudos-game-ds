inherit ROOM;
void create()
{
set("short","��}");
set("long", @LONG
�A�n���e���p�F���, �o�o�{�o�̥|�B�º�����, �ڥ��ݤ������F
��, �A����ҧA�Ӥ����~��ݦb�o�a��_���������G�����p��.
LONG
);
set("exits", ([ 
                "north"  : __DIR__"tree3.c",
                "out"  : __DIR__"tree2.c",
                           ]));
         set("no_clean_up", 0);
setup();
        replace_program(ROOM);
}

