#include <ansi.h>
#define OUT_ROOM "/open/world1/acme/area/sky/room15"
inherit ITEM;
void create()
{
    set_name(HIG"�Ѻ���C"NOR,({"green sword","greensword","sword"}));
        set("unit", "��");
        set("long",@LONG
�@��Ѻ�⪺���C�A�C�������J�a�O���ܨS�`�C�p�G�A�V���@��
��ë(pray)���ܡA�����w�|���ƻ�_�����Ʊ��o�͡C

LONG
);
	set_weight(999999);
	set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
	setup();
}

void init()
{
	add_action("do_pray","pray");
}

int do_pray(string arg)
{
	object me;
	
	me=this_player();
	if(arg!="green sword" && arg!="greensword" && arg!="sword" )
	{
		notify_fail("�A�n�擄��ë�i?\n");
		return 0;
	}

	message_vision(HIG"$N�ۤߪ��V�Ѻ����C��ë�A�@���Ѻ�⪺���~��¶��$N\n"NOR,me);
	if(me->can_move(OUT_ROOM))
	{
		tell_room(environment(me),me->name()+"�����������L�v�L�ܤF�C\n",({me}));
		me->move(OUT_ROOM);
		write(HIG"  �A���e������C�C�a�����A�ӧA�oı�A�w�^�쯫�������C\n"NOR);
		tell_room(environment(me),HIC"��M���@�}�벴���~�A"+me->name()+HIC"�H�ۥ��~�X�{�󦹦a�C\n"NOR,({me}));
		return 1;
	} else
	{
		write("���G����Ƴ��S�o��..�Aı�o���G���ӹ�l�C\n");
		return 1;
	}
}
