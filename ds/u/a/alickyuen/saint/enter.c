// Room: /u/a/alickyuen/area/enter.c

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CDoor�ICyberZoo[2;37;0m");
	set("long", @LONG
�o�̬OSaint�̳̦��W������ʪ���A�o�̪��ʪ����O��Saint�����
�a��s�X�Ӫ��A���O�L�̳��i�H�ͨ|���C�]���Ҧ����ʪ����t���h���ؤF
�A�ҥH���ӥ@�ɪ��d�����O����ƪ��C�A�i�H��J���B�R���J�h�ݰʪ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"door.c",
  "enter" : __DIR__"enter2.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
