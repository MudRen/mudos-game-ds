// dingtong.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("���F��", ({ "chen dahai", "chen", "dahai" }) );
       set("title", "��v");
       set("nickname", "�C���C");
       set("gender", "�k��" );
       set("age", 43);
       set("level", 35);
       set("long","
�@�Ө���ϥ��ͪ����j�~�l�A�Ⱦw���|�A�������ħJ�y�ܤ��¥��A
���إ������A�y�����ۤ@�`���C�C�L�O�N���s��U����v���@�C\n" );
       set("attitude", "heroism");

       set_skill("force", 100); 
       set_skill("unarmed", 100);
       set_skill("sword", 100);
       set_skill("dodge", 100);
       set_skill("parry", 100);
//       set_skill("qingmang-sword", 150); 
       setup();
       carry_object(__DIR__"obj/jinjian")->wield();
       add_money("silver", 10);
}

