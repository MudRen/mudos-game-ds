// zhufeng.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�׫n�s�D�p");
        set("long", @LONG
���ɧA�w���b�׫n�s�D�p�A�����󬰼s��C���C��h�A�s�s�ɬҫm
�˦b�}�U�C�����c���A��[�˦b�s�y�B�A�����ͽ��C�u�����ַ��t���G
�_�s�����A����ᬰ�����C�@������ (stone)�ߦb�@�ǡA���G��F����
�F��C����M�n�U�O�@���s���C
LONG    );
        set("item_desc", ([
                "stone"  :
"
                ��H�k�B�����n���l
                ���Ǹ��B���H��~��
                �פJ�_�^�_�P���}��
                �n�D���������Q�E�`
                �s��D���u�Ѵ��|��
                �A�A�A�A�A�A�A�A�A
                ���G�������y�\\�z��
                �եP�߮ɵ������M�i
                �⦹���Τ����ؤѾ�
                �Ϭۦ����ﻴ��@�U
                ���J�ӾڨB�I�h�W�i
                �C�C�C�C�C�C�C�C�C
"
        ]));
        set("outdoors", "forest");
        set("exits", ([
                "westdown"  : __DIR__"shanlu2",
                "southdown" : __DIR__"shanlu1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

