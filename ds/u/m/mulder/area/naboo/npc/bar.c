#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
	set_name(MAG"�s�O"NOR, ({"bartender","bar"}) );       
	set("long", "�@�Ӱs�O,�A�i�ݥX�L�@�w���D�n�h����Naboo�������C\n");
	set("race", "�H��");
	set("title","�հs�v");
	set("age", 40);
	set("level", 5);
 //               set("talk_reply","�A�����ڤ@�I�p��(help)�ܡH\n");
                set("inquiry/here","ť�A���f���A�n�����O�o�̪��H�A�A�٬O�֨����}�K�o�A���J�˪L�C\n");
	set("inquiry/�˪L","�˪L�D�D�D�D�A�٬O�O�i�J�D�D�A�|�����J����X�^�ӡC\n");
	set("sell_list",([
		__DIR__"obj/whisky" : 8,
		__DIR__"obj/punch" : 10,
		
        ]) );
	setup();
}
void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("age") != "18")
        
 {	
	message_vision("�`�Ю��l��$N���D�G" HIW "�A�n!�A�n....^_^�C\n" NOR,me);
        command("wink" + me->query("id"));
	
 }
	 
	else
 {
	ob 
	move->obj
 }
 }


