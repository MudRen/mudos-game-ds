// shulin2.c ��L
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�p��L");
        set("long", @LONG
�A���b�@���L�����p�D�W�A�|�P���O��C���B���G���@���ؿv��
��ò�q���O���S�F�X�ӡA�]�\���񪺤s�W���@�y�D�[�����C�o�Ǿ�A
�j���s���X�W�r�ӡA���ֳ��w�g�ܪ��F�C
LONG    );
        set("outdoors", "forest");
        set("exits", ([
                "southwest" : __DIR__"shulin3",
                "northeast" : __DIR__"shulin1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

