// Room: /d/ruzhou/yamen.c
// llm 1999/07/04

inherit ROOM;

void create()
{
	set("short", "���{���Ū�");
	set("long", @LONG
�o���K�O���{�����Ū��j���A����j�W�A�C�˥���A���`���ءC�ɥ֤j����
���\�ʩ�ۨ��Y�i���R�����۷�l�C�e���Өҳ����@�Ӥj���A��M�O�Ѥp����ޥ�
���C���ݨ�h�N�i�H�ݨ쪾�������j��C
LONG
	);
	set("exits", ([
	   "south" : __DIR__"wangxi-lu",
      "north" : __DIR__"yamen-datang",
	]));
	set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}

