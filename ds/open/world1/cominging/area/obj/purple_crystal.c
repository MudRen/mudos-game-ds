#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("[0;35m������[0m", ({ "purple crystal", "crystal" }));
	set("long", @LONG
�o�O�@���Q���S�������A�O��m�b�ɤ����}�����A�O�q�e�L�j�}���P
�a����A�L���@�������Ҧ����A�ǻ��]���O�b�L�j���L�ڤ��A�b�`�s��
���@�B�}���A�p�G�N���۩�W(lay on stone)�A�N�|�y�X�\�h�����C
LONG	);
	set_weight(9999);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("value", 1);
		set("no_sell", 1);
		set("no_sac", 1);
	}
	setup();
}