// Room: /d/gumu/qinshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", HIC"�^��"NOR);
	set("long", @LONG
�@�i�ۮ�(table)�A�@���۹��A��W��ۤ@��j�^�A�O�p�s�k���
�ɨ輾�^���h���a��C�C�C�^���͸͡A���H�M�M�A���ޤH�ߦ������A�P
�@�L���C
LONG	);
	set("exits", ([
		"west" : __DIR__"mudao18",
	]));
	set("item_desc", ([
		"�j�^"   : HIC"�o�O�@��~�N�������j�^�A�^���j��A�tĭ�Ⱦ��C�^�W��ۡ��ܻ� ��� �筷�����Ӧr�C\n"NOR,
		"table" : "��W��ۤ@��j�^�C \n",
	]));
	setup();
}

void init()
{
//	add_action("do_tan", "tan");
	add_action("do_tan", "play");
}

int do_tan(string arg)
{
	mapping fam;
	object me = this_player();
	int c_exp, c_skill;

    return notify_fail("�A���D�j�ӶǤH�A�L�k�⮩�j�ӪZ�\\�C\n");

	c_skill=(int)me->query_skill("force", 1);
	c_exp=me->query("combat_exp");

	if (arg == "qin")
	{
		if(!(fam = me->query("family")) || fam["family_name"]!="�j�Ӭ�")
    return notify_fail("�A���D�j�ӶǤH�A�L�k�⮩�j�ӪZ�\\�C\n");
		if (me->query("qi") < 30 || me->query("jing") < 30)
			return notify_fail("�A�믫�驿�A���h�����@�|�A�Ӽu�^�a�C\n");
		write(HIC"�A���ؽղz�@�|�𮧡A�߯����R�����^�Ӽu�C\n"NOR);
		if (c_skill < 50 )
			return notify_fail("�A�u�F�b�ѡA�^�n��Y�~��A�A�٬O�u�֪�h�a�C\n");
		if (me->query_skill("force", 1) > 100)
		{
			message_vision(
HIC"$N���H�����A�ĤJ�^�ҡA���H�^�n�A���n�u�D�G\n\n"
HIY"�ɮ��@�n�� �ʷʨ⩤��\t�B�I�H�� �u�O����
�a�ѯ� �ɯɥ@�W��\t�֭t�ֳӥX �Ѫ���
���s�� �ϫB��\t�ܮ��^�� ���ЫU�@�X�h�b
�M���� ���S�I��\t�����ٳѤF�@�̱߷�
�a�ͯ� ���A�I��\t�������b èè����\n"NOR,me);
			return 1;
		}
		if( c_skill > 100)
            return notify_fail("�A���\\���A�u�^�w�L�q�_�A�צ椺�O�C\n");
		write("�A���H�����A�ĤJ�^�ҡA�����߮𥭩M�A�P���u��۵M�y�ʡC\n");
		me->receive_damage("qi", 15+random(10), me);
		me->receive_damage("jing", 15+random(10), me);
		if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("force", random(me->query("int")) );
		return 1;
	}
    write("�A�n�u����H\n");
	return 1;
}

