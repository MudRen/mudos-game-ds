inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�A�~��V�˪L�F���ڶi�A�ӴH������_���[�j�A�Pı���H���I��
�H�Ө����ˤl�A��Ǫ������]������L�O�A�o�˪��˪L��b�O�@�L
�ͮ�A�O�H�L�k���������P�A�F�_�M��n���U���@�����C
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t16",
  "southwest" : __DIR__"t13",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}










