// Room: /d/ruzhou/xiaozheng.c �p��
// llm 99/02

inherit ROOM;

void create()
{
	set("short", "���{�p��");
	set("long", @LONG
�o���w�g�i�J���{�a�ɤF�C�p���j�A���O��_������D�ǡA�n
��_�����ȤH�K�ϱo�o���C�C�c�a�_�ӤF�C�Ʀܨϱo�o�������a�H�f
�Ƥ֡A��B���O���^�^������ȤH�C
LONG
	);

	set("exits", ([
		"south" : __DIR__"yidao1",
		"north" : __DIR__"ruzhou",
                "west" : __DIR__"yingbin-lou1",
	]));

	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
	]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



