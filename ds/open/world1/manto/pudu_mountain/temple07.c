inherit ROOM;

void create()
{
       set("short", "��[��");
        set("long", @LONG
�o�O����x����[�СA�M�����ѵ��i���b�x�̹L�]�C�Ф����\�]�Q
��²��A�u���@�i�˧ɸ��ȡA�ͬ��Q��²��C
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"temple03",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}

