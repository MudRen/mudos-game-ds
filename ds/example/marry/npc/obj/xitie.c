//Obj: /d/ruzhou/npc/obj/xitie.c  �߶K�A�ѥ[�B�b���ЬZ
// llm 99/07

inherit ITEM;

void create()
{
	set_name("�ߩ�", ({ "xi tie","tie"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
   {
		set("unit", "�i");
		set("long","�@�i�j�������l�A�W���g�ۡG\n"
			"���ܻդU�ѥ[�ڭ̪��b���{���Q�ܪ��B§�M���{�ﻫ�Ӫ��B�b�C\n");
      set("material", "paper");
	}
	setup();
}

