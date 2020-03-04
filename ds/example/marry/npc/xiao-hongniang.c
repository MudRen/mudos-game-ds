//�g�]�l(tubaozi)�i�D�A�Gwoodman@pub.wx.jsinfo.net

// Npc: /d/ruzhou/npc/xiao-hongniang.c �p���Q  �M�o���B�n�ݪ�
// by llm 99/06

#include <ansi.h>

inherit NPC;
int ask_marry();
int ask_guest();

void create()
{
	set_name("�p���Q", ({ "xiao hongniang", "hongniang" }));
   set("long","�o�O�@�Ӫ��o�ܦn�ݪ��p�h�Q�C��F��ڪ����V�W���p�|�l�A��o�U�o�a�i�R�F�C\n");
   set("gender", "�k��");
   set("age", 16);
   set_skill("unarmed", 20);
   set_skill("dodge", 20);
   set_skill("parry", 20);
   set_temp("apply/attack", 30);
   set_temp("apply/defense", 30);
   set_temp("apply/damage", 5);
   set("combat_exp", 3000);
   set("shen_type", 1);
   set("inquiry", ([
		"���B"    : (: ask_marry :),
      "�B§": (: ask_marry :),
      "���B�ݪ�"    : (: ask_marry :),
      "�m���B�ݪ��n"    : (: ask_marry :),
      "�W�h"    : (: ask_marry :),
      "�Ы�"    : (: ask_guest :),
      "�ܽ�"    : (: ask_guest :),
   ]));
   setup();

}
void init()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	::init();
	if( !ob || environment(ob) != environment() ) return;
  	say("�p���Q���H�H�a���D�G������Q�ܨӿ�ߨơA�i�o�n���D�@�ǳW�Z�A�p�G�A�Q���D���ܡA�i�H�ݧڡI��\n");
}

int ask_guest()
{
	object me;
	me = this_object();

	if (me->is_busy())
		return notify_fail("�p���Q���D�G���A�����Z�A�M�ڻ��ܧa�I��\n");
	if( this_object()->is_fighting()||me->is_fighting() )
		return notify_fail("�p���Q���D�G���{�b�S�\�ҡI��\n");
	if( !living(this_object()) )
		return notify_fail("�A�٬O���Q��k��p���Q�Ͽ��a�C\n");
	if ( (string)me->query("gender") == "�L��")
		return notify_fail("�p���Q�H�H�����a�{�l�����h�F�G���A�n���B�H�٭n�ЫȡA�������I�I�I��\n");
	if (((int)me->query("age") < 18) && (me->query("gender") == "�k��")
		||((int)me->query("age") < 16) && (me->query("gender") == "�k��"))
		return notify_fail("�p���Q�H�H�@���D�G���A�M�ڮt���h�j�A�N�Q���B�ЫȤF�H���檺�I��\n");
	if( (string)me->query("class")=="bonze"||(string)me->query("jobname")=="taoist" )
		return notify_fail("�p���Q�׼L�@���D�G���A�i�O���ڶ}�����A�X�a�H��\�൲�B�O�H��\n");
   if(me->query("couple/have_couple"))
   	return notify_fail("�p���Q�_�D�G���z���O�w�g���L�B�F�ܡH��\�ٷQ......��\n");
	write( "�p���Q���G���u����C�C������F���Z�A�N�i�H���C�C���A����N�ЫȤH�F�C��\n");
	return 1;
}

int ask_marry()
{
   object ob;
   if(this_player()->query_temp("marry-book"))
		return notify_fail("�p���Q���Ǥ������F�G���A�o�ӤH��\�|�o�ˡA��褣�O���L�A�@���F�ܡH\n");
   message_vision("�p���Q�I�I�Y�A���X�@���m���B�ݪ��n�浹$N�A���D�G�����B�i�O�@���l���j�ơA\n"
   "�A�@�w�n�J�ӬݬݡA���n�b����ɥX�v�H�A�˱o���]��F�A�B�]�S�����C��\n",this_player());
   ob=new(__DIR__"obj/marry-book");
   ob->move(this_player());
	this_player()->add_temp("marry-book",1);
	return 1;
}
