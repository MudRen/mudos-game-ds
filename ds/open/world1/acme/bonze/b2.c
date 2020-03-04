// Room: /open/world1/acme/bonze/b2.c

inherit ROOM;

void create()
{
	set("short", "�s�D");
	set("long", @LONG
�A���i�@�B�H�Ϩu�ܪ��s�D���A�|�襪�k���O�����θy������A
�B���F���u�A���O���ϩ��������W���ʪ����Ω~�a�[��ۧA����ʡA
�|�B�L�H�A�uť�����j��ʪ����B�B�n�T�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"b3",
  "northwest" : __DIR__"b1",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
