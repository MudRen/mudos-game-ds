#include <room.h>
inherit ROOM;
void create()
{
        set("short","���]");
        set("long", @LONG
�o�����]�ݰ_�ӥͷN����, ���M�u���x�d�M�@��p�G���Q����
���L, �i�O�ݱo�X�ӥL�̤Q������. �o���T�i��l�����E���F��
�C�ӤH. �b�o�د���~�����]�঳����h�H, �A���Tı�o���I��
��.
LONG
        );
        set("exits", (["out":__DIR__"mountdown3",]));
	set("light",1);
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
