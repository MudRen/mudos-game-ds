// Obj:/d/ruzhou/npc/obj/xijiu.c  �߰s
// llm 99/07

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�߰s", ({"xi jiu", "jiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�@�~���o�Q����P���ˤW���n�s���߰s�~�C\n");
		set("unit", "�~");
		set("max_liquid", 15);
	}
	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�ɭ��J",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
