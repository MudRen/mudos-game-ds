inherit NPC;
void create()
{
        set_name("�����H��", ({ "mystical man ", "man" }) );
        set("long", "�������H�A\n"
                    "�q�@�ӯ������@�ɨӪ��C\n");

        
        set("class","fighter");
        set("attitude","friendly");

        set("level",15);
        set("age",  28);
        set("chat_chance",9);
        set("chat_msg",({
  "�������H�C�n���G�o�@�ɡA�ڨӵL�v�A�h�L�a�C\n",
  (: command,"sweat" :),
}));

        set_skill("sword",  20);
        set_skill("dodge",  20);
        set_skill("parry",  25);
        
        setup();
        
}
