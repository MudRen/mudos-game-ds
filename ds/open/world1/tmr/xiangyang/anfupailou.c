// Room: /d/xiangyang/anfupailou.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�w�����P��");
	set("long", @LONG
�o�̬O�w���ϩ��e���@�y�P�ӡA���F�G�V�A�Ѷ��ɨ�A
�M�F�����N�x���γ����[���˦b��������ģ�U���ձ��M�A����
���סA�O�H�ج����t�A�Pı���~�ޮo���Y�C�A���Y��h�A����
�P�ӤW�|�Ӥj���r���w���ϩ����C�P�ӤU���ۨ⬣�⨺�M�j��
���L�A���n�ۨC�@�Ӿa��o�઺�H�C�_���N�O�w�����j�|�F�C
�n���N�O�����������s���C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"anfugate",
	]));

	setup();
	replace_program(ROOM);
}