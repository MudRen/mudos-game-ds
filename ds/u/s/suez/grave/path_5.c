// Room: /u/s/suez/grave/path_5.c

inherit ROOM;

void create()
{
	set("short", "���Ѿb��");
	set("long", @LONG
���n�y�s�A���ܶ��ѡC�o�̴N�O�n�y�s���_�I�F�A�����j�D�]�Ȧ���
��A�A�W�h�N�O�n�s�p�D�F�A���n�y�s�A���H���A�_�h���B�K�D�p���R��
�A�Ӧ���������Ϫ����Цa�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"path_6",
  "eastup" : __DIR__"path_4",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
