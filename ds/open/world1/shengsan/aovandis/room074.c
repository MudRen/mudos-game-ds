// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Z���M�橱"NOR);
	set("long", @LONG
�A�ݨ���W�αM�d���\�ۦn�h�U���U�˪��������Z���A�ݨ�o�Ǥ��g
���A���m�ʪ��İʡA�p�G�ݭn�i�H�����R�A�Q�n���Z���C�A�`�N����W
���ӥΤ�O�v�����i�ܵP(note)�C
LONG
	);
	set("item_desc", (["sign":@NOTE
[1;32m
�G�i�P�W�g��:

		buy       �V����R�F��
		list      ����|�i�D�A�o�̽�Ǥ���
		value     ����|�i�D�A��o��F��L�|���A�h�֪���
		sell      ��Y�ӪF��浹����
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room062",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}