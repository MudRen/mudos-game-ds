//key for locked door
#include <ansi.h>
inherit ITEM;

void create()
{
set_name(HIR"�����_��"NOR,({"red key","red","key"}));
	set_weight(60);
	set("unit", "��");
	set("long",
		"�o��"HIR"�����_��"NOR"�������٨�F["HIY"�s��"NOR"]��Ӧr�C\n"
		);
set("door","redkey");
	set("value", 10000);
	set("usage","�}�ҬY�@����");
        //set("amount",1);
}
