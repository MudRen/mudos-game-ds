// corpse.c
#include <ansi.h>

inherit ITEM;

int decayed;

void create()
{
	set_name("�L�W����", ({ "corpse" }) );
	set("long", "�o�O�@��L�W����C\n");
	set("unit", "��" );
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short()
{
         string str;
	str = name() + "(" + capitalize(query("id")) + ")"; 
//	if(desc=query("status_desc")) str+=" "+desc;//��ܥثe���A�Υ���
	return str;
}

void decay(int phase)
{
	object *inv,env;
	int i;
	decayed = phase;
	if(!this_object()) return;
	env=environment(this_object());
	if(!env)
	{
		destruct(this_object());
		return;
	}
	switch(phase) {
		case 1:
			tell_room(env, query("name") + "�}�l�G��F�M�o�X�@�����D���c��C\n" );
			switch(query("gender")) {
				case "�k��":
					set_name("�G�ꪺ�k��", ({ "corpse", "����" }) );
				case "�k��":
					set_name("�G�ꪺ�k��", ({ "corpse", "����" }) );
				default:
					set_name("�G�ꪺ����", ({ "corpse", "����" }) );
			}
			set("long",	"�o�������M�w�g���b�o�̦��@�q�ɶ��F�M�����o�ۤ@�ѻG�ͪ����D�C\n");
			call_out("decay", 200, phase + 1);
			break;
		case 2:
			tell_room(env, query("name") + "�Q���j���F�M�ܦ��@���e���C\n" );
			set_name("�\\�����e��", ({ "skeleton", "�e��" }) );
			set("long", "�o���e���w�g���b�o�̫ܤ[�F�C\n");
			call_out("decay", 100, phase + 1);
			break;
		case 3:
			tell_room(env, "�@�}���j�L�M��" + query("name") + "�Ʀ����ǧj���F�C\n" );
			if( environment() )
			{
				inv = all_inventory(this_object());
				if(sizeof(inv)>0)
				for(i=0; i<sizeof(inv); i++) 
				{
					if( inv[i]->query("no_drop") ||
					inv[i]->query("no_put") )
						destruct(inv[i]);
					else inv[i]->move(environment());
				// alickyuen�W�[�H�Wno_drop no_put�]�w
				}
			}
			destruct(this_object());
			break;
	}
}

object animate(object who, int time)
{
	object zombie;

	if( !environment() ) return 0;
	if( !who ) return 0;
	if( this_object()->query("race") != "human" && this_object()->query("race") != "�H��" ) return 0;

	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
        if( strsrch(query("name"), "���L��") == -1 ) zombie->set_name( (string)query("victim_name") + "���L��", ({ "zombie" }) );
	else zombie->set_name( (string)query("victim_name") , ({ "zombie" }) );
        tell_room(environment(this_object()), RED"\n\t��M�����A"+this_object()->name()+"�o�Ͳ����ܦ��L�͡I�C\n\n"NOR);
	zombie->move(environment());
	zombie->set("level", who->query("level") + 1);
	CHAR_D->setup_char(zombie);
	foreach(object oo in all_inventory(this_object()) )	{ oo->move(zombie); }
	zombie->animate(who, time);

	destruct(this_object());
	return zombie;
}
