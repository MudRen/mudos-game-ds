// shanlu4.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�o���s���L�۲׫n�s�D�p�ӤW�A�s���K�ۥ��z�w�X�A�u�e�\�@�H�o
�L�A�ζշ����I�m�C�����B��h�C�s�s��¶�A�C��}�U�A�ʨ������ɦ�
�����A�y�ɥO�H����~�@�A�Q�n���S�@�n�C���F�U�M��W�U�O�@���s���C
LONG    );
        set("outdoors", "forest");
        set("exits", ([
                "westup"   : __DIR__"shanlu3",
                "eastdown" : __DIR__"shanlu5",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

