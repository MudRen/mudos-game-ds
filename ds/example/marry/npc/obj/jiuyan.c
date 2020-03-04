// Obj /d/ruzhou/npc/obj/jiuxi.c
// llm 99/07/09

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("�s�u", ({ "jiuxi" }));
   if( clonep() )
       set_default_object(__FILE__);
   else
   {
		set("long", "�o�O�@�भ������B�����|���B�������s�u�C\n"
   HIG"�K�����L(pingpan)  �ë~�Xü(guogeng)  ���N��H(tipang)\n"
      "�Q�l�۳�(guiyu)    ��ۣ���(caixing)  �M�L�ҳ�(jiayu)\n"
      "�H������(jitang)   �A�ɨ��G(doufu)    ���ѫC��(qingxie)\n"NOR);
		set("unit", "��");
		set("value",1000);
      set("no_get","�A�]�Ӷ¤ߤF�a�H���Q�����o�@�઺�s�u�H�˱o�ʶܡH\n");
   }
   setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me=this_player();
   if( me->is_busy() )
      return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
   if((int)me->query("food")>=(int)me->max_food_capacity() )
	   return notify_fail("�A�w�g�Y�ӹ��F�A�ٷQ�Y���\�H\n");
	switch(arg)
   {
   	case "pingpan":
         message_vision("$N�����D�X�@�����L�N��A���i�L���z�z�����a�Z�_�ӡC\n",me);
	   	me->add("food",8);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water",1);
         break;
      case "guogeng":
      	message_vision("$N��F�@�c�ë~�Gü�A���ڡI���u�O�S���S���C\n",me);
	   	me->add("food",2);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 8);
         break;
      case "tipang":
      	message_vision("$N�e�F�@�j�������N��H�A�T�]��|�a�Y�F�U�h�C\n",me);
	   	me->add("food",20);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 2);
         break;
      case "guiyu":
      	message_vision("$N���X�@���Q�l�۳��A�uı�J�L�ƹ�A�A���L��C\n",me);
	   	me->add("food",10);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 2);
         break;
      case "caixing":
      	message_vision("$N�Ӥߦa�D�F�@�Ǧ⭻�ѥ�����ۣ��ߡA�C�C�a�~���ۡA�u���C\n",me);
	   	me->add("food",10);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 2);
         break;
      case "jiayu":
      	message_vision("$N�@�U�l���X�@���ҳ��A�椣�i�@�a��i�L���C\n",me);
	   	me->add("food",20);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 4);
         break;
      case "jitang":
      	message_vision("$N��ۭ����j�j�a���F�@�f�H�������A�G�u�O�A���L��C\n",me);
	   	me->add("food",2);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water",15);
         break;
      case "doufu":
      	message_vision("$N���_�@�_�A�ɨ��G�t�b�L���A�@�y�����ֺ����������C\n",me);
	   	me->add("food",8);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 1);
         break;
      case "qingxie":
      	message_vision("$N�e���Y�A��}�C�ɴߡA�@�f�@�f�a�m�l�����A�����ĦסC\n",me);
	   	me->add("food",10);
         if((int)me->query("water")< (int)me->max_water_capacity())
		   	me->add("water", 1);
         break;
      default:
      	write("�A�Q�Y���\�H��W���\�h�泣���Y�H\n");
         break;
   }
	return 1;
}
