inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�A�Ө�F�˪L���F�n��A�o�̪����Q���}�֡A�Pı���ӹ�l����
�l�A�o�̴N�O���n���ǥX�a�I�A�A���e���ۤ@�Ӿ��ҡA�L���G���F�@�I
�ˡA�I��ۧA���]�\�N�O�L���D�u�n�C
LONG
        );
        set("exits", ([
  "northwest" : __DIR__"t14",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}









