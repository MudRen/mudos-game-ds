inherit ROOM;

void create()
{
        set("short","��������");
        set("long", @LONG
���B���F�@�ⴡ�b�a�O���Ѻ����C�~�N�ŵL�@���A�A�ݨ즹�C
�����J�a�O���ܨS�`�C�����ǻ����O�i�H�q���t�@�ӪŶ�..���O�u��
���ѭ̤~�i�H�i�J�C�γ\�A�A�i�H�ݬݨ�����C........�@���u�i�H
�ί����ӧήe�C���n�i�H��F�Ѧa�|�|ĳ�ǡC

LONG
        );
        set("objects",([
__DIR__"item/greensword1" :1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room25",
  "north" : __DIR__"room70",
	"up" : __DIR__"bank",
		"east" : __DIR__"left",
		"west" : __DIR__"right",
]));
        set("light",1);
        set("no_kill",1);
set("no_goto",1);
        setup();
        set("stroom",1);
}

