// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�\\�U"NOR);
	set("long", @LONG
�o�̬O�@���\�U�A�~�������C�����s�A�]�ܧO�o�A���U�ئn�Y�n�ܪ�
�\�I�A�C�Ө�o�Y�L���H���O�٤����f�����n�Y�C�ӥB�o�̪��A�ȺA�פ]
���t��C�A�ݨ�@���P�l(note)�C
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
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room107",
	    "west" : __DIR__"room069",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}