#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("�ͥͳy�Ƥ�", ({ "stream pill","pill" }));
        set("long",
	"�@���դ��z�������Y�A���o�X�@�ѲM�����A���H���K�A���G�K�O����\n"
	"�����W���ˬ�t�ġСu�ͥͳy�Ƥ��v�A�۶Ǩ�s�y�D�`�}���A���T�n�M��\n"
	"�ѯ��F�ĥP��A��v�ҮɡA��n�����|�u�ɸ`�B�ɨ赥���A��ĪG��M�W\n"
	"�C�_�ĦW�������C\n"
	);
        set_weight(500);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
        	set("unit", "��");
		set("eat_msg","$N�Y�U�@�����o�X�M�������ĤY�C");
        	set("eff_msg",HIG "�A��ı�o���ѧN�y�b����¶�ण���A���W���ˤf���G�]����¡�X�F�C" NOR );
	}
	set("value", 300);
	set("heal",([
		"ap": 100,
		"hp": 100,
		"mp": 100,
	]));
	set("cure",([
		"body": 10,
	]));
        setup();
}
