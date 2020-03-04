inherit NPC;
#include <ansi.h>

void create()
{
    set_name(HBK"�ǯT��" NOR, ({ "wolf king", "wolf", "king"}) );
	set("race", "���~");
	set("age", 70);
	set("level", 35);
    set("unique", 2);
    set("long", "�T�H�s�~�A�o�u�a�Y���j�ǯT��䥦���j�@���H�W�A�C�I�a�q�ۡC\n");
    set("attitude", "aggressive");	
	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "�e��" }) );
	set("verbs", ({ "bite", "claw" }) );
    set("chat_chance", 20);
	set("chat_msg", ({
         "�ǯT�������ئb�·t���{�۬����A���a�`���ۧA���@�|�@�ʡC\n",
         "�ǯT���o�X�@�n��s�A�n���H�ɳ��n���W�ӡI\n",
	}) );
	set("skin", __DIR__"obj/langpi");

	setup();
}

void die()
{
        object ob, obj;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        
      	// ����
      obj = new( query("skin") );
      if(objectp(obj))
	      obj->move( this_object() ); 

  	  if( ob->getToDo("/open/quest/hasake_q4.c") ) {
  	  	  // �������կT�������ȡA�~�����|�s�X�կT��
		  // �O�����T��������
			ob->add_temp("hasake_wolf", 1);
	      if( ob->query_temp("hasake_wolf") > 3 + random(3) ) {
			  ob->delete_temp("hasake_wolf");
	      	  message_vision(HIW"�|�g����ũ��M�����F�U��..."NOR, this_object());
	      	  new(__DIR__"white-wolf")->move(environment(this_object()));
	      }
      }
        ::die();
}
