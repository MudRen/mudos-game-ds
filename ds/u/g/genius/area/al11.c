inherit ROOM;

void create()
{
set("short", "�R�����p��");
        set("long", @LONG
�o�̬O�R�����_�䪺�p���A�u�۳o�����L�h�N�i�H���W���䪺�C���C�o
���񦳤@�ʤ���������j��A���ӥi�H�ݨ�Q���b�Kٲ�����ʡC
LONG
        );
        set("exits", ([
     "east":__DIR__"al12",
     "south":__DIR__"al10",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
