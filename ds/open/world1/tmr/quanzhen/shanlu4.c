// /d/quanzhen/shanlu4.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�D��");
        set("long", @LONG
���B���׫n�s�s�}�C�ޮo���׫n�s�A�ۥj�H�ӴN�O���N�W�H�C
�����t�a�C����_�̵ª����s�A�F�ܰ��誺�����A�䶡��V�Q�l���A
�s���K�ʾl���C�����U���׫n�s���١C���F�i�ݨ��@�y�x�q�C����O
�@���q���K�L�����R�p���C���_�i�W�׫n�s.
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup" : __DIR__"shanlu8",
                "east"    : __DIR__"puguangsi",
                "west"    : __DIR__"shanlu5",
                "south"   : __DIR__"shanjiao",
        ]));

	set("coor/x", -3130);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
