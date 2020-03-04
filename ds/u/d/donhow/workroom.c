// Room: /u/d/donhow/workroom.c

inherit ROOM;

void create()
{
	set("short", "�ڷ��Ƕ�");
	set("long", @LONG
�o�̥��O�������W���ڷ����ժ��f�A�@�Ӷǻ����_�����a�C�ժ�
�f�O�ڦ����j�N�ؿv�A��y�ڷ����G�O���ۤk���u�@�ۯ몺�{�{�o��
�A���f�W���۾Ƕ骺���P(table)�A�o��ģ���B�ܥت��ե��C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "longya" : "/u/l/longya/workroom",
  "north" : __DIR__"area/a3",
  "future" : "/open/world3/meetroom",
  "wiz" : "/d/wiz/hall1",
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "table" : "�o�O�ڷ��Ƕ骺���P�A�Ѥ@���Ȧ⪺���Y�Ҩ�s�Ӧ��W���g�F�X�ӥj��(words)",
  "words" : "�A�յۥhŪ�X�o��j��r�A�W���g��'  ��   ��  '�A'�X������'....�o�X�Ӧr",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
