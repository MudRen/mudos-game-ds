// Room: /open/world1/acme/bonze/b5.c

inherit ROOM;

void create()
{
	set("short", "�W�s�p��");
	set("long", @LONG
���X����s�D�A���e�X�{�@���u�e�@�H�q�檺�ۤl�p�|�A����
��骺�V�W�L�ۡF�D�����󽯥͡A���G���F��b������઺�n�ۧA��
�A�A����ı�a�����x�ġA�u�Ʊ�֨����}�o�s���A�^�쫰�����C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"b6",
  "northdown" : __DIR__"b4",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
