inherit ROOM;
void create()
{
        set("short","�s��");
        set("long",@LONG
�A�q�L�F�s�D�Ө�F�@���d�骺�p�|�A�o���誺�s���󬰯U���A
�ӥB�]�����s���A�Pı�ϦӨ��ӭ��K���סA���L�o�٬O����i�`�A�ݨ�
�o�̤]�O���g���H���L�A�u�O�{�b�S���F�C
LONG
        );
        set("exits", ([
  "southdown" : __DIR__"m2",
  "northwest" : __DIR__"m4",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}



