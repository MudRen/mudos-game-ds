#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"�i�ܵP"NOR, ({ "sign" }) );
	set_weight(20);
	set("long",
"�@�ӥΤ�һs�����p�i�ܵP�A�W���ټg�ۨǦr�A��M�ݪ��X�ӬO�Ӷm��\n"
"�U�l�Ҽg���r�A�ä���򪺺}�G�A�W���g�ۡG\n\n"
HIC"     �����G 100 ����I�b�o���U�l�W�����@�|��A�i�H��_�@����\n"
"                      �O�Ϊk�O�A���L�]�O�������ˤf�_��N��F\n"
"                      �O����A�X�b�~�C��ӷ������n��k�A�Y�O\n"
"                      �ݭn���믫��n�ǡA���N��J�a�I\n"
"\n"
"     ��J�G 300 ����I��M�N�O�b�o�䪺�ӤW��J�F�A�𮧤@����\n"
"                      ���T�ʤ�����k�A�i��_�@����O�A�ͩR�O\n"
"                      �Ϊk�O�A���L�ѩ�ä��O�ܦn�����E�A�ҥH\n"
"                      �ä��|��_���˪�����C\n"NOR
"\n�Y���䥦������J�W�����D�A�i�H�߰ݤp�G�C\n"
	);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("no_get",1);
		set("no_sac",1);
	}
	setup();
}

void init()
{
	if( environment(this_object())->query("short") )
		set("name", HIC+environment(this_object())->query("short")+"�i�ܵP"NOR );
}