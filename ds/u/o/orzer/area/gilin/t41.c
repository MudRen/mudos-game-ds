inherit ROOM;
void create()
{
        set("short","���F�˪L����");
        set("long",@LONG
�A�C�C���¦V�˪L�`�B���h�A�b�A���e���۩_�Ǫ��H�Υͪ��A���W
�ǥX�@�}�}�G�ר��D�A��ʤQ���w�C�A�ӥB�����L�����W�@�L�b�I�ͮ�
�A�����D�O����_�Ǫ��F��A���𺥺��ର�@�p�C
LONG
        );
        set("exits", ([
        "northeast" : __DIR__"t42",
        "southwest" : __DIR__"t40", 
        "southeast" : __DIR__"t45",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}













