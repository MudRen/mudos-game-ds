inherit ROOM;
void create()
{
        set("short","�s�Y�U");
        set("long",@LONG
�A��L�F�s�Y�Ө�F�s�Y�U�A�e��O�@�y�s�諸�˪L�A���O�K���Z
�K�A�i�O�o�����ǨӤ@�ѴH��A�O�A�P�줣�H�ӷX�A�˪L�����۩_�S��
�M���A���H�Pı���Ǯ`�ȡA�����D���ۤ���M�I�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"t1",
  "southeast" : __DIR__"m6",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}




