// dingtong.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�B�P", ({ "ding tong", "ding", "tong" }) );
       set("title", "��v");
       set("nickname", "���Y�D");
       set("gender", "�k��" );
       set("age", 45);
       set("level", 35);
       set("long","�L�O�N���s��U����v���@�A�@���b�o�@�a�M��ۤ@�ӤH�C\n" );
       set("attitude", "heroism");
       set_skill("force", 140); 
       set_skill("unarmed", 140);
//       set_skill("qingmang-sword", 150);
       set_skill("sword", 140);
       set_skill("dodge", 140);
       set_skill("parry", 140);
       setup();
       carry_object(__DIR__"obj/yinjian")->wield();
       add_money("silver", 1);
}
