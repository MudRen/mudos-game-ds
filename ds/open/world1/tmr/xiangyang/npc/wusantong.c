// wusantong.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("�Z�T�q", ({"wu santong", "wu", "santong"}));
	set("gender", "�k��");
	set("age", 55);
	set("long", "�@�O�j�v���|�j�̤l���@�A�{�b������U���t�B���T�u���C\n");
 	set("attitude", "peaceful");
	
	set("per", 17);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	
	set("combat_exp", 100000);
	set("score", 20000);
	 
/*
    set_skill("kurong-changong", 50);
    set_skill("finger", 50);
    set_skill("sun-finger", 50);
    set_skill("cuff", 50);
    set_skill("jinyu-quan", 50);
    set_skill("dodge", 50);
    set_skill("tiannan-step", 50);
    set_skill("parry", 50);
    
    map_skill("force", "kurong-changong");
    map_skill("finger", "sun-finger");
    map_skill("cuff", "jinyu-quan");
    map_skill("dodge", "tiannan-step");
    map_skill("parry", "sun-finger");
*/
	
	setup();
	
}
