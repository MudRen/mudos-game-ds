#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��O�j�|");
	set("long", @long
�o�̥��O�@�~�@�ת�����`����O�j�|���|����a�������A����
�غ��F�ܦh���A���A��A�ٱ��W�F���֤C�m�}�ɪ���O�A�������p��
�e�A�@��H�b�o�����[��A�A�w�Q���o�ݤ��L��ӡC
long);
	set("exits", ([
		"east" : "/open/world1/tmr/area/hotel",
		"west" : __DIR__"en2",
	]));
	set("light", 1);
	set("no_recall", 1);

	setup();
}
