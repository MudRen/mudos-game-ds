// shanlu2.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�o���s���L�۲׫n�s�D�p�ӤW�A�s���K�ۥ��z�w�X�A�u�e�\�@�H�o
�L�A�ζշ����I�m�C�����B��h�C�s�s��¶�A�C��}�U�A�ʨ������ɦ�
�����A�y�ɥO�H����~�@�A�Q�n���S�@�n�C���_�U�O�@���s���C���F�W
�N�O�׫n�s�D�p�C
LONG    );
        set("outdoors", "forest");
        set("exits", ([
                "northdown" : __DIR__"shanlu3",
                "eastup"    : __DIR__"zhufeng",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

