inherit ROOM;

void create()
{
       set("short", "�F�[��");
        set("long", @LONG
�o�O����x���F�[�СA�M�����ѵ��i���b�x�̹L�]�C�Ф����\�]�Q
��²��A�u���@�i�˧ɸ��ȡA�ͬ��Q��²��C
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"temple03",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}

