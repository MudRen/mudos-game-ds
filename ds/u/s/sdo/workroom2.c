#include <ansi2.h>
inherit ROOM;

void create()
{
	set("short", "���P�j�U");
	set("long", @LONG
�o�̬O�֦��_���O�q���j�U�A�ө_���O�q���ӷ��N�O����������
�Ū��C�o�Ӫ��֦��Q���S����O�A�i�H����b�U�ϰ�̡A�i�H���O
�Q���n�Ϊ��]�k�D��C
LONG
	);
	set("item_desc",([
        "�ɪŪ�":"�o�O�@���������۪��A�W���J��۱i���R�������⥨�s�A�ݮݦp��\n"
        	 "���ˤl���H���I�`�ȡA�ϥΤ�k�Ф^�D�� (help door)�������a�I\n",
        ]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"workroom",
	]));

	setup();
}
void init()
{
	add_action("do_help","help");
}
int do_help(string str)
{
	if(str != "door") return 0;
	write(HIW"�A�Q�n��V(pass)����̡H\n"NOR);
	add_action("do_pass","pass");
	return 1;
}
int do_pass(string str1)
{
	if(!str1)
	{
	message_vision(
	HIW"�{�b��h���a�観�G\n\n"NOR
	HIW"1.�L�W�^������\n\n"NOR
	HIW"2.�g���˪L\n\n"NOR
	HIW"3.�L�۪k��\n\n"NOR
	HIW"�ХΡypass �Ʀr�z��V�ɪ�\n"NOR,this_player()
	);
	return 1;
	}
	if(str1 =="1")
	{
	message_vision(
	HIW"$N�ΤO����ۥ۪��A�j�۵ۡG�٤��a�ڥh�L�W�^�����ӡI\n"NOR
	HIW"���M�����ͤ@�ѫܤj���l�ޤO�A�N$N�ԧ�i�h�C\n"NOR,this_player()
	);
	
	this_player()->move(__DIR__"nonhero/h_d.c");
	return 1;
	}
	if(str1 == "2")
	{
	message_vision(
	HIW"$N�s�D�ۥ۪����G���ڥh�g���˪L�աI\n"NOR
	HIW"���M�����ͤ@�ѫܤj���l�ޤO�A�N$N�ԧ�i�h�C\n"NOR,this_player()
	);
	
	this_player()->move(__DIR__"pwest/path1.c");
	return 1;
	}
	if(str1 == "3")
	{
	message_vision(
        HIW"$N��ۥ۪����G�ڭn�h�L�۪k��...\n"NOR
	HIW"���M�����ͤ@�ѫܤj���l�ޤO�A�N$N�ԧ�i�h�C\n"NOR,this_player()
	);
	
	this_player()->move(__DIR__"nonhero/cir12.c");
	return 1;
	}
	else
	{
	write(HIW"�A�Q�h"+str1+HIW"���H�·Цۤv�����a�I\n"NOR);
	}
	return 1;
}
