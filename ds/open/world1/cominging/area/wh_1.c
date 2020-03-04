#define NOW_ROOM "/open/world2/lichi_town_1/map_5_6.c"
#include <path.h>
#include <ansi.h>
inherit ROOM;

static int *crystal = ({ 1,1,1 }); // �]�w�����s�b�� (����,�զ�,����) 0 ���S�� 1 ���s�b�i�Ѥ� 2 ���u�s�b���L�k�ϥ�
static string *crystal_kind = ({ "purple", "white", "red" }); // �]�w���������� (get��)
static string *crystal_color_kind = ({ "[0;35m����[0m", "[1;37m�զ�[0m", "[1;31m����[0m" });
string *locate = ({ "map_1_4.c", "map_1_5.c", "map_2_5.c", "map_3_5.c", "map_4_5.c", "map_5_3.c", "map_5_4.c", "map_5_5.c", "map_6_3.c" }); // �e�y�y�D
string *crystal_file = ({ COMINGING_PAST + "area/obj/purple_crystal.c", COMINGING_PAST + "area/obj/white_crystal.c", COMINGING_PAST + "area/obj/red_crystal.c" }); // ����

string query_crystal();
void random_moving(string file);
void show_message(object me, object ob);
void control(int flag);

void create()
{
/*
�o�̴N�O�ɤ����}�F, �R���۷î�, �X�G�Ů𤤩Ҧs��, ���ɬO����,
�o�䦳�ө_�����W�l, �O�@��[0;35m����[0m������, �����o�X�F�@�}�}�����~,
���۫K��X�\�h���X��, �]�\�o�ӴN�O���ɿ��̩Ҩ������a�U�����ӷ�
�@�� 3 �ؤ��P�C�⪺����, ���O�O[0;35m����[0m�B[1;37m�զ�[0m�B[1;31m����[0m������(crystal)�C
*/
	set("short", "[1;36m�ɤ����}[0m");
	set("long", @LONG

LONG	);
	set("exits", ([
  "out" : __DIR__"map_1_2.c",
]));
	for(int x=0;x<sizeof(crystal);x++)
		if( crystal[x] == 1 )
		{
			set("item_desc/crystal", "�W�l�W���۴X�ؤ�����" + query_crystal() + "�A���p�A�Q�N�����_, �i�H�յۥ�(get)�C\n");
			break;
		}
	setup();
}

string query_long(int raw)
{
	int q = 0;
	string out = @LONG

�o�̴N�O�ɤ����}�F, �o�N�O���ɿ��̩Ҩ��������������Y, �R���۷�
��, �X�G�Ů𤤩Ҧs��, ���ɬO����, �o�䦳�T�ӥ۬W, �۬W�W, ����
LONG;

	if( query_crystal() == "" )
		out += "�@�ӭӦ���l��j�p���}�A�W�����O�Ū��A�ſ������@���C\n\n";
	else out += query_crystal() + "\n\n";
	return out;
}

string query_crystal()
{
	int q;
	string out = "";
	if( crystal[0] == 1 )
		{ out += "[0;35m����[0m������"; q = 1; }
	if( crystal[1] == 1 )
		{ out += ((q==1) ? "�B" : "") + "[1;37m�զ�[0m������"; q = 2; }
	if( crystal[2] == 1 )
		{ out += ((q==2 || q==1) ? "�B" : "") + "[1;31m����[0m������"; q=3; }
		// �P�_�O�_ q == 1 �� 2 �A�[�W�᭱�ɥR, �[ q=3 �O�ȫe���S�� query ��.
	return out;
}

void init()
{
	add_action("do_get", "get");
	add_action("do_lay", "lay");
	add_action("do_cast", "cast");
}

int do_get(string arg)
{
	object me = this_player();
	string temp;
	int flag;

	if( !arg || sscanf(arg, "%s crystal", temp) != 1 )
	{
		write("�p�G�A�Q�n�����o�̪�����, �Х� get <�C��> crystal�C\n");
		return 0;
	}

	flag = member_array(temp, crystal_kind);
	if( flag == -1 || crystal[flag] == 0 )
		return notify_fail("�o�̨S��"+to_chinese(temp)+"�o���C�⪺�����I("+flag+")\n");

	if( me->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������T\n");

	if( !me->query_temp("invis") )
	{
		message_vision("$N�յ۱N" + crystal_color_kind[flag] + "���������_�K\n", me);
		message_vision("  ����, �]���o�Ǥ����L���e�j, ��M$N�@�Ӥ��p��, �q$N���⤤�Ƹ�, �������, �Q�����R���F�K\n", me);
	}
	else
	{
		write("�A�յ۱N" + crystal_color_kind[flag] + "���������_�K\n");
		write("  ����, �]���o�Ǥ����L���e�j, ��M$N�@�Ӥ��p��, �q$N���⤤�Ƹ�, �������, �Q�����R���F�K\n");
		message_vision(HIC"��M��, " + crystal_color_kind[flag] + "���������J�F���̡K�I\n"NOR, me);
	}

	call_out("random_moving", 10, flag);
	crystal[flag] = 0; // �Ϥ������s�b = 0;
	control(1);
	return 1;
}

int do_lay(string arg)
{
	object me = this_player(), ob;
	string temp;
	int x, flag;

	if( !arg || sscanf(arg, "%s on stone", temp) != 1 ) return notify_fail("�A�Q�n�񤰻�F��H(lay <����> on stone\n");
	if( !(ob=present(temp, me)) || living(ob) ) ob = present(temp, environment(me));
	if( !ob || living(ob) ) return notify_fail("�o�̨S���o�˪F��C\n");

	for(x=0;x<sizeof(crystal);x++)
		if( crystal[x] == 1 ) flag = 1;

	if( flag == 1 ) return notify_fail("���@�ѤO�q���ۧA��o�F��W�h�A�i��O�W���٦��S�ʪ��F��I\n");
	if( ob->id("crystal") )
	{
		switch(ob->query("id"))
		{
			case "purple crystal":
				crystal[0] = 2;
				break;
			case "white crystal":
				crystal[1] = 2;
				break;
			case "red crystal":
				crystal[2] = 2;
				break;
		}
		show_message(me, ob);
		destruct(ob);
	}
	else return notify_fail("�A�oı�N" + ob->name(1) + "��W�h�S������Ƶo�͡A��O�S���F�U��...\n");
	return 1;
}

int do_cast(string arg)
{
	object me = this_player();
	int x, flag;

	if( me->is_ghost()) return notify_fail(" �A�{�b�٬O����a\n");
	if( me->is_busy() || me->is_block() )
		return notify_fail("( �A�W�@�Ӱʧ@�٨S�������M������G��C)\n");
	if( sizeof(me->query_temp("is_busy")) ) return notify_fail("�A�{�b���b���S�ŬI�k�C\n");
	if( environment(me)->query("no_magic") || environment(me)->query("no_cast") )
		return notify_fail("�o�̤�����G��C\n");
	if( !arg || arg != "god-fire on the crystals" ) return 0;

	if( !me->query_spell("god-fire") )
		return notify_fail("�A�٨S�ǹL���G��C(god-fire)\n");

	for(x=0;x<sizeof(crystal);x++)
		if( crystal[x] == 0 || crystal[x] == 1 ) flag = 1;

	if( (int)me->query("mp") < 25 ) 
		return notify_fail("�A���k�O�����C\n");

	if( flag == 1 ) return notify_fail("���~�I�i��O�]���۬W�W�٦��Ŧ�S��Ϊ̬O�쥻�����������U�I\n");

	me->start_busy(2); //�I�k�ʧ@�ɶ�
	me->receive_damage("mp", 20); //�I�k��MP

	message_vision("$N����X�Q�A���ۻy�D�G"HIW"�u"HIG"�Ѧa�X�w�A���X���A�|�ɦX�ǡA�����X���H���ġC"HIW"�v\n"NOR,me);

	message_vision(RED"\n\n �u���@�D�D"HIR"���y"NOR RED"���V�����ӥh�K�K�@���G�����}�l�ĤơA�����S��_�F...\n"NOR, me);

	for(x=0;x<sizeof(crystal);x++)
		crystal[x] = 1;

	control(2);
	return 1;
}

void show_message(object me, object ob)
{
	int i, t = 0;
	string msg, msg1;

	if( !me || !ob ) return;
	if( crystal[0] == 0 )
		{ msg1 += crystal_color_kind[0]; t=1; }
	if( crystal[1] == 0 )
		{ msg1 += ((t==1) ? "�B" : "") + crystal_color_kind[1]; t=2; }
	if( crystal[2] == 0 )
		{ msg1 += ((t==1 || t==2) ? "�B" : "") + crystal_color_kind[2]; t=3; }
	if( msg1 ) msg = "�A�ٮt" + msg1 + "�X�Ӥ���";
	if( t == 0 ) msg = "�A�u�t�I�X"HIR"���Z�u��"NOR"�ӿĤ���(cast god-fire on the crystals)";
	message_vision("$N�N$n��b�۬W�W" + msg + "�C\n", me, ob);
	return;
}

void control(int flag)
{
	object now_room = load_object(NOW_ROOM);
	int x, j = 0, uj = 0;
	for(x=0;x<sizeof(crystal);x++)
	{
		if( crystal[x] == 0 ) j++;
		if( crystal[x] == 1 ) uj++;
	}
	if( j == 3 && flag == 1)
	{
		message("world:world1:vision", HIY"��M�A����������֡A�˪L�����@�D������M�_�F�K�I\n"NOR, users());
		// ���U�Ӫ��O�{�N���ܤ�
		tell_room(now_room, HIY"��M�@�}�ᦱ�A�Aı�o�@�}�ѱۦa��A���O�^�L������èS���o�{����A�O���O�Y�����F�H\n"NOR, ({ }));
		now_room->set_water(0);
		return;
	}
	if( uj = 3 && flag == 2)
	{
		message("world:world1:vision", HIY"�s�Y�������S��������_�F�K\n"NOR, users());
		// now's change
		tell_room(now_room, HIR"��M�@�}�ᦱ�A�Aı�o�@�}�ѱۦa��A���O�^�L������èS���o�{����A�O���O�Y�����F�H\n"NOR, ({ }));
		now_room->set_water(1);
		return;
	}
}

void random_moving(int flag)
{
	object crystal_move = new(crystal_file[flag]), room;
	if( !crystal_move )
	{
		CHANNEL_D->do_channel(this_object(), "sys", "error: /open/world1/cominging/area/wh_1.c error �ǤJ��");
		return;
	}
	room = load_object(locate[random(sizeof(locate))]);
	crystal_move->move(room);
	tell_room(room, HIG"�q�W���M�@�ӪF��y�F�L�ӡK\n"NOR, ({ }));
	return;
}

int *query_x()
{
	return crystal;
}
