// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�]�k�Ϋ~��"NOR);
	set("long", @LONG
�M�d�̳��C�۬öQ���Ĥ��A�o���Ĥ��i���O���q���Ĥ��A���̳����U
�ؤ��P���]�k�ĪG�C�b�~�D�ͮɵ���n�ǳƭӴX�~�Ĥ��H�Ƥ��ɤ��ݡC�A
�ݨ���W�a���ۤ@�Ӻ}�G���i�ܵP(note)�C
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
            "east" : __DIR__"room064",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}