inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�A����F�˪L���շt�B�A�o�̬ݨӴN�s���������Ӷi�ӡA�O�H����
�ۥD����i�F�_�ӡA�A�[�WŢ�n�۾�y�˪L���޲��𮧡A�u�O�ܨϤH�`
�ȡA�����D�������ӫe�i�A����s�@�I�n�����S���C
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t3",
  "west" : __DIR__"t5",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








