inherit NPC;
void create()
{
set_name("�Q����", ({ "king cancer","cancer" }) );
set("age",30);
set("level",41);
set("long", @LONG
�@���Q�����j������, �Ӫ����}���ۦy�U���˨�.
LONG
);
set("race","���~");
//set_temp("apply/armor",130);
//set("coin",260+random(130));
//set("chat_chance", 8);
//set("chat_msg", ({
//"�D�D\n",
//}));
set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"})); //���𳡦�
set("verbs", ({ "bite","claw","crash" })); //�������A��hoof��crash�rbite��claw��poke
setup();
}

void init()
{
 if(random(20) > 17)
 {
  kill_ob(this_player());
 }
}
