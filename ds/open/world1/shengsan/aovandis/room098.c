// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ԥh�V�m��"NOR);
	set("long", @LONG
�o�̬O�Ԥh�̽m�ߧޯ઺���ҡA����Ԥh�ɮv�b�o�̻{�u���оɥL��
�ǥ͡C�|�P���ɶǥX�Ԥh�̾޽m�ɩҵo�X�������o���n�A�ªZ���s�n���A
ı�o���Z�}���O�ӥ����˪������C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room086",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}