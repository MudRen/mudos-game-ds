inherit ROOM;

void create()
{
set("short", "�R�����p��");
        set("long", @LONG
�o�̬O�R�����_�䪺�p���A�u�۳o�����L�h�N�i�H���W���䪺�C���C��
�_�ݥh���M�O�@�������A�����]�w�g���X�F��l�C�Ӥj���G��O�H�Ԥ���
�a�L�a�y�X���f���ӡC
LONG
        );
        set("exits", ([
     "east":__DIR__"al2",
     "west":__DIR__"al12",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
