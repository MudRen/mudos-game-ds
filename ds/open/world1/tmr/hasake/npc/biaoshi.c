#include <ansi.h>
inherit NPC;
void create()
{
       set_name("������v", ({ "escort guard", "guard" }) );
       set("title", "�껷��");
       set("gender", "�k��" );
       set("age", 45);
       set("level",15);
       set("long", "�L�O�ӨӦۤ��쪺��v�A���L�Q�~�ӱq�S�^�h�L�A�n���O�b�䤰��F��C\n" );
       set("attitude", "heroism");
       set("chat_chance", 30);
       set("chat_msg", ({
            "������v�n���b�ۨ��ۻy�G�b���O�H�b���O�H \n",
       }) );          
       set_skill("force", 30); 
       set_skill("unarmed", 30);
       set_skill("sword", 30);
       set_skill("dodge", 30);
       set_skill("parry", 30);       
       setup();       
       add_money("silver", 5);
}