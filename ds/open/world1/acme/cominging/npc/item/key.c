#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW"�j�c�_��"NOR,({"jail key","key"}));
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","�o��O�ѫ��j�c���_�͡A�W�Y�٨�F"HIW"�i�ѡj"NOR"�r�C\n");
		set("door","jailkey");
		set("value", 1);
		set("no_sell",1);
		set("usage","�}�ҬY�@����");
//		set("amount",1);
	}
	setup();
}
