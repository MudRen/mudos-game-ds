// Room: /d/xiangyang/anfugate.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�w���ϸŪ�");
	set("long", @LONG
�o�O�w���ϸŪ����j���A�ɥ֥]�����G�����I���A�W����
��ө��̮̪������F�j���򳬡A�̭��o�ǥX�@�}�}�^���n�A�M
���f���±��ܤ���աC�Q�ӳo�Ӧw���Ϥj�H����l�٬O�L�o�Z
�����C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"anfupailou",
	]));

	setup();
	replace_program(ROOM);
}