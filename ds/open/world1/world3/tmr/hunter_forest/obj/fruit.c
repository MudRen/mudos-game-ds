#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG "����G��" NOR,({"purply fruit","fruit"}) );
        set_weight(200);
        set("long",@long
�o�O�@���G�֧e���⪺�G��A���o�ۤ@�Ѱs�����A�ڻ���G�״��o�X
�Ӫ��s����O���J�A�`�Q�Ψӻ����Y�ذʪ��C�A�ݪ��X�ӪG�ֲ��p�A
�n��֭�(broke)�U�ӡA�ˤ]�����P�C

long
);
        if(clonep() )
                set_default_object(__FILE__);
        else {
        set("value",1);
        set("material","plant");
        set("volume",1);
	set("food_remaining",2);
	set("heal_hp",20);
	set("heal_mp",20);
	set("heal_ap",20);
        }
        setup();
}

void init()
{
	add_action("do_broke","broke");
}

int do_broke(string arg)
{
	object me,ob;
	me=this_player();
	if(!arg || arg!="����G��") return 0;

	message_vision("$N�N�@���G�ꪺ�֤@�h�h�a��F�U�ӡC\n",me);
	ob=new(__DIR__"fruitb");
	ob->move(me);
	destruct(this_object());
	return 1;
}
