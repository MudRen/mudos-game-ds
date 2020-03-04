/*
  Name: /open/always/paper.c
  Copyright: DS
  Author: Alickyuen & Whoami
  Date: 06/09/05 11:36
  Description: Gift for 2005 Summer Game
*/


#include <ansi2.h>
#include <armor.h>

inherit EQUIP;

void setup();

void create()
{
	set_name( HIW"�կ�"NOR, ({ "white paper", "paper" }) );
	set("long", @LONG
[37m�b�b�b�c�c�c�c�d�d�d�d�e�e�e�e�e�f�f�f�f�g�g�g�g�h�h�h�h�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
[37m�i�i[47;30m2005 Summer Gift By -Alickyuen&Whoami@The.Dream.Of.Seven- [37m�i[0m
[47;30m�b�b�b�c�c�c�c�d�d�d�d�e�e�e�e�e�f�f�f�f�g�g�g�g�h�h�h�h�i�i�i�i[0m

�@�i�S������Ϯת��կȡA�u���k�U�����@��Ӧr�A�γ\�A�i�H���եΥ�
�]�b�ۤv���W����@�����E[ �ϥΤ�k�Ԩ� help gift ]
[Save EQ]
LONG);
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "�i");
		set("volume", 3);
		set("material", "paper");
	}
	set("no_drop",1);
	set("armor_prop", ([
		"armor"		:	-100,
		"damage"	:	-100,
		"bar"		:	-5,
		"con"		:	100,
	]) );
        set("wear_msg", HIG"$N�ܤW$n�F��A��M�@�}�ծ��񨭡A��ӤH���զ�@���I\n"NOR);

	setup();
}

void init()
{
	add_action("do_change", "change");
	add_action("do_help", "help");
}

int do_change(string str)
{ 
	object ob = this_object();

	if( ob->query("equipped") )
		return notify_fail("�Х��Ѱ��˳ơC\n"); 

	switch(str)
	{ 
		case "head":
		case "mask":
		case "neck":
		case "cloth":
		case "armor":
		case "surcoat":
		case "waist":
		case "shield":
		case "finger":
		case "hands":
		case "legging":
		case "pants":
		case "boots":
			set("armor_type", str);
			message_vision("$N����k���$n��X��"+str+"���ҼˡC\n", this_player(), ob); 
			break;
		default:      
			write("�A����k��N�O�S��k��X�o�تF��E\n"); 
			break;
	}

	return 1;
}

int query_autoload() { return 1; }

void setup()
{
	int g,total;
	::setup();
	if( clonep(this_object()) ) return;
	set("armor_type", TYPE_ARMOR); // default type == ARMOR
	if(!query("limit_con")) set("limit_con",weight()/700);
	if(!query("armor_prop/armor")) set("armor_prop/armor",weight()/500);
}

int is_armor(){ return 1; }

int do_help(string str)
{
	if( str == "gift" )
	{
		write(@HELP
���O�榡 : change <�������>

�A�i�H�ϥ�change���O��կȪ�����ʽ���ܡA�Y�կȥi�Hwear�b���W����@�����C 

��������]�A :  
head, mask, neck, cloth, armor, surcoat, waist, shield, finger, hands,
legging, pants, boots.

			Written By Sept 2005 -Alickyuen@The.Dream.Of.Seven-

HELP);
		return 1;
	}
}

// end of file
