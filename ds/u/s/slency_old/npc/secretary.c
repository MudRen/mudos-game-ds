#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"���"NOR"�p����" , ({ "Slency's personal secretary","secretary" }) );
        set("class","fighter"); 
        set("race", "�H��");
        set("long","�@��f�R�S�ѯu�����ѣ�...�u���L�o����Ƴ����|��..-_-�C\n");
        set("con", 100);
        set("str", 100);
        set("level",20);
        set("age",20);
        set("class1",HIW"�y ILLUSION RISER �z"NOR);
        set("title",HIW"�y ILLUSION RISER �z����"NOR);
        set_skill("sword", 140);
        set_skill("parry",140); 
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        setup();

}
void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "���")
        
 {
	message_vision("��ˤp���ѹ�$N���D�G" HIW "�o��ȤH�A�n, �ݭn����ڴ��z�A�Ȫ��� ^_^�C\n" NOR,me);
        command("wink" + me->query("id"));
 }
	else 
 { 
 	if(me->query("name") == "���s")    
       {
        command("hi dragonku");
       }
	else
 {
	command("say �D�H�A�Ӱ�, ���ӥG�A��N����  ^��^\n");
	command("wink slency");
 }
 }
}

