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
        "southeast" : __DIR__"t36",
        "northwest" : __DIR__"t33", 
        "northeast" : __DIR__"t31",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}













