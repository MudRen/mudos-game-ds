#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�a�U�K��");
	set("long",@LONG 
�o�̬O�@���a�U�K�ǡA�|�P����O�٫O����h������A��M�o�̤~���
�ئn���[�C������ݥh�A���������i�H�ݨ�@�ǤH�v�A���G�ٯ�ť������n
�M�L�������n�C�A���T�h�áA�쩳�O����H�|�b�o�ئa�D���O�H
LONG
);
	set("exits", ([ /* sizeof() == 1 */
                   "west" : __DIR__"base_5",
               ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}