inherit NPC;
void create()
{
set_name("�ѰF", ({ "old clam","clam" }) );
set("age",99);
set("level",61);
set("long", @LONG
�@�ӦѰF, �q�e�ߤW���a���ݨ�, ���ӤW�ʷ��F�a..
LONG
);
set("race","���~");
//set("coin",260+random(130));
//set("chat_chance", 8);
//set("chat_msg", ({
//"�D�D\n",
//}));
set("limbs", ({ "�Y��", "����", "�~��", "����"})); //���𳡦�
set("verbs", ({ "bite","crash" })); //�������A��hoof��crash�rbite��claw��poke
setup();
add_temp("apply/armor",400);
carry_object(__DIR__"item/pearl");
}

void init()
{
 add_action("no_cast","c");
}

int no_cast(string arg)
{
 if(arg && random(10) > 5 )
 {
  message_vision("$N��M�Q�X�@��Ȧ⪺����, $nı�o�@�}�Y�w..�u�n���I�k.\n",this_object(),this_player());	
  this_player()->start_busy(2);
  return 1;
 }	
 return 0;
}
