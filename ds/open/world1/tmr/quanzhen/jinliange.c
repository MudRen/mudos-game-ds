// jinliange.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�o�����զ��׫n�s�s�y���A�ζջᬰ�I�n�C�����իᦳ�@�f�J
�f�ʪ���u�A�u���Ѻ�z���A�������H�A�b��a�ᬰ���W�A���֤H�S
�O�Ӧ��A�u���F���o�������Ӫw���C���x�e���@���۸O(shibei)�A��
�F�@�����������֡C���n�ݥh�O�@���s���C���訫�O�@���d�骺�s���C
LONG
        );
	set("resource/water", 1);
        set("item_desc", ([
                "shibei"  : 
"

                �� �� �� ��
                �� �� �� �A
                �� �� �^ ��  ��
                �B �p �� ��  �n
                �J �� �X ��  �s
                �A �A �A �A
                �j �� �C �s
                �� �� �G �s  ��
                �� �� �J ��  ��
                �� �� �� ��
                �� �� �L ��
                �C �F �C �F

",
        ]));

        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"     : __DIR__"shanlu10",
                "southdown"  : __DIR__"shanlu9",
        ]));
        set("objects", ([
		CLASS_D("quanzhen")+"/yu" : 1,
        ]));

	set("coor/x", -3130);
	set("coor/y", 30);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}
