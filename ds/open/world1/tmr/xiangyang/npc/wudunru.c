// wudunlu.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("�Z����", ({"wu dunru", "wu", "dunru"}));
	set("title", HIY"���t�j�̤l"NOR);
	set("gender", "�k��");
	set("age", 23);
	set("long", "�L�O���t�j�̤l�A�ۻ��Mħ�A�@�Ѩ�߯��������C\n");
 	set("attitude", "peaceful");
	
	set("per", 24);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("inquiry", ([
		"���T" : "���O�ڮv���C\n",
		"���t" : "���O�ڮv���C\n",
	]));

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	
	set("combat_exp", 80000);
	set("score", 20000);
	 
/*    set_skill("force", 50);         // �򥻤��\
    set_skill("huntian-qigong", 50);    // �V�Ѯ�\
    set_skill("unarmed", 50);       // �򥻮��}
    set_skill("xianglong-zhang", 50);   // ���s�Q�K�x
    set_skill("dodge", 50);         // �򥻸��{
    set_skill("xiaoyaoyou", 50);        // �p���C
    set_skill("parry", 50);         // �򥻩۬[
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    map_skill("parry", "xianglong-zhang");
*/
	
	setup();
	
}

