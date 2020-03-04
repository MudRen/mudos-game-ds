#include <ansi.h>
#define OUT_ROOM "/open/world1/acme/area/moon/room7"
inherit ITEM;
void create()
{
    set_name(HIR"������"NOR,({"moon crystal","crystal"}));
        set("unit", "��");
        set("long",@LONG
        
  �A�ͦV�e�h�A�J�Ӫ��[��ۤ����C�o�Ӵ��o�۲H������~�����j����
  �A���ӴN�O���ǻ�����������(The Crystal of Moon-Soul)�F�C��
  ���������O�Ҧ���ڤH����𯫪��ڷ��A�p�G�A�V���@�۬�ë����
  �����w�|���ƻ�_�����Ʊ��o�͡C

LONG
);
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
	if(arg!="crystal" && arg!="moon crystal")
	{
		notify_fail("�A�n�擄��ë�i?\n");
		return 0;
	}

	message_vision("$N���W�����V�ۤ������q��ë��...\n",me);
	write("���M���}�C�I���n���b�A�������T�_�C\n");
	if(me->can_move(OUT_ROOM))
	{
		tell_room(environment(me),me->name()+"�����������L�v�L�ܤF�C\n",({me}));
		write(HIC"\n\t�^���l����!!!  ���N���^�Ҧ�....\n\n"NOR);
		me->move(OUT_ROOM);
        write("  ��A�w�w�i�}�����ɡA�o�{�w�g�^��F�J�����e�C\n");
		tell_room(environment(me),me->name()+"��M�q�J���I�ᨫ�F�X�ӡC\n",({me}));
		return 1;
	} else
	{
		write("���G����Ƴ��S�o��..�Aı�o���G���ӹ�l�C\n");
		return 1;
	}
}
