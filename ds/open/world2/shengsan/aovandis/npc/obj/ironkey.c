//key for locked door
#include <ansi.h>
inherit ITEM;

void create()
{
set_name("�Q�r�_��",({"iron key","red","key"}));
	set_weight(200);
	set("unit", "��");
	set("long",
		"�@��ܱ`�����K�s�Q�r�_�͡A�A�ݨ�o���_�ͪ��I���٨�F�@��[��]�r�C\n"
		);
	set("door","ironkey");
	set("value", 50);
	set("usage","�}�ҬY�@����");
        //set("amount",1);
}
