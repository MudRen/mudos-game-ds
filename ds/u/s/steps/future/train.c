#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�K�����[��");
        set("long", @LONG
�o�O�@�C�ө��q���M�a�y���K���A�o���K���]�p�D�`�W�S�A�|�Ѳ���
���N�H�e��ت��a�A�D�`���Ĳv�C�a�M�o���K���w�g�ئh�~�A���O�̵M�g
�`���H�ϥΡA�i�����@�ΫD�`�C
LONG
        );
	set("no_clean_up", 0);
	set("no_kill",1);
	set("no_magic",1);
	set("no_recall",1);
	setup();
}