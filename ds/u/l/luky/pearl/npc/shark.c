inherit NPC;
void create()
{
set_name("�T��", ({ "shark" }) );
set("age",12);
set("level",35);
set("long", @LONG
�@�����j���T��, �����h�n�N���n�ۧA��...
LONG
);
set("race","���~");
//set_temp("apply/armor",130);
//set("coin",260+random(130));
set("chat_chance", 8);
set("chat_msg", ({
"�T���b�A����L�۵ۡD�D\n",
 (:command("go south"):),
 (:command("go east"):),
}));
set("limbs", ({ "�Y��", "����", "�I�_", "����","����"})); //���𳡦�
set("verbs", ({ "bite" })); //�������A��hoof��crash�rbite��claw��poke
setup();
}

void init()
{
 if(random(10) > 7)
 {
  kill_ob(this_player());
 }
}
